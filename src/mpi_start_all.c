/* $Id$ */
/* Point-to-point communication */

#include "nullmpi.h"

int MPI_Startall(int count, MPI_Request array_of_requests[])
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}
