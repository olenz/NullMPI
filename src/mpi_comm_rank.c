/* $Id$ */
/* Communicator handling */

#include "nullmpi.h"

/*@access MPI_Comm@*/

int MPI_Comm_rank (MPI_Comm comm, int *rank)
{
  NULLMPI_STATS;
  if (MPI_COMM_WORLD != comm)
    fprintf (stderr,"SingleProcessorMPI only with MPI_COMM_WORLD communicator.\n");
  *rank = 0;
  return MPI_SUCCESS;
}
