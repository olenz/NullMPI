/* $Id$ */
/* Initialization and Miscellaneous */

#include "nullmpi.h"

int MPI_Finalize (void)
{
  NULLMPI_STATS;
  nullmpi_finalize();
  return MPI_SUCCESS;
}
