/* $Id$ */
/* User-defined datatypes */

#include "nullmpi.h"

int MPI_Type_free(MPI_Datatype *datatype)
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}
