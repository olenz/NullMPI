#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.57)
AC_INIT([nullmpi], [0.2], [wildenhues@ins.uni-bonn.de])
AC_REVISION($Revision$)
AC_CONFIG_SRCDIR([src/mpi.c])
AC_CONFIG_AUX_DIR(config)
AC_CONFIG_HEADERS([src/config.h])
AM_INIT_AUTOMAKE([1.7 foreign -Wall])

# Checks for programs.
AC_PROG_CC
AC_PROG_CXX
AC_PROG_CPP
AC_PROG_INSTALL
AC_PROG_RANLIB
AC_PROG_LN_S
AC_PROG_MAKE_SET

# Checks for header files.
AC_HEADER_STDC
AC_HEADER_TIME
AC_CHECK_HEADERS([assert.h sys/resource.h unistd.h])

# Checks for types.
AC_CHECK_TYPES([long long int])

# Checks for structures.
AC_CHECK_MEMBER([struct rusage.ru_utime.tv_sec],,,
[#if TIME_WITH_SYS_TIME
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
#endif])


# Checks for compiler characteristics.
AC_C_STRINGIZE
AC_C_CONST
AC_C_VAR_FUNC

# Checks for library functions.
AC_CHECK_FUNCS([memcpy gettimeofday getrusage])

# Checks for system services

AC_CONFIG_FILES([Makefile src/Makefile])
AC_CONFIG_FILES([bin/mpicc bin/mpiCC bin/mpiexec], [chmod u+x bin/mpi*])
AC_OUTPUT
