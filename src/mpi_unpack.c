/* $Id$ */
/* User-defined datatypes */

#include "nullmpi.h"

int MPI_Unpack(void *inbuf, int insize, int *position,
    void *outbuf, int outcount, MPI_Datatype datatype, MPI_Comm comm)
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}
