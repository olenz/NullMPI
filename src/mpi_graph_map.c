/* $Id$ */
/* Graph handling */

#include "nullmpi.h"

int MPI_Graph_map(MPI_Comm comm_old, int nnodes,
    int indx[], int edges[], /*@out@*/ int *newrank)
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}
