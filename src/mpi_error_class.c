/* $Id$ */
/* Error handling */

#include "nullmpi.h"

int MPI_Error_class(int errorcode, /*@out@*/ int *errorclass)
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}
