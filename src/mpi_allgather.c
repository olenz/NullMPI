/* $Id$ */
/* Collective communication */

#include "nullmpi.h"

int MPI_Allgather (void* sendbuf, int sendcount, MPI_Datatype sendtype,
                   void* recvbuf, int recvcount, MPI_Datatype recvtype,
		   MPI_Comm comm)
{
  NULLMPI_STATS;
  memcpy (recvbuf, sendbuf, nullmpi_sizeof_datatype (sendtype) * sendcount);
  return MPI_SUCCESS;
}
