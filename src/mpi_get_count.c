/* $Id$ */
/* Point-to-point communication */

#include "nullmpi.h"

int MPI_Get_count (MPI_Status *status, MPI_Datatype type, int *count)
{
  size_t elsize;
  NULLMPI_STATS;
  elsize = nullmpi_sizeof_datatype(type);
  if (elsize) {
    *count = status->size / elsize;
    return MPI_SUCCESS;
  } else {
    return nullmpi_unsupported();
  }
}
