/* $Id$ */
/* Communicator handling */

#include "nullmpi.h"

int MPI_Topo_test(MPI_Comm comm, /*@out@*/ int *type)
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}
