/* $Id$ */
/* Initialization and Miscellaneous */

#include "nullmpi.h"

/* Init */
int MPI_Init (int *argc, char ***argv)
{
  nullmpi_initialize();
  NULLMPI_STATS;
  return MPI_SUCCESS;
}
