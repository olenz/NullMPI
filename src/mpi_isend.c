/* $Id$ */
/* Point-to-point communication */

#include "nullmpi.h"

int MPI_Isend (void* buf, int count, MPI_Datatype type, int dest,
	       int tag, MPI_Comm comm, MPI_Request *request)
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}
