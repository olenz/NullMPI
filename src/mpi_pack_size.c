/* $Id$ */
/* User-defined datatypes */

#include "nullmpi.h"

int MPI_Pack_size(int incount, MPI_Datatype datatype, MPI_Comm comm,
    /*@out@*/ int *size)
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}
