/* $Id$ */
/* Collective communication */

#include "nullmpi.h"

int MPI_Sendrecv(void *sendbuf, int sendcount, MPI_Datatype sendtype,
                 int dest, int sendtag,
                 void *recvbuf, int recvcount, MPI_Datatype recvtype,
                 int source, int recvtag,
                 MPI_Comm comm, MPI_Status *status)
{
  NULLMPI_STATS;
  nullmpi_assert (dest == 0 && source == 0);
  nullmpi_assert (sendtag == recvtag);
  nullmpi_assert (nullmpi_sizeof_datatype (sendtype) * sendcount ==
                  nullmpi_sizeof_datatype (recvtype) * recvcount);
  memcpy (recvbuf, sendbuf, nullmpi_sizeof_datatype (sendtype) * sendcount);
  return MPI_SUCCESS;
}
