#include "nullmpi.h"

/* Collective communication */

/* Helper */
static size_t _NULLMPI_SizeofMPIDatatype (MPI_Datatype type)
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
      fprintf (stderr,"MPI_Datatype not implemented.\n");
      return 0;
    }
}

int MPI_Bcast (void* buf, int count, MPI_Datatype type, int count2, MPI_Comm comm)
{
#if defined __ASSERT_FUNCTION && __PRINT_ASSERT_FUNCTION
  fprintf (stderr,"SingleProcessorMPI '%s'.\n",__ASSERT_FUNCTION);
#endif
  return 0;
}

#if 0
int MY_Bcast (void* buf, int count, MPI_Datatype type, int proc, MPI_Comm communicator)
{
  int processid;
  int numberofprocesses;
  int i;
  int tag = 0;
  MPI_Status status;
  MPI_Comm_rank (communicator, &processid);
  MPI_Comm_size (communicator, &numberofprocesses);
  if (processid == proc)
        for (i = 0; i < numberofprocesses; ++i)
{
                if (i!=processid)
                        MPI_Send (buf, count, type, i, tag, communicator);
}
  else
        MPI_Recv (buf, count, type, proc, tag, communicator, &status);
  return 0;
}
#endif

int MPI_Gather (void* buf, int count, MPI_Datatype type, void* buf2, int count2,
		MPI_Datatype type2, int count3, MPI_Comm comm)
{
#if defined __ASSERT_FUNCTION && __PRINT_ASSERT_FUNCTION
  fprintf (stderr,"SingleProcessorMPI '%s'.\n",__ASSERT_FUNCTION);
#endif
  memcpy (buf2, buf, SizeofMPIDatatype (type) * count);
  return 0;
}

int MPI_Allgather (void* buf, int count, MPI_Datatype type, void* buf2, int count2,
		   MPI_Datatype type2, MPI_Comm comm)
{
#if defined __ASSERT_FUNCTION && __PRINT_ASSERT_FUNCTION
  fprintf (stderr,"SingleProcessorMPI '%s'.\n",__ASSERT_FUNCTION);
#endif
  memcpy (buf2, buf, SizeofMPIDatatype (type) * count);
  return 0;
}

int MPI_Reduce (void* buf, void* buf2, int count, MPI_Datatype type,
		MPI_Op op, int count2, MPI_Comm comm)
{
#if defined __ASSERT_FUNCTION && __PRINT_ASSERT_FUNCTION
  fprintf (stderr,"SingleProcessorMPI '%s'.\n",__ASSERT_FUNCTION);
#endif
  memcpy (buf2, buf, SizeofMPIDatatype (type) * count);
  return 0;
}

int MPI_Allreduce (void* buf, void* buf2, int count, MPI_Datatype type,
		   MPI_Op op, MPI_Comm comm)
{
#if defined __ASSERT_FUNCTION && __PRINT_ASSERT_FUNCTION
  fprintf (stderr,"SingleProcessorMPI '%s'.\n",__ASSERT_FUNCTION);
#endif
  memcpy (buf2, buf, SizeofMPIDatatype (type) * count);
  return 0;
}

int MPI_Alltoall(void *sendbuf, int sendcount, MPI_Datatype sendtype,
    void *recvbuf, int recvcnt, MPI_Datatype recvtype,
    MPI_Comm comm)
{

  return 0;
}
