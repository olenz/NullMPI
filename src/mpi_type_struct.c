/* $Id$ */
/* User-defined datatypes */

#include "nullmpi.h"

#if _NULLMPI_USE_DEPRECATED_MPI1_FEATURES
int MPI_Type_struct(int count, int blocklens[], MPI_Aint indices[],
               MPI_Datatype old_types[], MPI_Datatype *newtype)
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}
#endif /* _NULLMPI_USE_DEPRECATED_MPI1_FEATURES */
