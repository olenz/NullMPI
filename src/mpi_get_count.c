/* $Id$ */
/* Point-to-point communication */

#include "nullmpi.h"

int MPI_Get_count (MPI_Status *status, MPI_Datatype type, int *count)
{
  size_t elsize;
  NULLMPI_STATS;
  elsize = nullmpi_sizeof_datatype(type);
  if (elsize && status->size / elsize * elsize == status->size)
    *count = status->size / elsize;
  else
    *count = MPI_UNDEFINED;
  return MPI_SUCCESS;
}
