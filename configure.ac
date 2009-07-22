#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.57)
AC_INIT([NullMPI], [0.6], [wildenhues@ins.uni-bonn.de])
AC_REVISION($Revision$)
AC_CONFIG_SRCDIR([src/nullmpi.c])
AC_CONFIG_AUX_DIR(config)
AC_CONFIG_HEADERS([src/config.h])
AX_PREFIX_CONFIG_H([src/nullmpi_conf.h], [_NULLMPI])
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
AC_CHECK_SIZEOF(long double)
AC_CHECK_SIZEOF(long long)

# Checks for structures.

# Checks for compiler characteristics.
AC_C_CONST
AC_C_VAR_FUNC
AC_MSG_CHECKING([if the compiler understands __attribute__])
AC_CACHE_VAL([rw_cv_c_attribute],
	     [AC_COMPILE_IFELSE([int f(void) __attribute__((__pure__,__deprecated__));
	      int f(void) { return 1; }],
	      [rw_cv_c_attribute=yes],[rw_cv_c_attribute=no])])
case $rw_cv_c_attribute in
	yes) AC_MSG_RESULT([yes])
	AC_DEFINE(HAVE_ATTRIBUTE, 1, [define if the compiler understands __attribute__])
	;;
	no) AC_MSG_RESULT([no]) ;;
esac

# Checks for library functions.
AC_CHECK_FUNCS([memcpy gettimeofday getrusage])

# Checks for system services

# nullmpi features
AC_DEFINE([USE_MPI2_FEATURES], 1, [define if you want to make use of MPI2 features])
AC_DEFINE([USE_DEPRECATED_MPI1_FEATURES], 1, [define if you want to make use of deprecated MPI1 features])

AH_TOP([/*@-namechecks@*/])
AH_BOTTOM([#if defined(_NULLMPI_HAVE_ATTRIBUTE) || defined(HAVE_ATTRIBUTE)
# define __nullmpi_attribute__(a) __attribute__(a)
#else
# define __nullmpi_attribute__(a)
#endif

/* splint null checking: allow for valid user code */
#ifndef _NULLMPI_NULL
# define _NULLMPI_NULL /*@null@*/
#endif
/*@=namechecks@*/])

# We ought to be testing all of
# - build tree
# - destdir tree
# - install tree
# file system semantics.  However, we cannot expect to be able to write
# anywhere except the first at configure time.  So punt if that fails.
AC_CACHE_CHECK([whether the file system is case sensitive],
	       [nullmpi_cv_case_sensitive],
[rm -f conftest.ca?
echo hello > conftest.cas
echo bye > conftest.caS
if grep bye conftest.cas >/dev/null; then
  nullmpi_cv_case_sensitive=no
else
  nullmpi_cv_case_sensitive=yes
fi
rm -f conftest.ca?
])
AM_CONDITIONAL([CASE_SENSITIVE_FILE_SYSTEM], [test $nullmpi_cv_case_sensitive = yes])


AC_CONFIG_FILES([Makefile src/Makefile pmpi/Makefile tests/Makefile
		 man/mpicc.1 man/mpicxx.1 man/mpiexec.1])
AC_CONFIG_FILES([bin/mpicc bin/mpicxx bin/mpiexec], [chmod u+x bin/mpi*])
AC_OUTPUT
