/* $Id$ */
/* Point-to-point communication */

#include "nullmpi.h"

int MPI_Recv_init(void *buf, int count, MPI_Datatype datatype,
    int source, int tag, MPI_Comm comm, MPI_Request *request)
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}
