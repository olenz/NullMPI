/* $Id$ */
/* Communicator handling */

#include "nullmpi.h"

int MPI_Intercomm_merge(MPI_Comm comm, int high,
    /*@out@*/ MPI_Comm *comm_out)
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}
