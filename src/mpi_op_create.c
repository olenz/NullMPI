/* $Id$ */
/* Collective communication */

#include "nullmpi.h"

int MPI_Op_create(MPI_User_function *function, int commute, MPI_Op *op)
{
  NULLMPI_STATS;
  return MPI_SUCCESS;
}
