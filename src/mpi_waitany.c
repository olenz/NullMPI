/* $Id$ */
/* Point-to-point communication */

#include "nullmpi.h"

int MPI_Waitany(int count, MPI_Request array_of_requests[],
                int *indx, MPI_Status *status)
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}
