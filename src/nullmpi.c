/* $Id$ */
/* private data */

#include "nullmpi.h"

static enum {
 nullmpi_before_MPI_Init,
 nullmpi_after_MPI_Init,
 nullmpi_after_MPI_Finalize
} initialized;

static int nullmpi_debuglevel;

int nullmpi_get_debuglevel(void)
{
  return nullmpi_debuglevel;
}

void nullmpi_set_debuglevel(int level)
{
  nullmpi_debuglevel = level;
}

void nullmpi_initialize(void)
{
  initialized = nullmpi_after_MPI_Init;
}

int nullmpi_initialized(void)
{
  /* we want no error after finalize: cf. MPI-1.2 clarification */
  return initialized != nullmpi_before_MPI_Init;
}

void nullmpi_finalize(void)
{
  initialized = nullmpi_after_MPI_Finalize;
}

int nullmpi_finalized(void)
{
  return initialized == nullmpi_after_MPI_Finalize;
}

void nullmpi_abort(int error)
{
  abort();
  /*@notreached@*/
  exit(error);
}

static MPI_Errhandler nullmpi_errhandler = MPI_ERRORS_RETURN;

static int nullmpi_handle_error(const char *s)
{
  (void)nullmpi_printf("an error occured: %s", s ? s : "");
  switch (nullmpi_errhandler) {
  case MPI_ERRORS_ARE_FATAL:
    nullmpi_abort(127);
  case MPI_ERRORS_RETURN:
    return -1;
  default:
    nullmpi_print("errhandler not implemented");
    return -1;
  }
}

int nullmpi_set_errhandler(MPI_Comm comm, MPI_Errhandler *errhandler)
{
  switch (nullmpi_errhandler) {
  case MPI_ERRORS_ARE_FATAL:
  case MPI_ERRORS_RETURN:
    nullmpi_errhandler = *errhandler;
    return MPI_SUCCESS;
  default:
    return nullmpi_unsupported();
  }
}

int nullmpi_printf(const char *fmt, ...)
{
  va_list ap;

  fputs("nullmpi: ", stderr);
  va_start(ap, fmt);
  vfprintf(stderr, fmt, ap);
  va_end(ap);
  return fputc('\n', stderr);
}

int nullmpi_print(const char *string)
{
  fputs("nullmpi: ", stderr);
  fputs(string, stderr);
  return fputc('\n', stderr);
}

int nullmpi_checkinit_print(const char *string)
{
  nullmpi_print (string);
  if (initialized != nullmpi_after_MPI_Init)
    return nullmpi_handle_error("MPI function called outside MPI_Init and MPI_Finalize");
  else
    return 0;
}

int nullmpi_stats(const char *func)
{
  return nullmpi_get_debuglevel() ? nullmpi_checkinit_print(func) : 0;
}

int nullmpi_unsupported(void)
{
  nullmpi_print("function not supported");
  return -1;
}

void /*@exits@*/ nullmpi_deadlock(void)
{
  nullmpi_print("deadlock found");
  nullmpi_abort(127);
}

/*@access MPI_Datatype@*/

struct floatint		{ float x; int d;};
struct doubleint	{ double x; int d;};
struct longint		{ long l; int d;};
struct shortint		{ short s; int d;};
struct twoint		{ int d1, d2;};
struct longdblint	{ long double lx; int x;};

size_t nullmpi_sizeof_datatype (MPI_Datatype type)
{
  static const size_t nullmpi_datatype_sizes[NULLMPI_MAX_DATATYPE] = {
    0,				/* MPI_DATATYPE_NULL, */
    1,				/* MPI_CHAR, */
    1,				/* MPI_UNSIGNED_CHAR, */
    1,				/* MPI_BYTE, */
    sizeof(short),		/* MPI_SHORT, */
    sizeof(unsigned short),	/* MPI_UNSIGNED_SHORT, */
    sizeof(int),		/* MPI_INT, */
    sizeof(unsigned int),	/* MPI_UNSIGNED, */
    sizeof(long),		/* MPI_LONG, */
    sizeof(unsigned long),	/* MPI_UNSIGNED_LONG, */
    sizeof(float),		/* MPI_FLOAT, */
    sizeof(double),		/* MPI_DOUBLE, */
    SIZEOF_LONG_DOUBLE,		/* MPI_LONG_DOUBLE, */
    SIZEOF_LONG_LONG,		/* MPI_LONG_LONG_INT, */
    /* */
    0,				/* MPI_PACKED, */
    /* */
    0,				/* MPI_LB, */
    0,				/* MPI_UB, */
    /* */
    sizeof(struct floatint),	/* MPI_FLOAT_INT, */
    sizeof(struct doubleint),	/* MPI_DOUBLE_INT, */
    sizeof(struct longint),	/* MPI_LONG_INT, */
    sizeof(struct shortint),	/* MPI_SHORT_INT, */
    sizeof(struct twoint),	/* MPI_2INT, */
    sizeof(struct longdblint),	/* MPI_LONG_DOUBLE_INT, */
    /* */
    0,				/* MPI_COMPLEX, */
    0,				/* MPI_DOUBLE_COMPLEX, */
    0,				/* MPI_LOGICAL, */
    0,				/* MPI_REAL, */
    0,				/* MPI_DOUBLE_PRECISION, */
    0,				/* MPI_INTEGER, */
    0,				/* MPI_2INTEGER, */
    0,				/* MPI_2COMPLEX, */
    0,				/* MPI_2DOUBLE_COMPLEX, */
    0,				/* MPI_2REAL, */
    0,				/* MPI_2DOUBLE_PRECISION, */
    0				/* MPI_CHARACTER */
  };

  if ((int)type >= 0 &&
      (int)type < NULLMPI_MAX_DATATYPE &&
      nullmpi_datatype_sizes[(int)type] > 0)
    return nullmpi_datatype_sizes[(int)type];
  else
      nullmpi_print ("MPI_Datatype not implemented.\n");
  return 0;
}
