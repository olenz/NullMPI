/* $Id$ */
/* Point-to-point communication */

#include "nullmpi.h"

int MPI_Buffer_detach (void *buf, int *size)
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}
