/* $Id$ */
/* Communicator handling */

#include "nullmpi.h"

int MPI_Comm_split(MPI_Comm comm, int color, int key, MPI_Comm *comm_out)
{
  NULLMPI_STATS;
  if (color == MPI_UNDEFINED)
    *comm_out = MPI_COMM_NULL;
  else
    *comm_out = comm;
  return MPI_SUCCESS;
}
