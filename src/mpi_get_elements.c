/* $Id$ */
/* User-defined datatypes */

#include "nullmpi.h"

int MPI_Get_elements(MPI_Status *status, MPI_Datatype datatype, int *count)
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}
