/* $Id$ */
/* Collective communication */

#include "nullmpi.h"

int MPI_Scatter (void *sendbuf, int sendcount, MPI_Datatype sendtype,
                 void *recvbuf, int recvcount, MPI_Datatype recvtype,
                 int root, MPI_Comm comm)
{
  NULLMPI_STATS;
  nullmpi_assert (nullmpi_sizeof_datatype (sendtype) * sendcount ==
                  nullmpi_sizeof_datatype (recvtype) * recvcount);
  memcpy (recvbuf, sendbuf, nullmpi_sizeof_datatype (sendtype) * sendcount);
  return MPI_SUCCESS;
}
