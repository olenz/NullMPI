/* $Id$ */
/* Group handling */

#include "nullmpi.h"

int MPI_Group_range_excl(MPI_Group group, int n, int ranges[][3],
    /*@out@*/ MPI_Group *newgroup)
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}
