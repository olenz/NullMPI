/* $Id$ */
/* Group handling */

#include "nullmpi.h"

int MPI_Group_translate_ranks(MPI_Group group_a, int n, int *ranks_a,
    MPI_Group group_b, /*@out@*/ int *ranks_b)
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}
