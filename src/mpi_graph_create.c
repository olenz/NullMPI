/* $Id$ */
/* Graph handling */

#include "nullmpi.h"

int MPI_Graph_create(MPI_Comm comm_old, int nnodes,
    int indx[], int edges[], int reorder, /*@out@*/ MPI_Comm *comm_graph)
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}
