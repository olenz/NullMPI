/* $Id$ */

#include "nullmpi.h"

/* Init */
int MPI_Pcontrol (int level, ...)
{
  NULLMPI_STATS;
  nullmpi_set_debuglevel(level);
  return MPI_SUCCESS;
}
