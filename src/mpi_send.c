/* $Id$ */
/* Point-to-point communication */

#include "nullmpi.h"
#include "ptp.h"

int MPI_Send (void* buf, int count, MPI_Datatype type, int dest,
	      int tag, MPI_Comm comm)
{
  NULLMPI_STATS;
  return nullmpi_blockptp(buf, count, type, tag, comm, NULL, ISSEND);
}
