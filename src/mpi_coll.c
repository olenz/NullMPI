#include "nullmpi.h"

/* Collective communication */

/* Helper */
static size_t SizeofMPIDatatype (MPI_Datatype type)
{
  switch (type)
    {
    case MPI_CHAR:		return sizeof (char);
    case MPI_UNSIGNED_CHAR:	return sizeof (unsigned char);
    case MPI_BYTE:		return 1;
    case MPI_SHORT:		return sizeof (short int);
    case MPI_UNSIGNED_SHORT:	return sizeof (unsigned short int);
    case MPI_INT:		return sizeof (int);
    case MPI_UNSIGNED:		return sizeof (unsigned int);
    case MPI_LONG:		return sizeof (long int);
    case MPI_UNSIGNED_LONG:	return sizeof (long unsigned int);
    case MPI_FLOAT:		return sizeof (float);
    case MPI_DOUBLE:		return sizeof (double);
    case MPI_LONG_DOUBLE:	return sizeof (long double);
#if HAVE_LONG_LONG_INT
    case MPI_LONG_LONG_INT:	return sizeof (long long int);
#endif
    default:
      nullmpi_print ("MPI_Datatype not implemented.\n");
      return 0;
    }
}

int MPI_Bcast (void* buf, int count, MPI_Datatype type, int root, MPI_Comm comm)
{
  NULLMPI_STATS;
  return MPI_SUCCESS;
}

int MPI_Gather (void* sendbuf, int sendcount, MPI_Datatype sendtype,
                void* recvbuf, int recvcount, MPI_Datatype recvtype,
		int root, MPI_Comm comm)
{
  NULLMPI_STATS;
  nullmpi_assert (SizeofMPIDatatype (sendtype) * sendcount ==
                  SizeofMPIDatatype (recvtype) * recvcount);
  memcpy (recvbuf, sendbuf, SizeofMPIDatatype (sendtype) * sendcount);
  return MPI_SUCCESS;
}

int MPI_Gatherv (void *sendbuf, int sendcount, MPI_Datatype sendtype,
                 void *recvbuf, int recvcounts[], int displs[],
                 MPI_Datatype recvtype, int root, MPI_Comm comm)
{
  NULLMPI_STATS;
  nullmpi_assert (SizeofMPIDatatype (sendtype) * sendcount ==
                  SizeofMPIDatatype (recvtype) * recvcounts[0]);
  memcpy ((char *)recvbuf + displs[0] * SizeofMPIDatatype (recvtype),
          sendbuf, SizeofMPIDatatype (sendtype) * sendcount);
  return MPI_SUCCESS;
}

int MPI_Scatter (void *sendbuf, int sendcount, MPI_Datatype sendtype,
                 void *recvbuf, int recvcount, MPI_Datatype recvtype,
                 int root, MPI_Comm comm)
{
  NULLMPI_STATS;
  nullmpi_assert (SizeofMPIDatatype (sendtype) * sendcount ==
                  SizeofMPIDatatype (recvtype) * recvcount);
  memcpy (recvbuf, sendbuf, SizeofMPIDatatype (sendtype) * sendcount);
  return MPI_SUCCESS;
}

int MPI_Scatterv (void *sendbuf, int *sendcounts, int *displs, MPI_Datatype sendtype,
                  void *recvbuf, int recvcount, MPI_Datatype recvtype,
                  int root, MPI_Comm comm)
{
  NULLMPI_STATS;
  nullmpi_assert (SizeofMPIDatatype (sendtype) * sendcounts[0] ==
                  SizeofMPIDatatype (recvtype) * recvcount);
  memcpy (recvbuf, (char *)sendbuf + displs[0] * SizeofMPIDatatype (recvtype),
          SizeofMPIDatatype (sendtype) * sendcounts[0]);
  return MPI_SUCCESS;
}

int MPI_Allgather (void* sendbuf, int sendcount, MPI_Datatype sendtype,
                   void* recvbuf, int recvcount, MPI_Datatype recvtype,
		   MPI_Comm comm)
{
  NULLMPI_STATS;
  memcpy (recvbuf, sendbuf, SizeofMPIDatatype (sendtype) * sendcount);
  return MPI_SUCCESS;
}

