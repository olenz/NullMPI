/* $Id$ */
/* Collective communication */

#include "nullmpi.h"

int MPI_Sendrecv_replace(void *buf, int count, MPI_Datatype datatype,
                         int dest, int sendtag, int source, int recvtag,
                         MPI_Comm comm, MPI_Status *status)
{
  NULLMPI_STATS;
  nullmpi_assert (dest == 0 && source == 0);
  nullmpi_assert (sendtag == recvtag);
  return MPI_SUCCESS;
}
