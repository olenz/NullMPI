/* $Id$ */
/* Topology handling */

#include "nullmpi.h"

int MPI_Cart_coords(MPI_Comm comm, int rank, int maxdims, int coords[])
{
  int i;
  NULLMPI_STATS;
  /* FIXME: we rely on maxdims being correct here, instead of using comm.cart.dim */
  for (i=0; i<maxdims; ++i)
    coords[i] = 0;
  return MPI_SUCCESS;
}
