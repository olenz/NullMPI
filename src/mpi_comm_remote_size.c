/* $Id$ */
/* Group handling */

#include "nullmpi.h"

int MPI_Comm_remote_size(MPI_Comm comm, /*@out@*/ int *size)
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}
