/* $Id$ */
/* User-defined datatypes */

#include "nullmpi.h"

int MPI_Type_contiguous(int count, MPI_Datatype oldtype,
    MPI_Datatype *newtype)
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}
