#include <mpi.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <float.h>

/*@access MPI_Datatype@*/

#define BUF 2657

#define comm(type,TYPE) static int comm_##TYPE(void) \
	{ \
	  size_t i; \
	  type send[BUF], recv[BUF]; \
	  MPI_Status status; \
	  for (i=0; i<BUF; ++i) send[i]=(type)i; \
	  return !(MPI_Sendrecv(send, BUF, MPI_##TYPE, 0, 123 + (int)MPI_##TYPE, \
		                recv, BUF, MPI_##TYPE, 0, 123 + (int)MPI_##TYPE, \
				MPI_COMM_WORLD, &status) == MPI_SUCCESS && \
	      recv[BUF-1] - (type)(BUF-1) <= (type)DBL_EPSILON); \
	}
#define for_types(macro) \
	macro(char,CHAR) \
	macro(short,SHORT) \
	macro(int,INT) \
	macro(unsigned,UNSIGNED) \
	macro(long,LONG) \
	macro(unsigned long,UNSIGNED_LONG) \
	macro(float,FLOAT) \
	macro(double,DOUBLE) \
	macro(long double,LONG_DOUBLE)
#define try_comm(type,TYPE) \
  if (comm_##TYPE ()) \
    abort();

for_types(comm)


/* isend test */
int test_nonblock(void)
{
  size_t i;
  int count;
  char send[BUF], recv[BUF];
  MPI_Request sreq, rreq;
  MPI_Status sstat, rstat;

  for (i=0; i<BUF; ++i) send[i] = 2*i + 1;

  recv[0] = 0;
  if (MPI_Isend(send, BUF, MPI_CHAR, 0, 666, MPI_COMM_WORLD, &sreq) != MPI_SUCCESS)
    abort();
  if (MPI_Irecv(recv, BUF, MPI_CHAR, 0, 666, MPI_COMM_WORLD, &rreq) != MPI_SUCCESS)
    abort();
  if (MPI_Wait(&sreq, &sstat) != MPI_SUCCESS)
    abort();
  if (MPI_Wait(&rreq, &rstat) != MPI_SUCCESS)
    abort();
  if (recv[0] != 1)
    abort();

  recv[0] = 0;
  if (MPI_Isend(send, BUF, MPI_CHAR, 0, 666, MPI_COMM_WORLD, &sreq) != MPI_SUCCESS)
    abort();
  if (MPI_Irecv(recv, BUF, MPI_CHAR, 0, 666, MPI_COMM_WORLD, &rreq) != MPI_SUCCESS)
    abort();
#if 0		/* THIS IS UNPORTABLE! */  /* AND WRONG IN OUR IMPLEMENTATION */
  if (recv[0] == 1)
    abort();
#endif
  if (MPI_Wait(&sreq, &sstat) != MPI_SUCCESS)
    abort();
  if (MPI_Wait(&rreq, &rstat) != MPI_SUCCESS)
    abort();
  if (recv[0] != 1)
    abort();

  recv[0] = 0;
  if (MPI_Irecv(recv, BUF, MPI_CHAR, 0, 667, MPI_COMM_WORLD, &rreq) != MPI_SUCCESS)
    abort();
  if (MPI_Send(send, BUF, MPI_CHAR, 0, 667, MPI_COMM_WORLD) != MPI_SUCCESS)
    abort();
  if (recv[0] != 1)
    abort();
  if (MPI_Wait(&rreq, &rstat) != MPI_SUCCESS)
    abort();
  if (MPI_Get_count(&rstat, MPI_CHAR, &count) != MPI_SUCCESS)
    abort();
  if (count != BUF)
    abort();

  recv[0] = 0;
  if (MPI_Isend(send, BUF, MPI_CHAR, 0, 669, MPI_COMM_WORLD, &sreq) != MPI_SUCCESS)
    abort();
  if (MPI_Recv(recv, BUF, MPI_CHAR, 0, 669, MPI_COMM_WORLD, &rstat) != MPI_SUCCESS)
    abort();
  if (MPI_Wait(&sreq, &sstat) != MPI_SUCCESS)
    abort();
  if (recv[0] != 1)
    abort();
  if (MPI_Get_count(&sstat, MPI_CHAR, &count) != MPI_SUCCESS)
    abort();
  if (count != BUF)
    abort();

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

  for_types(try_comm);

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
