/* $Id$ */
/* Initialization and Miscellaneous */

#include "nullmpi.h"

int MPI_Initialized(int *flag)
{
  *flag = nullmpi_initialized();
  return MPI_SUCCESS;
}
