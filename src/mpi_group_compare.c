/* $Id$ */
/* Group handling */

#include "nullmpi.h"

int MPI_Group_compare(MPI_Group group1, MPI_Group group2,
    /*@out@*/ int *res)
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}
