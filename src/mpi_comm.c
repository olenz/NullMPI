#include "nullmpi.h"

int MPI_Comm_size (MPI_Comm comm, int *size)
{
#if defined __ASSERT_FUNCTION && __PRINT_ASSERT_FUNCTION
  fprintf (stderr,"SingleProcessorMPI '%s'.\n",__ASSERT_FUNCTION);
#endif
  if (MPI_COMM_WORLD != comm)
    fprintf (stderr,"SingleProcessorMPI only with MPI_COMM_WORLD communicator.\n");
  *size = 1;
  return 0;
}

int MPI_Comm_rank (MPI_Comm comm, int *rank)
{
#if defined __ASSERT_FUNCTION && __PRINT_ASSERT_FUNCTION
  fprintf (stderr,"SingleProcessorMPI '%s'.\n",__ASSERT_FUNCTION);
#endif
  if (MPI_COMM_WORLD != comm)
    fprintf (stderr,"SingleProcessorMPI only with MPI_COMM_WORLD communicator.\n");
  *rank = 0;
  return 0;
}
