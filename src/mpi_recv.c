/* $Id$ */
/* Point-to-point communication */

#include "nullmpi.h"
#include "ptp.h"

int MPI_Recv (void* buf, int count, MPI_Datatype type, int source,
              int tag, MPI_Comm comm, MPI_Status *status)
{
  NULLMPI_STATS;
  return nullmpi_blockptp(buf, count, type, tag, comm, status, ISRECV);
}
