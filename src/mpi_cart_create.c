/* $Id$ */
/* Topology handling */

#include "nullmpi.h"

int MPI_Cart_create(MPI_Comm comm_old, int ndims,
    int *dims, int *periods, int reorder, MPI_Comm *comm_cart)
{
  NULLMPI_STATS;
  *comm_cart = comm_old;
  return MPI_SUCCESS;
}
