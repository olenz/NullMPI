/* $Id$ */
/* Point-to-point communication */

#include "nullmpi.h"

int MPI_Test_cancelled(MPI_Status *status, int *flag)
{
  NULLMPI_STATS;
  *flag = FALSE;
  return MPI_SUCCESS;
}
