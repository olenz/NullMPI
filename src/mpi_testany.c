/* $Id$ */
/* Point-to-point communication */

#include "nullmpi.h"

int MPI_Testany(int count, MPI_Request array_of_requests[],
    /*@out@*/ int *indx, /*@out@*/ int *flag, /*@out@*/ MPI_Status *status)
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}
