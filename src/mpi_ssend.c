/* $Id$ */
/* Point-to-point communication */

#include "nullmpi.h"

int MPI_Ssend (void *buf, int count, MPI_Datatype datatype,
    int dest, int tag, MPI_Comm comm)
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}
