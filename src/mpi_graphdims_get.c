/* $Id$ */
/* Graph handling */

#include "nullmpi.h"

int MPI_Graphdims_get(MPI_Comm comm,
    /*@out@*/ int *nnodes, /*@out@*/ int *nedges)
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}
