/* $Id$ */
/* Communicator handling */

#include "nullmpi.h"

int MPI_Intercomm_create(MPI_Comm local_comm, int local_leader,
                         MPI_Comm peer_comm, int remote_leader, int tag,
                         MPI_Comm *comm_out)
{
  NULLMPI_STATS;
  *comm_out = local_comm;
  return nullmpi_unsupported();
}
