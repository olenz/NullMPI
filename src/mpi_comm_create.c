/* $Id$ */
/* Communicator handling */

#include "nullmpi.h"

int MPI_Comm_create(MPI_Comm comm, MPI_Group group, MPI_Comm *comm_out)
{
  NULLMPI_STATS;
  *comm_out = comm;
  return MPI_SUCCESS;
}
