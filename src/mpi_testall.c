/* $Id$ */
/* Point-to-point communication */

#include "nullmpi.h"

int MPI_Testall(int count, MPI_Request array_of_requests[],
    int *flag, MPI_Status array_of_statuses[])
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}
