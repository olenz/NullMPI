/* $Id$ */
/* Topology handling */

#include "nullmpi.h"

int MPI_Cart_map(MPI_Comm comm_old, int ndims, int dims[], int periods[],
    /*@out@*/ int *newrank)
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}
