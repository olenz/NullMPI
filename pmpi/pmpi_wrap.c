#include <mpi.h>

static double totalTime;

#define _P(func) P##func

#define PMPI_WRAP1(func, type1)						\
int _P(func)(type1 arg1)						\
{									\
  double tstart = MPI_Wtime();						\
  int result = func(arg1);						\
  totalTime += MPI_Wtime() - tstart;					\
  return result;							\
}

#define PMPI_WRAP2(func, type1, type2)					\
int _P(func)(type1 arg1, type2 arg2)					\
{									\
  double tstart = MPI_Wtime();						\
  int result = func(arg1, arg2);					\
  totalTime += MPI_Wtime() - tstart;					\
  return result;							\
}

#define PMPI_WRAP3(func, type1, type2, type3)				\
int _P(func)(type1 arg1, type2 arg2, type3 arg3)			\
{									\
  double tstart = MPI_Wtime();						\
  int result = func(arg1, arg2, arg3);					\
  totalTime += MPI_Wtime() - tstart;					\
  return result;							\
}

#define PMPI_WRAP4(func, type1, type2, type3, type4)			\
int _P(func)(type1 arg1, type2 arg2, type3 arg3, type4 arg4)		\
{									\
  double tstart = MPI_Wtime();						\
  int result = func(arg1, arg2, arg3, arg4);				\
  totalTime += MPI_Wtime() - tstart;					\
  return result;							\
}

#define PMPI_WRAP5(func, type1, type2, type3, type4, type5)		\
int _P(func)(type1 arg1, type2 arg2, type3 arg3, type4 arg4,		\
    type5 arg5)								\
{									\
  double tstart = MPI_Wtime();						\
  int result = func(arg1, arg2, arg3, arg4, arg5);			\
  totalTime += MPI_Wtime() - tstart;					\
  return result;							\
}

#define PMPI_WRAP6(func, type1, type2, type3, type4, type5, type6)	\
int _P(func)(type1 arg1, type2 arg2, type3 arg3, type4 arg4,		\
    type5 arg5, type6 arg6)						\
{									\
  double tstart = MPI_Wtime();						\
  int result = func(arg1, arg2, arg3, arg4, arg5, arg6);		\
  totalTime += MPI_Wtime() - tstart;					\
  return result;							\
}

PMPI_WRAP6(MPI_Send, void *, int, MPI_Datatype, int, int, MPI_Comm)
