/* $Id$ */
/* User-defined datatypes */

#include "nullmpi.h"

#if _NULLMPI_USE_DEPRECATED_MPI1_FEATURES
int MPI_Address(void *p, MPI_Aint *mp)
{
  NULLMPI_STATS;
  /*@i@*/ *mp = p;
  return MPI_SUCCESS;
}
#endif /* _NULLMPI_USE_DEPRECATED_MPI1_FEATURES */
