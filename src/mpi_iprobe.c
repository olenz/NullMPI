/* $Id$ */
/* Point-to-point communication */

#include "nullmpi.h"

int MPI_Iprobe(int source, int tag, MPI_Comm comm,
               int *flag, MPI_Status *status)
{
  NULLMPI_STATS;
  *flag = FALSE;
  return MPI_SUCCESS;
}
