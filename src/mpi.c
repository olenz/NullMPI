/* nullmpi mpi.c */

#include "nullmpi.h"

/* Init */
int MPI_Init (int *argc, char ***argv)
{
#if defined __ASSERT_FUNCTION && __PRINT_ASSERT_FUNCTION
  fprintf (stderr,"SingleProcessorMPI '%s'.\n",__ASSERT_FUNCTION);
#endif
  return 0;
}

int MPI_Finalize (void)
{
#if defined __ASSERT_FUNCTION && __PRINT_ASSERT_FUNCTION
  fprintf (stderr,"SingleProcessorMPI '%s'.\n",__ASSERT_FUNCTION);
#endif
  return 0;
}

int MPI_Abort (MPI_Comm comm, int errorcode)
{
#if defined __ASSERT_FUNCTION && __PRINT_ASSERT_FUNCTION
  fprintf (stderr,"SingleProcessorMPI '%s'.\n",__ASSERT_FUNCTION);
#endif
  abort();
  exit(errorcode);
  return 0;
}

/* Communication */
int MPI_Barrier (MPI_Comm comm)
{
#if defined __ASSERT_FUNCTION && __PRINT_ASSERT_FUNCTION
  fprintf (stderr,"SingleProcessorMPI '%s'.\n",__ASSERT_FUNCTION);
#endif
  return 0;
}
