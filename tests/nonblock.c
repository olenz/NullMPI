#include <mpi.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <float.h>

/*@access MPI_Datatype@*/

#define BUF 1982
#define N 4


void setup(char **r, char **s, MPI_Request *rreq, MPI_Request *sreq,
    MPI_Status *rstats)
{
  size_t i, j;
  for (i=0; i<N; ++i) {
    s[i] = (char*) malloc(BUF * sizeof s[i][0]);
    r[i] = (char*) malloc(BUF * sizeof r[i][0]);
    if (!s[i] || !r[i])
      abort();
    for (j=0; j<BUF; ++j) {
      s[i][j] = (char) (N * i + j +1);
      r[i][j] = 0;
    }
    rreq[i] = NULL;
    sreq[i] = NULL;
    rstats[i].MPI_TAG = 0;
    rstats[i].MPI_ERROR = 0;
    rstats[i].size = 0;
  }
}

int test_nonblock(void)
{
  size_t i;
  char *s[N];
  char *r[N];
  MPI_Request sreq[N], rreq[N];
  MPI_Status sstat;
  MPI_Status rstats[N];
  int count;

  setup(r, s, rreq, sreq, rstats);

  for (i=0; i<N; ++i) {
    if (MPI_Irecv(r[i], BUF, MPI_CHAR, 0, 666, MPI_COMM_WORLD, &rreq[i]) != MPI_SUCCESS)
      abort();
  }
  for (i=0; i<N; ++i) {
    if (MPI_Isend(s[i], BUF/2, MPI_CHAR, 0, 666, MPI_COMM_WORLD, &sreq[i]) != MPI_SUCCESS)
      abort();
  }

  for (i=N-1; ; --i) {
    if (MPI_Wait(&sreq[i], &sstat) != MPI_SUCCESS)
      abort();
#if 1
    if (r[i][0] != (char) (N * i + 1))
      abort();
#endif
    if (r[i][BUF/2] != 0)
      abort();
    if (MPI_Get_count(&sstat, MPI_CHAR, &count) != MPI_SUCCESS)
      abort();
    if (count != BUF/2)
      abort();
    if (i == 0)
      break;
  }
  if (MPI_Wait(rreq+0, rstats+0) != MPI_SUCCESS)
    abort();
  if (MPI_Get_count(rstats+0, MPI_CHAR, &count) != MPI_SUCCESS)
    abort();
  if (count != BUF)
    abort();
  if (MPI_Waitall(N-1, rreq+1, rstats+1) != MPI_SUCCESS)
    abort();

  for (i=0; i<N; ++i) {
    free(s[i]);
    free(r[i]);
  }
  return 0;
}


int main(int argc, char **argv)
{
  int info;
  char processor_name[MPI_MAX_PROCESSOR_NAME];
  if (getenv("VERBOSE") && MPI_Pcontrol(1))
      abort();
  MPI_Init(&argc, &argv);
  if (MPI_Get_processor_name(processor_name, &info) ||
      info != (int)strlen(processor_name))
    abort();
  printf("running on %s\n", processor_name);

  if (MPI_Comm_rank(MPI_COMM_WORLD, &info))
    abort();
  if (MPI_Comm_size(MPI_COMM_WORLD, &info))
    abort();

  if (test_nonblock())
    abort();

  if (MPI_Finalize())
    abort();
  return 0;
}
