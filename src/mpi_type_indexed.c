/* $Id$ */
/* User-defined datatypes */

#include "nullmpi.h"

int MPI_Type_indexed(int count, int blocklens[], int indices[],
    MPI_Datatype oldtype, /*@out@*/ MPI_Datatype *newtype)
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}
