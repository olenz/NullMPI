/* $Id$ */
/* Initialization and Miscellaneous */

#include "nullmpi.h"

int MPI_Barrier (MPI_Comm comm)
{
  NULLMPI_STATS;
  return MPI_SUCCESS;
}
