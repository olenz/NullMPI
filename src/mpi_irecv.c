/* $Id$ */
/* Point-to-point communication */

#include "nullmpi.h"
#include "ptp.h"

int MPI_Irecv (void* buf, int count, MPI_Datatype type, int source,
               int tag, MPI_Comm comm, MPI_Request *request)
{
  NULLMPI_STATS;
  nullmpi_assert(request);
  *request = nullmpi_queue_ptp(buf, nullmpi_sizeof_datatype (type) * count, tag, comm, ISRECV);
  return *request ? MPI_SUCCESS : -1;
}
