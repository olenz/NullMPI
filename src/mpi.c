/* nullmpi mpi.c */

#include "nullmpi.h"

/* Init */
int MPI_Init (int *argc, char ***argv)
{
  nullmpi_initialize();
  NULLMPI_STATS;
  return MPI_SUCCESS;
}

int MPI_Finalize (void)
{
  NULLMPI_STATS;
  nullmpi_finalize();
  return MPI_SUCCESS;
}

int MPI_Abort (MPI_Comm comm, int errorcode)
{
  NULLMPI_STATS;
  nullmpi_abort(errorcode);
  return MPI_SUCCESS;
}

int MPI_Barrier (MPI_Comm comm)
{
  NULLMPI_STATS;
  return MPI_SUCCESS;
}

int MPI_Get_processor_name(char *name, int *resultlen)
{
  NULLMPI_STATS;
  *resultlen = strlen(NULLMPI_PROCESSOR_NAME);
  strcpy(name, NULLMPI_PROCESSOR_NAME);
  return MPI_SUCCESS;
}
