/* $Id$ */
/* User-defined datatypes */

#include "nullmpi.h"

int MPI_Type_commit(MPI_Datatype *datatype)
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}
