/* $Id$ */
/* Communicator handling */

#include "nullmpi.h"

int MPI_Comm_test_inter(MPI_Comm comm, int *flag)
{
  NULLMPI_STATS;
  *flag = 0;
  return MPI_SUCCESS;
}
