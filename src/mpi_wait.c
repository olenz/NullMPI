/* $Id$ */
/* Point-to-point communication */

#include "nullmpi.h"
#include "ptp.h"

int MPI_Wait(MPI_Request *request, MPI_Status *status)
{
  int completed;
  NULLMPI_STATS;
  return nullmpi_waithandle(1, request, &completed, status);
}
