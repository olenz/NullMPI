/* $Id$ */
/* Group handling */

#include "nullmpi.h"

int MPI_Group_difference(MPI_Group group1, MPI_Group group2,
    /*@out@*/ MPI_Group *newgroup)
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}
