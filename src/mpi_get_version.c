/* $Id$ */
/* Initialization and Miscellaneous */

#include "nullmpi.h"

int MPI_Get_version(int *version, int *subversion)
{
  *version = MPI_VERSION;
  *subversion = MPI_SUBVERSION;
  return MPI_SUCCESS;
}
