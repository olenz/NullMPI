/* $Id$ */
/* Timer handling */

#include "nullmpi.h"

#if TIME_WITH_SYS_TIME
# include <sys/time.h>
# include <time.h>
#else
# if HAVE_SYS_TIME_H
#  include <sys/time.h>
# else
#  include <time.h>
# endif
#endif

#if HAVE_SYS_RESOURCE_H
# include <sys/resource.h>
#endif

#if HAVE_UNISTD_H
# include <unistd.h>
#endif


/* Timing */
double MPI_Wtime (void)
{
  NULLMPI_STATS;
#ifdef __RUSAGE_TIME__
  struct rusage rut;
  double ut, st, wt;
  /* initalize time */
  getrusage (RUSAGE_SELF,&rut);
  /* user time */
  ut = rut.ru_utime.tv_sec + 1e-6 * rut.ru_utime.tv_usec;
  /* system time */
  st = rut.ru_stime.tv_sec + 1e-6 * rut.ru_stime.tv_usec;
  /* wallclock time */
  wt = ut + st;
  return wt;
#else
  return (double)clock () / (double)CLOCKS_PER_SEC;
#endif
}

/* FIXME: this one needs a lot of work */
double MPI_Wtick(void);
