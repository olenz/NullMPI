/* $Id$ */
/* Topology handling */

#include "nullmpi.h"

int MPI_Cart_get(MPI_Comm comm, int maxdims,
    /*@out@*/ int dims[], /*@out@*/ int periods[], /*@out@*/ int coords[])
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}
