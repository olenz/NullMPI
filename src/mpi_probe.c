/* $Id$ */
/* Point-to-point communication */

#include "nullmpi.h"

int MPI_Probe (int count1, int count2, MPI_Comm comm, MPI_Status *status)
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}
