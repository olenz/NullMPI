/* $Id$ */
/* Topology handling */

#include "nullmpi.h"

int MPI_Cart_shift(MPI_Comm comm, int direction, int displ,
    /*@out@*/ int *source, /*@out@*/ int *dest)
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}
