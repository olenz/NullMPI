/* $Id$ */
/* Point-to-point communication */

#include "nullmpi.h"

int MPI_Waitall(int count, MPI_Request array_of_requests[],
    MPI_Status array_of_statuses[])
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}
