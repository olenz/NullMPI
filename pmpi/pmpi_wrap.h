#include <mpi.h>

#define totalTime nullmpi_total_time
extern double totalTime;

#define _P(func) P##func

#define PMPI_WRAP0(func)						\
int _P(func)(void)							\
{									\
  double tstart = MPI_Wtime();						\
  int result = func();							\
  totalTime += MPI_Wtime() - tstart;					\
  return result;							\
}

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

#define PMPI_WRAP7(func, type1, type2, type3, type4, type5, type6,	\
    type7)								\
int _P(func)(type1 arg1, type2 arg2, type3 arg3, type4 arg4,		\
    type5 arg5, type6 arg6, type7 arg7)					\
{									\
  double tstart = MPI_Wtime();						\
  int result = func(arg1, arg2, arg3, arg4, arg5, arg6, arg7);		\
  totalTime += MPI_Wtime() - tstart;					\
  return result;							\
}

#define PMPI_WRAP8(func, type1, type2, type3, type4, type5, type6,	\
    type7, type8)							\
int _P(func)(type1 arg1, type2 arg2, type3 arg3, type4 arg4,		\
    type5 arg5, type6 arg6, type7 arg7, type8 arg8)			\
{									\
  double tstart = MPI_Wtime();						\
  int result = func(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);	\
  totalTime += MPI_Wtime() - tstart;					\
  return result;							\
}

#define PMPI_WRAP9(func, type1, type2, type3, type4, type5, type6,	\
    type7, type8, type9)						\
int _P(func)(type1 arg1, type2 arg2, type3 arg3, type4 arg4,		\
    type5 arg5, type6 arg6, type7 arg7, type8 arg8, type9 arg9)		\
{									\
  double tstart = MPI_Wtime();						\
  int result = func(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8,	\
      arg9);								\
  totalTime += MPI_Wtime() - tstart;					\
  return result;							\
}

#define PMPI_WRAP10(func, type1, type2, type3, type4, type5, type6,	\
    type7, type8, type9, type10)					\
int _P(func)(type1 arg1, type2 arg2, type3 arg3, type4 arg4,		\
    type5 arg5, type6 arg6, type7 arg7, type8 arg8, type9 arg9,		\
    type10 arg10)							\
{									\
  double tstart = MPI_Wtime();						\
  int result = func(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8,	\
      arg9, arg10);							\
  totalTime += MPI_Wtime() - tstart;					\
  return result;							\
}

#define PMPI_WRAP11(func, type1, type2, type3, type4, type5, type6,	\
    type7, type8, type9, type10, type11)				\
int _P(func)(type1 arg1, type2 arg2, type3 arg3, type4 arg4,		\
    type5 arg5, type6 arg6, type7 arg7, type8 arg8, type9 arg9,		\
    type10 arg10, type11 arg11)						\
{									\
  double tstart = MPI_Wtime();						\
  int result = func(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8,	\
      arg9, arg10, arg11);						\
  totalTime += MPI_Wtime() - tstart;					\
  return result;							\
}

#define PMPI_WRAP12(func, type1, type2, type3, type4, type5, type6,	\
    type7, type8, type9, type10, type11, type12)			\
int _P(func)(type1 arg1, type2 arg2, type3 arg3, type4 arg4,		\
    type5 arg5, type6 arg6, type7 arg7, type8 arg8, type9 arg9,		\
    type10 arg10, type11 arg11, type12 arg12)				\
{									\
  double tstart = MPI_Wtime();						\
  int result = func(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8,	\
      arg9, arg10, arg11, arg12);					\
  totalTime += MPI_Wtime() - tstart;					\
  return result;							\
}
