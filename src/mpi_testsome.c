/* $Id$ */
/* Point-to-point communication */

#include "nullmpi.h"

int MPI_Testsome(int incount, MPI_Request array_of_requests[],
    int *outcount,
    int array_of_indices[], MPI_Status array_of_statuses[])
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}
