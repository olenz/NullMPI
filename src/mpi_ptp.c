/* mpi_ptp.c */

#include "nullmpi.h"

int MPI_Send (void* buf, int count, MPI_Datatype type, int dest,
	      int tag, MPI_Comm comm)
{
  NULLMPI_STATS;
  return -1;
}

int MPI_Recv (void* buf, int count, MPI_Datatype type, int source,
              int tag, MPI_Comm comm, MPI_Status *status)
{
  NULLMPI_STATS;
  return -1;
}

int MPI_Get_count (MPI_Status *status, MPI_Datatype type, int *count)
{
  NULLMPI_STATS;
  *count = 0;
  return -1;
}

extern int MPI_Bsend(void *buf, int count, MPI_Datatype datatype,
    int dest, int tag, MPI_Comm comm)
    /*@requires maxRead(buf) >= (count - 1)@*/ ;

extern int MPI_Ssend(void *buf, int count, MPI_Datatype datatype,
    int dest, int tag, MPI_Comm comm)
    /*@requires maxRead(buf) >= (count-1)@*/ ;

extern int MPI_Rsend(void *buf, int count, MPI_Datatype datatype,
    int dest, int tag, MPI_Comm comm)
    /*@requires maxRead(buf) >= (count-1)@*/ ;

extern int MPI_Buffer_attach(/*@out@*/ void *buf, int size)
    /*@modifies buf@*/
    /*@requires size >= MPI_BSEND_OVERHEAD /\ maxSet(buf) >= size@*/;

extern int MPI_Buffer_detach(/*@out@*/ void *buf, /*@out@*/ int *size);

int MPI_Isend (void* buf, int count, MPI_Datatype type, int dest,
	       int tag, MPI_Comm comm, MPI_Request *request)
{
  NULLMPI_STATS;
  return -1;
}

extern int MPI_Ibsend(void *buf, int count, MPI_Datatype datatype,
    int dest, int tag, MPI_Comm comm, /*@out@*/ MPI_Request *request)
    /*@modifies request@*/
    /*@requires maxRead(buf) >= (count-1)@*/ ;

extern int MPI_Issend(void *buf, int count, MPI_Datatype datatype,
    int dest, int tag, MPI_Comm comm, /*@out@*/ MPI_Request *request)
    /*@modifies request@*/
    /*@requires maxRead(buf) >= (count-1)@*/ ;

extern int MPI_Irsend(void *buf, int count, MPI_Datatype datatype,
    int dest, int tag, MPI_Comm comm, /*@out@*/ MPI_Request *request)
    /*@modifies request@*/
    /*@requires maxRead(buf) >= (count-1)@*/  ;

int MPI_Irecv (void* buf, int count, MPI_Datatype type, int source,
               int tag, MPI_Comm comm, MPI_Request *request)
{
  NULLMPI_STATS;
  return -1;
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

extern int MPI_Request_free(MPI_Request *request)
    /*@modifies request@*/ ;

int MPI_Waitany(int count, MPI_Request array_of_requests[],
                int *index, MPI_Status *status)
{
  NULLMPI_STATS;
  nullmpi_assert (0 && "not implemented");
}

extern int MPI_Testany(int count, MPI_Request array_of_requests[],
    /*@out@*/ int *index, /*@out@*/ int *flag, /*@out@*/ MPI_Status *status)
    /*@modifies index, flag, status@*/
    /*@requires maxRead(array_of_requests) >= (count-1)@*/ ;

extern int MPI_Waitall(int count, MPI_Request array_of_requests[],
    /*@out@*/ MPI_Status array_of_statuses[])
    /*@modifies array_of_statuses@*/
    /*@requires maxRead(array_of_requests) >= (count-1)@*/
    /*@ensures maxRead(array_of_statuses) == (count-1)@*/ ;

extern int MPI_Testall(int count, MPI_Request array_of_requests[],
    /*@out@*/ int *flag, /*@out@*/ MPI_Status array_of_statuses[])
    /*@modifies flag, array_of_statuses@*/
    /*@requires maxRead(array_of_requests) >= (count-1)@*/
    /*@ensures maxRead(array_of_statuses) == (count-1)@*/ ;

extern int MPI_Waitsome(int incount, MPI_Request array_of_requests[],
    /*@out@*/ int *outcount,
    /*@out@*/ int array_of_indices[], /*@out@*/ MPI_Status array_of_statuses[])
    /*@modifies outcount, array_of_indices, array_of_statuses@*/
    /*@requires maxRead(array_of_requests) >= (incount-1)
             /\ maxSet(array_of_indices) >= (incount-1)
	     /\ maxSet(array_of_statuses) >= (incount-1)@*/
    /*@ensures maxRead(array_of_indices) == *outcount
            /\ maxRead(array_of_statuses) == *outcount@*/ ;

extern int MPI_Testsome(int incount, MPI_Request array_of_requests[],
    /*@out@*/ int *outcount,
    /*@out@*/ int array_of_indices[], /*@out@*/ MPI_Status array_of_statuses[])
    /*@requires maxRead(array_of_requests) >= (incount-1)
             /\ maxSet(array_of_indices) >= (incount-1)
	     /\ maxSet(array_of_statuses) >= (incount-1)@*/
    /*@ensures maxRead(array_of_indices) == *outcount
            /\ maxRead(array_of_statuses) == *outcount@*/ ;

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
  return -1;
}

int MPI_Cancel(MPI_Request *request)
{
  NULLMPI_STATS;
  return -1;
}

int MPI_Test_cancelled(MPI_Status *status, int *flag)
{
  NULLMPI_STATS;
  *flag = FALSE;
  return MPI_SUCCESS;
}

extern int MPI_Send_init(void *buf, int count, MPI_Datatype datatype,
    int dest, int tag, MPI_Comm comm, /*@out@*/ MPI_Request *request)
    /*@modifies request@*/
    /*@requires maxSet(buf) >= (count-1)@*/ ;  /* not maxRead! can write to buf later! */

extern int MPI_Bsend_init(void *buf, int count, MPI_Datatype datatype,
    int dest, int tag, MPI_Comm comm, /*@out@*/ MPI_Request *request)
    /*@modifies request@*/
    /*@requires maxSet(buf) >= (count-1)@*/ ;

extern int MPI_Ssend_init(void *buf, int count, MPI_Datatype datatype,
    int dest, int tag, MPI_Comm comm, /*@out@*/ MPI_Request *request)
    /*@modifies request@*/
    /*@requires maxSet(buf) >= (count-1)@*/ ;

extern int MPI_Rsend_init(void *buf, int count, MPI_Datatype datatype,
    int dest, int tag, MPI_Comm comm, /*@out@*/ MPI_Request *request)
    /*@modifies request@*/
    /*@requires maxSet(buf) >= (count-1)@*/ ;

extern int MPI_Recv_init(/*@out@*/ void *buf, int count, MPI_Datatype datatype,
    int source, int tag, MPI_Comm comm, /*@out@*/ MPI_Request *request)
    /*@modifies request, buf@*/
    /*@requires maxSet(buf) >= (count-1)@*/ ;

extern int MPI_Start(MPI_Request *request);

extern int MPI_Startall(int count, MPI_Request array_of_requests[])
    /*@requires maxRead(array_of_requests) >= (count-1)@*/ ;

/* MPI_Sendrecv and MPI_Sendrecv_replace are to be found in mpi_coll.c */
