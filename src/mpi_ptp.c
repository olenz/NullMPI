/* $Id$ */
/* Point-to-point communication */

#include "nullmpi.h"

int MPI_Send (void* buf, int count, MPI_Datatype type, int dest,
	      int tag, MPI_Comm comm)
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}

int MPI_Recv (void* buf, int count, MPI_Datatype type, int source,
              int tag, MPI_Comm comm, MPI_Status *status)
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}

int MPI_Get_count (MPI_Status *status, MPI_Datatype type, int *count)
{
  NULLMPI_STATS;
  *count = 0;
  return nullmpi_unsupported();
}

int MPI_Bsend (void *buf, int count, MPI_Datatype datatype,
    int dest, int tag, MPI_Comm comm)
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}

int MPI_Ssend (void *buf, int count, MPI_Datatype datatype,
    int dest, int tag, MPI_Comm comm)
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}

int MPI_Rsend (void *buf, int count, MPI_Datatype datatype,
    int dest, int tag, MPI_Comm comm)
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}

int MPI_Buffer_attach (void *buf, int size)
{
  NULLMPI_STATS;
  nullmpi_assert(size >= MPI_BSEND_OVERHEAD);
  return nullmpi_unsupported();
}

int MPI_Buffer_detach (void *buf, int *size)
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}

int MPI_Isend (void* buf, int count, MPI_Datatype type, int dest,
	       int tag, MPI_Comm comm, MPI_Request *request)
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}

int MPI_Ibsend(void *buf, int count, MPI_Datatype datatype,
    int dest, int tag, MPI_Comm comm, MPI_Request *request)
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}

int MPI_Issend(void *buf, int count, MPI_Datatype datatype,
    int dest, int tag, MPI_Comm comm, MPI_Request *request)
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}

int MPI_Irsend(void *buf, int count, MPI_Datatype datatype,
    int dest, int tag, MPI_Comm comm, MPI_Request *request)
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}

int MPI_Irecv (void* buf, int count, MPI_Datatype type, int source,
               int tag, MPI_Comm comm, MPI_Request *request)
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}

int MPI_Wait(MPI_Request *request, MPI_Status *status)
{
  NULLMPI_STATS;
  return MPI_SUCCESS;
}

int MPI_Test(MPI_Request *request, int *flag, MPI_Status *status)
{
  NULLMPI_STATS;
  *flag = FALSE;
  return MPI_SUCCESS;
}

int MPI_Request_free(MPI_Request *request)
{
  NULLMPI_STATS;
  return MPI_SUCCESS;
}

int MPI_Waitany(int count, MPI_Request array_of_requests[],
                int *index, MPI_Status *status)
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}

int MPI_Testany(int count, MPI_Request array_of_requests[],
    int *index, int *flag, MPI_Status *status)
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}

int MPI_Waitall(int count, MPI_Request array_of_requests[],
    MPI_Status array_of_statuses[])
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}

int MPI_Testall(int count, MPI_Request array_of_requests[],
    int *flag, MPI_Status array_of_statuses[])
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}

int MPI_Waitsome(int incount, MPI_Request array_of_requests[],
    int *outcount,
    int array_of_indices[], MPI_Status array_of_statuses[])
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}

int MPI_Testsome(int incount, MPI_Request array_of_requests[],
    int *outcount,
    int array_of_indices[], MPI_Status array_of_statuses[])
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}

int MPI_Iprobe(int source, int tag, MPI_Comm comm,
               int *flag, MPI_Status *status)
{
  NULLMPI_STATS;
  *flag = FALSE;
  return MPI_SUCCESS;
}

int MPI_Probe (int count1, int count2, MPI_Comm comm, MPI_Status *status)
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}

int MPI_Cancel(MPI_Request *request)
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}

int MPI_Test_cancelled(MPI_Status *status, int *flag)
{
  NULLMPI_STATS;
  *flag = FALSE;
  return MPI_SUCCESS;
}

int MPI_Send_init(void *buf, int count, MPI_Datatype datatype,
    int dest, int tag, MPI_Comm comm, MPI_Request *request)
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}

int MPI_Bsend_init(void *buf, int count, MPI_Datatype datatype,
    int dest, int tag, MPI_Comm comm, MPI_Request *request)
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}

int MPI_Ssend_init(void *buf, int count, MPI_Datatype datatype,
    int dest, int tag, MPI_Comm comm, MPI_Request *request)
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}

int MPI_Rsend_init(void *buf, int count, MPI_Datatype datatype,
    int dest, int tag, MPI_Comm comm, MPI_Request *request)
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}

int MPI_Recv_init(void *buf, int count, MPI_Datatype datatype,
    int source, int tag, MPI_Comm comm, MPI_Request *request)
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}

int MPI_Start(MPI_Request *request)
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}

int MPI_Startall(int count, MPI_Request array_of_requests[])
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}

/* MPI_Sendrecv and MPI_Sendrecv_replace are to be found in mpi_coll.c */
