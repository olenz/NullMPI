/* $Id$ */
/* Collective communication */

#include "nullmpi.h"

int MPI_Bcast (void* buf, int count, MPI_Datatype type, int root, MPI_Comm comm)
{
  NULLMPI_STATS;
  return MPI_SUCCESS;
}
