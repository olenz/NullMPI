/* $Id$ */
/* User-defined datatypes */

#include "nullmpi.h"

int MPI_Type_vector(int count, int blocklen, int stride,
    MPI_Datatype oldtype, /*@out@*/ MPI_Datatype *newtype)
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}
