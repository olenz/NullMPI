/* $Id$ */
/* Group handling */

#include "nullmpi.h"

int MPI_Group_size(MPI_Group group, /*@out@*/ int *size)
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}
