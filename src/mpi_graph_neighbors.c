/* $Id$ */
/* Graph handling */

#include "nullmpi.h"

int MPI_Graph_neighbors(MPI_Comm comm, int rank,
    int maxneighbors, /*@out@*/ int neighbors[])
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}
