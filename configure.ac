#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.57)
AC_INIT([nullmpi], [0.3], [wildenhues@ins.uni-bonn.de])
AC_REVISION($Revision$)
AC_CONFIG_SRCDIR([src/mpi.c])
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

# Checks for structures.

# Checks for compiler characteristics.
AC_C_CONST
AC_C_VAR_FUNC
attr_dep='__attribute__ ((__deprecated__))'
AC_MSG_CHECKING([if the compiler understands $attr_dep])
AC_CACHE_VAL([rw_cv_c_attr_dep],
	     [AC_COMPILE_IFELSE([int f(void) $attr_dep;
int f(void) { return 1; }],
		          	[rw_cv_c_attr_dep="$attr_dep"],
				[rw_cv_c_attr_dep=])])
AC_DEFINE_UNQUOTED([ATTR_DEPRECATED], [$rw_cv_c_attr_dep], [define if your compiler understands __attribute__ ((deprecated)) or alike])
case $rw_cv_c_attr_dep in
	?*) AC_MSG_RESULT([yes]) ;;
	*) AC_MSG_RESULT([no]) ;;
esac

# Checks for library functions.
AC_CHECK_FUNCS([memcpy gettimeofday getrusage])

# Checks for system services

# nullmpi features
AC_DEFINE([USE_MPI2_FEATURES], 1, [define if you want to make use of MPI2 features])
AC_DEFINE([USE_DEPRECATED_MPI1_FEATURES], 1, [define if you want to make use of deprecated MPI1 features])

AH_TOP([/*@-namechecks@*/])
AH_BOTTOM([/*@=namechecks@*/])

AC_CONFIG_FILES([Makefile src/Makefile
		 man/mpicc.1 man/mpiCC.1 man/mpiexec.1])
AC_CONFIG_FILES([bin/mpicc bin/mpiCC bin/mpiexec], [chmod u+x bin/mpi*])
AC_OUTPUT
