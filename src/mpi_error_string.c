/* $Id$ */
/* Error handling */

#include "nullmpi.h"

int MPI_Error_string(int errorcode,
    /*@out@*/ char *errstring, /*@out@*/ int *resultlen)
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}
