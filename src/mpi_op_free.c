/* $Id$ */
/* Collective communication */

#include "nullmpi.h"

int MPI_Op_free(MPI_Op *op)
{
  NULLMPI_STATS;
  return MPI_SUCCESS;
}
