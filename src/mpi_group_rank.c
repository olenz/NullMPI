/* $Id$ */
/* Group handling */

#include "nullmpi.h"

int MPI_Group_rank(MPI_Group group, /*@out@*/ int *rank)
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}
