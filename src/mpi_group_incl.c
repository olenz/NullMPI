/* $Id$ */
/* Group handling */

#include "nullmpi.h"

int MPI_Group_incl(MPI_Group group, int n, int *ranks,
    /*@out@*/ MPI_Group *newgroup)
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}
