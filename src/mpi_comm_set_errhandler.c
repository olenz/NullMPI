/* $Id$ */
/* Communicator handling */

#include "nullmpi.h"

/* MPI2 */
#if _NULLMPI_USE_MPI2_FEATURES

int MPI_Comm_set_errhandler(MPI_Comm comm,
    MPI_Errhandler errhandler)
{
  NULLMPI_STATS;
  return nullmpi_set_errhandler(comm, &errhandler);
}

#endif /* _NULLMPI_USE_MPI2_FEATURES */
