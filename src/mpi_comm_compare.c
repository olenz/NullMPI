/* $Id$ */
/* Communicator handling */

#include "nullmpi.h"

int MPI_Comm_compare(MPI_Comm comm1, MPI_Comm comm2, int *res)
{
  NULLMPI_STATS;
  *res = MPI_IDENT;
  return MPI_SUCCESS;
}
