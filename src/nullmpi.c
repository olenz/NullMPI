/* $Id$ */
/* private data */

#include "nullmpi.h"

static int initialized;

void nullmpi_initialize(void)
{
  initialized = 1;
}

int nullmpi_initialized(void)
{
  return initialized;
}

void nullmpi_finalize(void)
{
  initialized = 2;
}

void nullmpi_abort(int error)
{
  abort();
  exit(error);
}

int nullmpi_print(const char *string)
{
  fprintf (stderr, "nullmpi: %s.\n", string);
  nullmpi_assert (initialized == 1);
  return 0;
}

int nullmpi_unsupported(void)
{
  nullmpi_print("function not supported");
  return -1;
}
