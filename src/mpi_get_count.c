/* $Id$ */
/* Point-to-point communication */

#include "nullmpi.h"

int MPI_Get_count (MPI_Status *status, MPI_Datatype type, int *count)
{
  NULLMPI_STATS;
  *count = 0;
  return nullmpi_unsupported();
}
