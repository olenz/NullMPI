/* $Id$ */
/* Collective communication */

#include "nullmpi.h"

int MPI_Alltoallv(void *sendbuf, int *sendcounts, int *sdispls,
    MPI_Datatype sendtype,
    void *recvbuf, int *recvcounts, int *rdispls,
    MPI_Datatype recvtype, MPI_Comm comm)
{
  NULLMPI_STATS;
  nullmpi_assert (nullmpi_sizeof_datatype (sendtype) * sendcounts[0] ==
                  nullmpi_sizeof_datatype (recvtype) * recvcounts[0]);
  memcpy ((char *)recvbuf + rdispls[0] * nullmpi_sizeof_datatype (sendtype),
          (char *)sendbuf + sdispls[0] * nullmpi_sizeof_datatype (sendtype),
	  nullmpi_sizeof_datatype (sendtype) * sendcounts[0]);
  return MPI_SUCCESS;
}
