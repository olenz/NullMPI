/* $Id$ */
/* Point-to-point communication */

#include "nullmpi.h"
#include "ptp.h"

int MPI_Waitall(int count, MPI_Request array_of_requests[],
    MPI_Status array_of_statuses[])
{
  int completed;
  NULLMPI_STATS;
  return nullmpi_waithandle(count, array_of_requests, &completed, array_of_statuses);
}
