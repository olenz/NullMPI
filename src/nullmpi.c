/* $Id$ */
/* private data */

#include "nullmpi.h"

static enum {
 nullmpi_before_MPI_Init,
 nullmpi_after_MPI_Init,
 nullmpi_after_MPI_Finalize
} initialized;

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
  exit(error);
}

static MPI_Errhandler nullmpi_errhandler = MPI_ERRORS_RETURN;

static int nullmpi_handle_error(const char *s)
{
  nullmpi_print("an error occured");
  nullmpi_print(s);
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

int nullmpi_print(const char *string)
{
  return fprintf (stderr, "nullmpi: %s.\n", string);
}

int nullmpi_checkinit_print(const char *string)
{
  nullmpi_print (string);
  if (initialized != nullmpi_after_MPI_Init)
    return nullmpi_handle_error("MPI function called outside MPI_Init and MPI_Finalize");
  else
    return 0;
}

int nullmpi_unsupported(void)
{
  nullmpi_print("function not supported");
  return -1;
}
