/* $Id$ */
/* Topology handling */

#include "nullmpi.h"

int MPI_Cart_rank(MPI_Comm comm, int coords[], int *rank)
{
  NULLMPI_STATS;
  *rank = 0;
  return MPI_SUCCESS;
}
