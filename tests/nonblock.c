#include <mpi.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <float.h>

/*@access MPI_Datatype@*/

#define BUF 1982
#define N 4

int test_nonblock(void)
{
  size_t i, j;
  char *s[N];
  char *r[N];
  MPI_Request sreq[N], rreq[N];
  MPI_Status sstat, rstat;

  for (i=0; i<N; ++i) {
    s[i] = (char*) malloc(BUF * sizeof s[i][0]);
    r[i] = (char*) malloc(BUF * sizeof r[i][0]);
    if (!s[i] || !r[i])
      abort();
    for (j=0; j<BUF; ++j) {
      s[i][j] = (char) (N * i + j +1);
      r[i][j] = 0;
    }
  }

  for (i=0; i<N; ++i) {
    if (MPI_Irecv(r[i], BUF, MPI_CHAR, 0, 666, MPI_COMM_WORLD, &rreq[i]) != MPI_SUCCESS)
      abort();
  }
  for (i=0; i<N; ++i) {
    if (MPI_Isend(s[i], BUF, MPI_CHAR, 0, 666, MPI_COMM_WORLD, &sreq[i]) != MPI_SUCCESS)
      abort();
  }

  for (i=N-1; ; --i) {
    if (MPI_Wait(&sreq[i], &sstat) != MPI_SUCCESS)
      abort();
    if (MPI_Wait(&rreq[i], &rstat) != MPI_SUCCESS)
      abort();
#if 0
    if (r[i][0] != (char) (N * i + 1))
      abort();
#endif
    if (i == 0)
      break;
  }

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
