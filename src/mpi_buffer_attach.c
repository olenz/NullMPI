/* $Id$ */
/* Point-to-point communication */

#include "nullmpi.h"

int MPI_Buffer_attach (void *buf, int size)
{
  NULLMPI_STATS;
  nullmpi_assert(size >= MPI_BSEND_OVERHEAD);
  return nullmpi_unsupported();
}
