/* $Id$ */
/* Initialization and Miscellaneous */

#include "nullmpi.h"

int MPI_Abort (MPI_Comm comm, int errorcode)
{
  NULLMPI_STATS;
  nullmpi_abort(errorcode);
}