int MPI_Allgatherv(void *sendbuf, int sendcount, MPI_Datatype sendtype,
                   void *recvbuf, int *recvcounts, int *displs,
                   MPI_Datatype recvtype, MPI_Comm comm)
{
  NULLMPI_STATS;
  nullmpi_assert (SizeofMPIDatatype (sendtype) * sendcount ==
                  SizeofMPIDatatype (recvtype) * recvcounts[0]);
  memcpy ((char *)recvbuf + displs[0] * SizeofMPIDatatype (recvtype),
          sendbuf, SizeofMPIDatatype (sendtype) * sendcount);
  return MPI_SUCCESS;
}

int MPI_Alltoall(void *sendbuf, int sendcount, MPI_Datatype sendtype,
    void *recvbuf, int recvcount, MPI_Datatype recvtype,
    MPI_Comm comm)
{
  NULLMPI_STATS;
  nullmpi_assert (SizeofMPIDatatype (sendtype) * sendcount
      == SizeofMPIDatatype (recvtype) * recvcount);
  memcpy (recvbuf, sendbuf, SizeofMPIDatatype (sendtype) * sendcount);
  return MPI_SUCCESS;
}

int MPI_Alltoallv(void *sendbuf, int *sendcounts, int *sdispls,
    MPI_Datatype sendtype,
    void *recvbuf, int *recvcounts, int *rdispls,
    MPI_Datatype recvtype, MPI_Comm comm)
{
  NULLMPI_STATS;
  nullmpi_assert (SizeofMPIDatatype (sendtype) * sendcounts[0]
      == SizeofMPIDatatype (recvtype) * recvcounts[0]);
  memcpy ((char *)recvbuf + rdispls[0] * SizeofMPIDatatype (sendtype),
          (char *)sendbuf + sdispls[0] * SizeofMPIDatatype (sendtype),
	  SizeofMPIDatatype (sendtype) * sendcounts[0]);
  return MPI_SUCCESS;
}

int MPI_Reduce (void* sendbuf, void* recvbuf, int count,
	        MPI_Datatype type, MPI_Op op, int root, MPI_Comm comm)
{
  NULLMPI_STATS;
  memcpy (recvbuf, sendbuf, SizeofMPIDatatype (type) * count);
  return MPI_SUCCESS;
}

int MPI_Allreduce (void* sendbuf, void* recvbuf, int count,
		   MPI_Datatype type, MPI_Op op, MPI_Comm comm)
{
  NULLMPI_STATS;
  memcpy (recvbuf, sendbuf, SizeofMPIDatatype (type) * count);
  return MPI_SUCCESS;
}

int MPI_Reduce_scatter(void *sendbuf, void *recvbuf, int *recvcnts,
                       MPI_Datatype type, MPI_Op op, MPI_Comm comm)
{
  NULLMPI_STATS;
  memcpy (recvbuf, sendbuf, SizeofMPIDatatype (type) * recvcnts[0]);
  return MPI_SUCCESS;
}

int MPI_Scan(void *sendbuf, void *recvbuf, int count,
             MPI_Datatype type, MPI_Op op, MPI_Comm comm)
{
  NULLMPI_STATS;
  memcpy (recvbuf, sendbuf, SizeofMPIDatatype (type) * count);
  return MPI_SUCCESS;
}

int MPI_Op_create(MPI_User_function *function, int commute, MPI_Op *op)
{
  NULLMPI_STATS;
  return MPI_SUCCESS;
}

int MPI_Op_free(MPI_Op *op)
{
  NULLMPI_STATS;
  return MPI_SUCCESS;
}



int MPI_Sendrecv(void *sendbuf, int sendcount, MPI_Datatype sendtype,
                 int dest, int sendtag,
                 void *recvbuf, int recvcount, MPI_Datatype recvtype,
                 int source, int recvtag,
                 MPI_Comm comm, MPI_Status *status)
{
  NULLMPI_STATS;
  nullmpi_assert (dest == 0 && source == 0);
  nullmpi_assert (sendtag == recvtag);
  nullmpi_assert (SizeofMPIDatatype (sendtype) * sendcount ==
                  SizeofMPIDatatype (recvtype) * recvcount);
  memcpy (recvbuf, sendbuf, SizeofMPIDatatype (sendtype) * sendcount);
  return MPI_SUCCESS;
}

int MPI_Sendrecv_replace(void *buf, int count, MPI_Datatype datatype,
                         int dest, int sendtag, int source, int recvtag,
                         MPI_Comm comm, MPI_Status *status)
{
  NULLMPI_STATS;
  nullmpi_assert (dest == 0 && source == 0);
  nullmpi_assert (sendtag == recvtag);
  return MPI_SUCCESS;
}
