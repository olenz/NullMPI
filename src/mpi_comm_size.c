/* $Id$ */
/* Communicator handling */

#include "nullmpi.h"

/*@access MPI_Comm@*/

int MPI_Comm_size (MPI_Comm comm, int *size)
{
  NULLMPI_STATS;
  if (MPI_COMM_WORLD != comm)
    fprintf (stderr,"SingleProcessorMPI only with MPI_COMM_WORLD communicator.\n");
  *size = 1;
  return MPI_SUCCESS;
}
