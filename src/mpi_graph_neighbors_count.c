/* $Id$ */
/* Graph handling */

#include "nullmpi.h"

int MPI_Graph_neighbors_count(MPI_Comm comm, int rank,
    /*@out@*/ int *nneighbors)
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}
