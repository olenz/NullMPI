/* $Id$ */
/* Initialization and Miscellaneous */

#include "nullmpi.h"

/* Init */
int MPI_Init (int *argc, char ***argv)
{
  nullmpi_initialize();
  NULLMPI_STATS;
  return MPI_SUCCESS;
}

int MPI_Finalize (void)
{
  NULLMPI_STATS;
  nullmpi_finalize();
  return MPI_SUCCESS;
}

int MPI_Initialized(int *flag)
{
  *flag = nullmpi_initialized();
  return MPI_SUCCESS;
}

int MPI_Abort (MPI_Comm comm, int errorcode)
{
  NULLMPI_STATS;
  nullmpi_abort(errorcode);
  return MPI_SUCCESS;
}

int MPI_Pcontrol(const int, ...);

int MPI_Barrier (MPI_Comm comm)
{
  NULLMPI_STATS;
  return MPI_SUCCESS;
}

int MPI_Get_processor_name(char *name, int *resultlen)
{
  NULLMPI_STATS;
  *resultlen = strlen(NULLMPI_PROCESSOR_NAME);
  strcpy(name, NULLMPI_PROCESSOR_NAME);
  return MPI_SUCCESS;
}

#if _NULLMPI_USE_DEPRECATED_MPI1_FEATURES

int MPI_Keyval_create(MPI_Copy_function *, MPI_Delete_function *,
    int *, void *);
int MPI_Keyval_free(int *);

int MPI_Attr_put(MPI_Comm, int, void *);
int MPI_Attr_get(MPI_Comm, int, void *, int *);
int MPI_Attr_delete(MPI_Comm, int);

/* MPI-1.2 */

int MPI_Errhandler_create(MPI_Handler_function *,
    MPI_Errhandler *);
int MPI_Errhandler_set(MPI_Comm, MPI_Errhandler);
int MPI_Errhandler_get(MPI_Comm, MPI_Errhandler *);
int MPI_Errhandler_free(MPI_Errhandler *);

#endif /* _NULLMPI_USE_DEPRECATED_MPI1_FEATURES */

int MPI_Get_version(int *version, int *subversion)
{
  *version = MPI_VERSION;
  *subversion = MPI_SUBVERSION;
  return MPI_SUCCESS;
}

int MPI_Error_string(int errorcode,
    char *errstring, int *resultlen)
;

int MPI_Error_class(int errorcode, int *errorclass)
    ;
