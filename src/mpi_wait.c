/* $Id$ */
/* Point-to-point communication */

#include "nullmpi.h"

int MPI_Wait(MPI_Request *request, MPI_Status *status)
{
  NULLMPI_STATS;
  return MPI_SUCCESS;
}
