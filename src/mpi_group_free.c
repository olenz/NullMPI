/* $Id$ */
/* Group handling */

#include "nullmpi.h"

int MPI_Group_free(MPI_Group *group)
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}
