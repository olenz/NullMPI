/* $Id$ */
/* Point-to-point communication */

#include "nullmpi.h"

int MPI_Rsend_init(void *buf, int count, MPI_Datatype datatype,
    int dest, int tag, MPI_Comm comm, /*@out@*/ MPI_Request *request)
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}
