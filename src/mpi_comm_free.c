/* $Id$ */
/* Communicator handling */

#include "nullmpi.h"

int MPI_Comm_free(MPI_Comm *comm)
{
  NULLMPI_STATS;
  return MPI_SUCCESS;
}
