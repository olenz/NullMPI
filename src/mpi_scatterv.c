/* $Id$ */
/* Collective communication */

#include "nullmpi.h"

int MPI_Scatterv (void *sendbuf, int *sendcounts, int *displs, MPI_Datatype sendtype,
                  void *recvbuf, int recvcount, MPI_Datatype recvtype,
                  int root, MPI_Comm comm)
{
  NULLMPI_STATS;
  nullmpi_assert (nullmpi_sizeof_datatype (sendtype) * sendcounts[0] ==
                  nullmpi_sizeof_datatype (recvtype) * recvcount);
  memcpy (recvbuf, (char *)sendbuf + displs[0] * nullmpi_sizeof_datatype (recvtype),
          nullmpi_sizeof_datatype (sendtype) * sendcounts[0]);
  return MPI_SUCCESS;
}
