/* $Id$ */
/* User-defined datatypes */

#include "nullmpi.h"

int MPI_Type_size(MPI_Datatype datatype, int *size)
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}
