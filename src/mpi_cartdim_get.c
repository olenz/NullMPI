/* $Id$ */
/* Topology handling */

#include "nullmpi.h"

int MPI_Cartdim_get(MPI_Comm comm, int *ndims)
{
  NULLMPI_STATS;
  *ndims = 1; /*FIXME*/
  return -1;
}
