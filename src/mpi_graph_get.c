/* $Id$ */
/* Graph handling */

#include "nullmpi.h"

int MPI_Graph_get(MPI_Comm comm, int maxindx, int maxedges,
    /*@out@*/ int indx[], /*@out@*/ int edges[])
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}
