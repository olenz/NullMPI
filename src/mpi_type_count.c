/* $Id$ */
/* User-defined datatypes */

#include "nullmpi.h"

int MPI_Type_count(MPI_Datatype datatype, /*@out@*/ int *count)
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}
