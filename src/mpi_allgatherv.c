/* $Id$ */
/* Collective communication */

#include "nullmpi.h"

int MPI_Allgatherv(void *sendbuf, int sendcount, MPI_Datatype sendtype,
                   void *recvbuf, int *recvcounts, int *displs,
                   MPI_Datatype recvtype, MPI_Comm comm)
{
  NULLMPI_STATS;
  nullmpi_assert (nullmpi_sizeof_datatype (sendtype) * sendcount ==
                  nullmpi_sizeof_datatype (recvtype) * recvcounts[0]);
  memcpy ((char *)recvbuf + displs[0] * nullmpi_sizeof_datatype (recvtype),
          sendbuf, nullmpi_sizeof_datatype (sendtype) * sendcount);
  return MPI_SUCCESS;
}
