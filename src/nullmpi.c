#include "nullmpi.h"

static int initialized;

void nullmpi_initialize(void)
{
  initialized = 1;
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
