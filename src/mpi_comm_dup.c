/* $Id$ */
/* Communicator handling */

#include "nullmpi.h"

int MPI_Comm_dup(MPI_Comm comm, MPI_Comm *newcomm)
{
  NULLMPI_STATS;
  *newcomm = comm;
  return MPI_SUCCESS;
}
