/* $Id$ */
/* Point-to-point communication */

#include "nullmpi.h"

int MPI_Request_free(MPI_Request *request)
{
  NULLMPI_STATS;
  return MPI_SUCCESS;
}
