/* $Id$ */
/* Point-to-point communication */

#include "nullmpi.h"

int MPI_Test(MPI_Request *request, int *flag, MPI_Status *status)
{
  NULLMPI_STATS;
  *flag = FALSE;
  return MPI_SUCCESS;
}
