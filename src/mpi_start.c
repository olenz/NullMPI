/* $Id$ */
/* Point-to-point communication */

#include "nullmpi.h"

int MPI_Start(MPI_Request *request)
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}
