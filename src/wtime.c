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

/* possible implementations, to be sorted in decreasing order of accuracy:
 *
 * could just use usclock package from mpich/mpid/ch_p4/p4/usc
 *
 * WALL TIME:
 * timing          resolution     nominal res.  wraparound  standardization/usage
 * ------------------------------------------------------------------------------
 * clock_gettime   clock_getres   1e-9 s                    SUSv3 (realtime)
 * gettimeofday    --             1e-6 s                    SUSv3, SVr4, BSD 4.3
 * ftime                          1e-3 s                    POSIX 1003.1-2001, BSD 4.2 (obsolete)
 * time                           1e+0 s                    SVr4, SVID, POSIX, X/OPEN, BSD 4.3 (obsolete)
 *
 *
 * PROCESSOR TIME:
 * timing          resolution     nominal res.  wraparound  standardization/usage
 * ------------------------------------------------------------------------------
 * getrusage                                                SVr4, BSD 4.3

 * times           sysconf(_SC_CLK_TCK)                     SVr4, SVID, POSIX, X/OPEN, BSD 4.3
 *                 CLK_TCK (obsolete)
 *                 HZ (even more obsolete)
 *
 * clock           CLOCKS_PER_SEC 1e-6 s                    ANSI C, POSIX
 *    POSIX unfortunately requires CLOCKS_PER_SEC to be 1000000 independent of actual resolution
 *    wraparound of 72 min on 32bit
 */

double MPI_Wtime (void)
{
#if HAVE_GETRUSAGE
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
#elif HAVE_GETTIMEOFDAY
  struct timezone tzp;
  struct timeval tv;
  gettimeofday(&tv, &tzp);
  return tv.tv_sec + 1.e-6 * tv.tv_usec;
#else
  return clock () / (double)CLOCKS_PER_SEC;
#endif
}

/* FIXME: make this one correct */
double MPI_Wtick (void)
{
#if HAVE_GETRUSAGE
  return 1.e-6;
#elif HAVE_GETTIMEOFDAY
  return 1.e-6;
#else
  return 1e-3;		/* be conservative */
#endif
}
