/* $Id$ */
/* Collective communication */

#include "nullmpi.h"

int MPI_Reduce_scatter(void *sendbuf, void *recvbuf, int *recvcnts,
                       MPI_Datatype type, MPI_Op op, MPI_Comm comm)
{
  NULLMPI_STATS;
  memcpy (recvbuf, sendbuf, nullmpi_sizeof_datatype (type) * recvcnts[0]);
  return MPI_SUCCESS;
}
