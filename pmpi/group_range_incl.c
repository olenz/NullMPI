#include "pmpi_wrap.h"

typedef int foobar[][3];
PMPI_WRAP4(MPI_Group_range_incl, MPI_Group, int, foobar, MPI_Group *)
