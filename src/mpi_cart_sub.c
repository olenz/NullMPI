/* $Id$ */
/* Topology handling */

#include "nullmpi.h"

int MPI_Cart_sub(MPI_Comm comm, int *remain_dims,
    /*@out@*/ MPI_Comm *comm_new)
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}
