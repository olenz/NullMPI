/* $Id$ */
/* User-defined datatypes */

#include "nullmpi.h"

int MPI_Type_contiguous(int count, MPI_Datatype oldtype,
    MPI_Datatype *newtype);

int MPI_Type_vector(int count, int blocklen, int stride,
    MPI_Datatype oldtype, MPI_Datatype *newtype);

int MPI_Type_indexed(int count, int blocklens[], int indices[],
    MPI_Datatype oldtype, MPI_Datatype *newtype);

#if _NULLMPI_USE_DEPRECATED_MPI1_FEATURES
int MPI_Type_hindexed(int, int *, MPI_Aint *, MPI_Datatype,
    MPI_Datatype *);
int MPI_Type_hvector(int, int, MPI_Aint, MPI_Datatype,
    MPI_Datatype *);

int MPI_Type_struct(int count, int blocklens[], MPI_Aint indices[],
               MPI_Datatype old_types[], MPI_Datatype *newtype)
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}

int MPI_Address(void *p, MPI_Aint *mp)
{
  NULLMPI_STATS;
  mp = &p;
  return MPI_SUCCESS;
}

int MPI_Type_extent(MPI_Datatype, MPI_Aint *);
int MPI_Type_lb(MPI_Datatype, MPI_Aint*);
int MPI_Type_ub(MPI_Datatype, MPI_Aint*);
#endif /* _NULLMPI_USE_DEPRECATED_MPI1_FEATURES */

int MPI_Type_size(MPI_Datatype datatype, int *size);

int MPI_Type_count(MPI_Datatype datatype, int *count);

int MPI_Type_commit(MPI_Datatype *datatype)
{
  NULLMPI_STATS;
  return nullmpi_unsupported();
}

int MPI_Type_free(MPI_Datatype *datatype);

int MPI_Get_elements(MPI_Status *status, MPI_Datatype datatype,
    int *count);

int MPI_Pack(void *inbuf, int incount, MPI_Datatype datatype,
    void *outbuf, int outsize, int *position, MPI_Comm comm)
;

int MPI_Unpack(void *inbuf, int insize, int *position,
    void *outbuf, int outcount, MPI_Datatype datatype, MPI_Comm comm)
;

int MPI_Pack_size(int incount, MPI_Datatype datatype, MPI_Comm comm,
    int *size)
    ;
