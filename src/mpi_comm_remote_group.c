/* $Id$ */
/* Group handling */

#include "nullmpi.h"

int MPI_Comm_remote_group(MPI_Comm comm, /*@out@*/ MPI_Group *group)
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}
