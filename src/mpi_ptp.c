/* mpi_ptp.c */

#include "nullmpi.h"

int MPI_Send (void* buf, int count, MPI_Datatype type, int count2,
	      int count3, MPI_Comm comm)
{
#if defined __ASSERT_FUNCTION && __PRINT_ASSERT_FUNCTION
  fprintf (stderr,"SingleProcessorMPI '%s'.\n",__ASSERT_FUNCTION);
#endif
  return 0;
}

int MPI_Recv (void* buf, int count, MPI_Datatype type, int count2, int count3,
	      MPI_Comm comm, MPI_Status *status)
{
#if defined __ASSERT_FUNCTION && __PRINT_ASSERT_FUNCTION
  fprintf (stderr,"SingleProcessorMPI '%s'.\n",__ASSERT_FUNCTION);
#endif
  return 0;
}

int MPI_Get_count (MPI_Status *status, MPI_Datatype type, int *count)
{
#if defined __ASSERT_FUNCTION && __PRINT_ASSERT_FUNCTION
  fprintf (stderr,"SingleProcessorMPI '%s'.\n",__ASSERT_FUNCTION);
#endif
  *count = 0;
  return 0;
}

int MPI_Probe (int count1, int count2, MPI_Comm comm, MPI_Status *status)
{
#if defined __ASSERT_FUNCTION && __PRINT_ASSERT_FUNCTION
  fprintf (stderr,"SingleProcessorMPI '%s'.\n",__ASSERT_FUNCTION);
#endif
  return 0;
}
