/* $Id$ */
/* private data and portability header */

/* for splint @null@ checking: inside nullmpi, these pointers are not to be null! */
#define _NULLMPI_NULL

#ifdef HAVE_CONFIG_H
# include <config.h>
#else
# error "compilation without config.h header not supported."
#endif


#ifdef HAVE_ATTRIBUTE
# define __nullmpi_attribute__(a) __attribute__(a)
#else
# define __nullmpi_attribute__(a)
#endif

#if STDC_HEADERS
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
#else
# if !HAVE_MEMCPY
#  define memcpy(d, s, n) bcopy ((s), (d), (n))
# endif
#endif

#if HAVE_ASSERT_H
# include <assert.h> /* for __ASSERT_FUNCTION */
#endif

#include "mpi.h"

#ifndef FALSE
/*@notfunction@*/
# define FALSE 0
/*@notfunction@*/
# define TRUE !FALSE
#endif

#if defined __ASSERT_FUNCTION
# define NULLMPI_STATS nullmpi_stats(__ASSERT_FUNCTION)
#else
# if HAVE_FUNC
#  define NULLMPI_STATS nullmpi_stats(__func__)
# else
#  define NULLMPI_STATS
# endif
#endif

#define NULLMPI_PROCESSOR_NAME "supercomputer"

int nullmpi_get_debuglevel(void)
  __nullmpi_attribute__((__pure__));
void nullmpi_set_debuglevel(int level);

extern int nullmpi_print(const char *string);
extern int nullmpi_printf(const char *fmt, ...);
extern int nullmpi_checkinit_print(const char *string);
extern int nullmpi_stats(const char *func);
#define nullmpi_assert(EXPR) assert(EXPR)

extern void nullmpi_initialize(void);
extern int nullmpi_initialized(void)
  __nullmpi_attribute__((__pure__));
extern void nullmpi_finalize(void);
extern int nullmpi_finalized(void)
  __nullmpi_attribute__((__pure__));
extern void /*@exits@*/ nullmpi_abort(int)
  __nullmpi_attribute__((__noreturn__));
extern int nullmpi_unsupported(void);
extern int nullmpi_set_errhandler(MPI_Comm, MPI_Errhandler *);

extern size_t nullmpi_sizeof_datatype (MPI_Datatype type)
  __nullmpi_attribute__((__const__));
