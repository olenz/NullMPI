/* $Id$ */
/* Collective communication */

#include "nullmpi.h"

int MPI_Reduce (void* sendbuf, void* recvbuf, int count,
	        MPI_Datatype type, MPI_Op op, int root, MPI_Comm comm)
{
  NULLMPI_STATS;
  memcpy (recvbuf, sendbuf, nullmpi_sizeof_datatype (type) * count);
  return MPI_SUCCESS;
}
