/* $Id$ */
/* User-defined datatypes */

#include "nullmpi.h"

int MPI_Pack(void *inbuf, int incount, MPI_Datatype datatype,
    void *outbuf, int outsize, int *position, MPI_Comm comm)
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}
