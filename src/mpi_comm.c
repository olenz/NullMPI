/* $Id$ */
/* Communicator handling */

#include "nullmpi.h"

int MPI_Comm_size (MPI_Comm comm, int *size)
{
  NULLMPI_STATS;
  if (MPI_COMM_WORLD != comm)
    fprintf (stderr,"SingleProcessorMPI only with MPI_COMM_WORLD communicator.\n");
  *size = 1;
  return MPI_SUCCESS;
}

int MPI_Comm_rank (MPI_Comm comm, int *rank)
{
  NULLMPI_STATS;
  if (MPI_COMM_WORLD != comm)
    fprintf (stderr,"SingleProcessorMPI only with MPI_COMM_WORLD communicator.\n");
  *rank = 0;
  return MPI_SUCCESS;
}

int MPI_Comm_compare(MPI_Comm comm1, MPI_Comm comm2, int *res)
{
  NULLMPI_STATS;
  *res = MPI_IDENT;
  return MPI_SUCCESS;
}

int MPI_Comm_dup(MPI_Comm comm, MPI_Comm *newcomm)
{
  NULLMPI_STATS;
  *newcomm = comm;
  return MPI_SUCCESS;
}

int MPI_Comm_create(MPI_Comm comm, MPI_Group group, MPI_Comm *comm_out)
{
  NULLMPI_STATS;
  *comm_out = comm;
  return MPI_SUCCESS;
}

int MPI_Comm_split(MPI_Comm comm, int color, int key, MPI_Comm *comm_out)
{
  NULLMPI_STATS;
  if (color == MPI_UNDEFINED)
    *comm_out = MPI_COMM_NULL;
  else
    *comm_out = comm;
  return MPI_SUCCESS;
}

int MPI_Comm_free(MPI_Comm *comm)
{
  NULLMPI_STATS;
  return MPI_SUCCESS;
}

int MPI_Comm_test_inter(MPI_Comm comm, int *flag)
{
  NULLMPI_STATS;
  *flag = 0;
  return MPI_SUCCESS;
}

int MPI_Comm_remote_size(MPI_Comm comm, int *size);

int MPI_Comm_remote_group(MPI_Comm comm, MPI_Group *group);

int MPI_Intercomm_create(MPI_Comm local_comm, int local_leader,
                         MPI_Comm peer_comm, int remote_leader, int tag,
                         MPI_Comm *comm_out);

int MPI_Intercomm_merge(MPI_Comm comm, int high,
                        MPI_Comm *comm_out);

int MPI_Topo_test(MPI_Comm comm, int *type);


/* MPI2 */
#ifdef _NULLMPI_USE_MPI2_FEATURES

int MPI_Comm_create_errhandler(MPI_Comm_errhandler_fn *function,
    MPI_Errhandler *errhandler);

int MPI_Comm_get_errhandler(MPI_Comm comm,
    MPI_Errhandler *errhandler);

int MPI_Comm_set_errhandler(MPI_Comm comm,
    MPI_Errhandler errhandler)
{
  NULLMPI_STATS;
  return nullmpi_set_errhandler(comm, &errhandler);
}

#endif /* _NULLMPI_USE_MPI2_FEATURES */
