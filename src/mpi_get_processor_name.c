/* $Id$ */
/* Initialization and Miscellaneous */

#include "nullmpi.h"

int MPI_Get_processor_name(char *name, int *resultlen)
{
  NULLMPI_STATS;
  *resultlen = (int)strlen(NULLMPI_PROCESSOR_NAME);
  strcpy(name, NULLMPI_PROCESSOR_NAME);
  return MPI_SUCCESS;
}
