/*
 * mpi.h
 *
 * C Interface for the MPI Message Passing Interface Specification
 * (versions 1.2 and 2.0).
 *
 * The reference for this file is taken from the standard specifications
 * at http://www.mpi-forum.org/docs/docs.html
 * with looking at the implementation headers of
 * MPICH http://www-unix.mcs.anl.gov/mpi/mpich/ and
 * LAM http://www.lam-mpi.org/
 * and modified (annotated) to use as splint definition header.
 * Transcription by Ralf Wildenhues <Ralf.Wildenhues@gmx.de>.
 */

/*
 * In order to enable the bindings of MPI2 (not enabled by default),
 * #define _NULLMPI_USE_MPI2_FEATURES 1
 */
/*
 * If you need the MPI1 functions which have been deprecated by later
 * standards versions (they are disabled by default),
 * #define _NULLMPI_USE_DEPRECATED_MPI1_FEATURES 1
 */

#ifndef __NULLMPI_INCLUDE_MPI_H__
#define __NULLMPI_INCLUDE_MPI_H__

/* Keep C++ compilers from getting confused */
#if defined(__cplusplus)
extern "C" {
#endif

/* TODO: a lot to make it really splint-clean: */
/*@-declundef@*/
/*@-constuse@*/
/*@-fcnuse@*/
/*@-typeuse@*/
/*@-exporttype@*/
/*@-exportconst@*/
/*@-exportfcn@*/
/*@-protoparamname@*/

#include "mpi_types.h"

/* C bindings */
extern int MPI_Send(void *buf, int count, MPI_Datatype datatype,
    int dest, int tag, MPI_Comm comm)
    /*@globals internalState@*/
    /*@modifies internalState@*/
    /*@requires maxRead(buf) >= (count-1)@*/ ;

extern int MPI_Recv(/*@out@*/ void *buf, int count, MPI_Datatype datatype,
    int source, int tag , MPI_Comm comm, /*@out@*/ MPI_Status *status)
    /*@modifies buf, status@*/
    /*@requires maxSet(buf) >= (count-1)@*/
    /*@ensures maxRead(buf) == (count-1)@*/ ;

extern int MPI_Get_count(MPI_Status *status, MPI_Datatype datatype,
    /*@out@*/ int *count)
    /*@modifies count@*/
    /*@requires maxSet(count) >= 1@*/ ;

extern int MPI_Bsend(void *buf, int count, MPI_Datatype datatype,
    int dest, int tag, MPI_Comm comm)
    /*@requires maxRead(buf) >= (count - 1)@*/ ;

extern int MPI_Ssend(void *buf, int count, MPI_Datatype datatype,
    int dest, int tag, MPI_Comm comm)
    /*@requires maxRead(buf) >= (count-1)@*/ ;

extern int MPI_Rsend(void *buf, int count, MPI_Datatype datatype,
    int dest, int tag, MPI_Comm comm)
    /*@requires maxRead(buf) >= (count-1)@*/ ;

extern int MPI_Buffer_attach(/*@out@*/ void *buf, int size)
    /*@modifies buf@*/
    /*@requires size >= MPI_BSEND_OVERHEAD /\ maxSet(buf) >= size@*/;

extern int MPI_Buffer_detach(/*@out@*/ void *buf, /*@out@*/ int *size);

extern int MPI_Isend(void *buf, int count, MPI_Datatype datatype,
    int dest, int tag, MPI_Comm comm, /*@out@*/ MPI_Request *request)
    /*@modifies request@*/
    /*@requires maxRead(buf) >= (count-1)@*/ ;

extern int MPI_Ibsend(void *buf, int count, MPI_Datatype datatype,
    int dest, int tag, MPI_Comm comm, /*@out@*/ MPI_Request *request)
    /*@modifies request@*/
    /*@requires maxRead(buf) >= (count-1)@*/ ;

extern int MPI_Issend(void *buf, int count, MPI_Datatype datatype,
    int dest, int tag, MPI_Comm comm, /*@out@*/ MPI_Request *request)
    /*@modifies request@*/
    /*@requires maxRead(buf) >= (count-1)@*/ ;

extern int MPI_Irsend(void *buf, int count, MPI_Datatype datatype,
    int dest, int tag, MPI_Comm comm, /*@out@*/ MPI_Request *request)
    /*@modifies request@*/
    /*@requires maxRead(buf) >= (count-1)@*/  ;

extern int MPI_Irecv(/*@out@*/ void *buf, int count, MPI_Datatype datatype,
    int dest, int tag, MPI_Comm comm, /*@out@*/ MPI_Request *request)
    /*@modifies buf, request@*/
    /*@requires maxSet(buf) >= (count-1)@*/
    /*@ensures maxRead(buf) == (count-1)@*/ ;

extern int MPI_Wait(MPI_Request *request, /*@out@*/ MPI_Status *status)
    /*@modifies status@*/ ;

extern int MPI_Test(MPI_Request *request,
    /*@out@*/ int *flag, /*@out@*/ MPI_Status *status)
    /*@modifies flag, status@*/ ;

extern int MPI_Request_free(MPI_Request *request)
    /*@modifies request@*/ ;

extern int MPI_Waitany(int count, MPI_Request array_of_requests[],
    /*@out@*/ int *indx, /*@out@*/ MPI_Status *status)
    /*@modifies indx, status@*/
    /*@requires maxRead(array_of_requests) >= (count-1)@*/ ;

extern int MPI_Testany(int count, MPI_Request array_of_requests[],
    /*@out@*/ int *indx, /*@out@*/ int *flag, /*@out@*/ MPI_Status *status)
    /*@modifies indx, flag, status@*/
    /*@requires maxRead(array_of_requests) >= (count-1)@*/ ;

extern int MPI_Waitall(int count, MPI_Request array_of_requests[],
    /*@out@*/ MPI_Status array_of_statuses[])
    /*@modifies array_of_statuses@*/
    /*@requires maxRead(array_of_requests) >= (count-1)@*/
    /*@ensures maxRead(array_of_statuses) == (count-1)@*/ ;

extern int MPI_Testall(int count, MPI_Request array_of_requests[],
    /*@out@*/ int *flag, /*@out@*/ MPI_Status array_of_statuses[])
    /*@modifies flag, array_of_statuses@*/
    /*@requires maxRead(array_of_requests) >= (count-1)@*/
    /*@ensures maxRead(array_of_statuses) == (count-1)@*/ ;

extern int MPI_Waitsome(int incount, MPI_Request array_of_requests[],
    /*@out@*/ int *outcount,
    /*@out@*/ int array_of_indices[], /*@out@*/ MPI_Status array_of_statuses[])
    /*@modifies outcount, array_of_indices, array_of_statuses@*/
    /*@requires maxRead(array_of_requests) >= (incount-1)
             /\ maxSet(array_of_indices) >= (incount-1)
	     /\ maxSet(array_of_statuses) >= (incount-1)@*/
    /*@ensures maxRead(array_of_indices) == *outcount
            /\ maxRead(array_of_statuses) == *outcount@*/ ;

extern int MPI_Testsome(int incount, MPI_Request array_of_requests[],
    /*@out@*/ int *outcount,
    /*@out@*/ int array_of_indices[], /*@out@*/ MPI_Status array_of_statuses[])
    /*@requires maxRead(array_of_requests) >= (incount-1)
             /\ maxSet(array_of_indices) >= (incount-1)
	     /\ maxSet(array_of_statuses) >= (incount-1)@*/
    /*@ensures maxRead(array_of_indices) == *outcount
            /\ maxRead(array_of_statuses) == *outcount@*/ ;

extern int MPI_Iprobe(int source, int tag, MPI_Comm comm,
    /*@out@*/ int *flag, /*@out@*/ MPI_Status *status)
    /*@modifies flag, status@*/ ;

extern int MPI_Probe(int source, int tag, MPI_Comm comm,
    /*@out@*/ MPI_Status *status)
    /*@modifies status@*/ ;

extern int MPI_Cancel(MPI_Request *request)
    /*@modifies request@*/ ;

extern int MPI_Test_cancelled(MPI_Status *status, /*@out@*/ int *flag)
    /*@modifies flag@*/ ;

extern int MPI_Send_init(void *buf, int count, MPI_Datatype datatype,
    int dest, int tag, MPI_Comm comm, /*@out@*/ MPI_Request *request)
    /*@modifies request@*/
    /*@requires maxSet(buf) >= (count-1)@*/ ;  /* not maxRead! can write to buf later! */

extern int MPI_Bsend_init(void *buf, int count, MPI_Datatype datatype,
    int dest, int tag, MPI_Comm comm, /*@out@*/ MPI_Request *request)
    /*@modifies request@*/
    /*@requires maxSet(buf) >= (count-1)@*/ ;

extern int MPI_Ssend_init(void *buf, int count, MPI_Datatype datatype,
    int dest, int tag, MPI_Comm comm, /*@out@*/ MPI_Request *request)
    /*@modifies request@*/
    /*@requires maxSet(buf) >= (count-1)@*/ ;

extern int MPI_Rsend_init(void *buf, int count, MPI_Datatype datatype,
    int dest, int tag, MPI_Comm comm, /*@out@*/ MPI_Request *request)
    /*@modifies request@*/
    /*@requires maxSet(buf) >= (count-1)@*/ ;

extern int MPI_Recv_init(/*@out@*/ void *buf, int count, MPI_Datatype datatype,
    int source, int tag, MPI_Comm comm, /*@out@*/ MPI_Request *request)
    /*@modifies request, buf@*/
    /*@requires maxSet(buf) >= (count-1)@*/ ;

extern int MPI_Start(MPI_Request *request);

extern int MPI_Startall(int count, MPI_Request array_of_requests[])
    /*@requires maxRead(array_of_requests) >= (count-1)@*/ ;

extern int MPI_Sendrecv(void *sendbuf, int sendcount, MPI_Datatype sendtype,
    int dest, int sendtag,
    /*@out@*/ /*@unique@*/ void *recvbuf, int recvcount, MPI_Datatype recvtype,
    int source, int recvtag,
    MPI_Comm comm, /*@out@*/ MPI_Status *status)
    /*@modifies recvbuf, status@*/
    /*@requires maxRead(sendbuf) >= (sendcount-1)
             /\ maxSet(recvbuf) >= (recvcount-1)@*/
    /*@ensures maxRead(recvbuf) == (recvcount-1)@*/ ;

extern int MPI_Sendrecv_replace(void *buf, int count, MPI_Datatype datatype,
    int dest, int sendtag, int source, int recvtag,
    MPI_Comm comm, /*@out@*/ MPI_Status *status)
    /*@modifies buf, status@*/
    /*@requires maxRead(buf) >= (count-1)@*/
    /*@ensures maxRead(buf) >= (count-1)@*/ ;

extern int MPI_Type_contiguous(int count, MPI_Datatype oldtype,
    /*@out@*/ MPI_Datatype *newtype);

extern int MPI_Type_vector(int count, int blocklen, int stride,
    MPI_Datatype oldtype, /*@out@*/ MPI_Datatype *newtype);

extern int MPI_Type_indexed(int count, int blocklens[], int indices[],
    MPI_Datatype oldtype, /*@out@*/ MPI_Datatype *newtype)
    /*@requires maxRead(blocklens) >= (count-1)
             /\ maxRead(indices) >= (count-1)@*/ ;

#ifdef _NULLMPI_USE_DEPRECATED_MPI1_FEATURES
extern int MPI_Type_hindexed(int, int *, MPI_Aint *, MPI_Datatype,
    /*@out@*/ MPI_Datatype *);
extern int MPI_Type_hvector(int, int, MPI_Aint, MPI_Datatype,
    /*@out@*/ MPI_Datatype *);
extern int MPI_Type_struct(int, int *, MPI_Aint *, MPI_Datatype *,
    /*@out@*/ MPI_Datatype *);
extern int MPI_Address(void *, /*@out@*/ MPI_Aint *);

extern int MPI_Type_extent(MPI_Datatype, /*@out@*/ MPI_Aint *);
extern int MPI_Type_lb(MPI_Datatype, /*@out@*/ MPI_Aint*);
extern int MPI_Type_ub(MPI_Datatype, /*@out@*/ MPI_Aint*);
#endif /* _NULLMPI_USE_DEPRECATED_MPI1_FEATURES */

/* see mpi-20.ps. It clarifies the declaration below as correct
 * instead of the second argument being MPI_Aint *
 */
extern int MPI_Type_size(MPI_Datatype datatype, /*@out@*/ int *size)
    /*@modifies size@*/ ;

extern int MPI_Type_count(MPI_Datatype datatype, /*@out@*/ int *count)
    /*@modifies count@*/ ;

extern int MPI_Type_commit(MPI_Datatype *datatype)
    /*@globals internalState@*/
    /*@modifies internalState@*/ ;

extern int MPI_Type_free(MPI_Datatype *datatype)
    /*@globals internalState@*/
    /*@modifies internalState@*/ ;

extern int MPI_Get_elements(MPI_Status *status, MPI_Datatype datatype,
    /*@out@*/ int *count)
    /*@modifies count@*/ ;

extern int MPI_Pack(void *inbuf, int incount, MPI_Datatype datatype,
    /*@out@*/ void *outbuf, int outsize, int *position, MPI_Comm comm)
    /*@modifies position, outbuf@*/
    /*@requires maxRead(inbuf) >= (incount-1)
             /\ maxSet(outbuf) >= (outsize-1)@*/
    /*@ensures maxRead(outbuf) >= *position@*/ ;

extern int MPI_Unpack(void *inbuf, int insize, int *position,
    /*@out@*/ void *outbuf, int outcount, MPI_Datatype datatype, MPI_Comm comm)
    /*@modifies position@*/
    /*@requires maxRead(inbuf) >= (insize-1)
             /\ maxSet(outbuf) >= (outcount-1)@*/
    /*@ensures maxRead(outbuf) == (outcount-1)@*/ ;

extern int MPI_Pack_size(int incount, MPI_Datatype datatype, MPI_Comm comm,
    /*@out@*/ int *size)
    /*@modifies size@*/ ;

extern int MPI_Barrier(MPI_Comm comm)
    /*@globals internalState@*/
    /*@modifies internalState@*/ ;   /* ??? */

extern int MPI_Bcast(/*@reldef@*/ void *buf, int count, MPI_Datatype datatype,
    int root, MPI_Comm comm)
    /*@modifies buf@*/
    /*@requires maxSet(buf) >= (count-1)@*/
    /*@ensures maxRead(buf) == (count-1)@*/ ;

extern int MPI_Gather(void *sendbuf, int sendcnt, MPI_Datatype sendtype,
    /*@null@*/ /*@out@*/ void *recvbuf, int recvcnt, MPI_Datatype recvtype,
    int root, MPI_Comm comm)
    /*@modifies recvbuf@*/
    /*@requires maxRead(sendbuf) >= (sendcnt-1)@*/ ;

extern int MPI_Gatherv(void *sendbuf, int sendcnt, MPI_Datatype sendtype,
    /*@null@*/ /*@out@*/ void *recvbuf, int recvcnts[], int displs[],
    MPI_Datatype recvtype, int root, MPI_Comm comm)
    /*@modifies recvbuf@*/
    /*@requires maxRead(sendbuf) >= (sendcnt-1)@*/ ;

extern int MPI_Scatter(/*@null@*/ void *sendbuf, int sendcnt,
    MPI_Datatype sendtype,
    /*@out@*/ void *recvbuf, int recvcnt, MPI_Datatype recvtype,
    int root, MPI_Comm comm)
    /*@modifies recvbuf@*/
    /*@requires maxSet(recvbuf) >= (recvcnt-1)@*/
    /*@ensures maxRead(recvbuf) == (recvcnt-1)@*/ ;

extern int MPI_Scatterv(/*@null@*/ void *sendbuf,
    /*@null@*/ int *sendcnts, /*@null@*/ int *displs, MPI_Datatype sendtype,
    /*@out@*/ void *recvbuf, int recvcnt, MPI_Datatype recvtype,
    int root, MPI_Comm comm)
    /*@modifies recvbuf@*/
    /*@ensures maxRead(recvbuf) == (recvcnt-1)@*/ ;

extern int MPI_Allgather(void *sendbuf, int sendcount, MPI_Datatype sendtype,
    /*@out@*/ /*@unique@*/ void *recvbuf, int recvcount, MPI_Datatype recvtype,
    MPI_Comm comm)
    /*@modifies recvbuf@*/
    /*@requires maxRead(sendbuf) >= (sendcount-1)
             /\ maxSet(recvbuf) >= (recvcount-1)@*/
    /*@ensures maxRead(recvbuf) == (recvcount-1)@*/ ;

extern int MPI_Allgatherv(void *sendbuf, int sendcount, MPI_Datatype sendtype,
    /*@out@*/ /*@unique@*/ void *recvbuf, int *recvcounts, int *displs,
    MPI_Datatype recvtype, MPI_Comm comm)
    /*@modifies recvbuf@*/
    /*@requires maxRead(sendbuf) >= (sendcount-1)@*/ ;

extern int MPI_Alltoall(void *sendbuf, int sendcount, MPI_Datatype sendtype,
    /*@out@*/ void *recvbuf, int recvcnt, MPI_Datatype recvtype,
    MPI_Comm comm)
    /*@modifies recvbuf@*/ ;

extern int MPI_Alltoallv(void *sendbuf, int *sendcnts, int *sdispls,
    MPI_Datatype sendtype,
    /*@out@*/ /*@unique@*/ void *recvbuf, int *recvcnts, int *rdispls,
    MPI_Datatype recvtype, MPI_Comm comm)
    /*@modifies recvbuf@*/ ;

extern int MPI_Reduce(void *sendbuf, /*@out@*/ /*@null@*/ void *recvbuf,
    int count, MPI_Datatype datatype, MPI_Op op, int root, MPI_Comm comm)
    /*@modifies recvbuf@*/
    /*@requires maxRead(sendbuf) >= (count-1)@*/ ;

extern int MPI_Allreduce(void *sendbuf, /*@out@*/ /*@unique@*/ void *recvbuf,
    int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm)
    /*@modifies recvbuf@*/
    /*@requires maxRead(sendbuf) >= (count-1)
             /\ maxSet(recvbuf) >= (count-1)@*/
    /*@ensures maxRead(recvbuf) == (count-1)@*/ ;

extern int MPI_Reduce_scatter(void *sendbuf, /*@out@*/ void *recvbuf,
    int *recvcnts, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm)
    /*@modifies recvbuf@*/ ;

extern int MPI_Scan(void *sendbuf, /*@out@*/ void *recvbuf,
    int count, MPI_Datatype datatype, MPI_Op op, MPI_Comm comm)
    /*@modifies recvbuf@*/
    /*@requires maxRead(sendbuf) >= (count-1)
             /\ maxSet(recvbuf) >= (count-1)@*/
    /*@ensures maxRead(recvbuf) == (count-1)@*/ ;

extern int MPI_Op_create(MPI_User_function *function, int commute,
    /*@out@*/ MPI_Op *op)
    /*@modifies op@*/ ;

extern int MPI_Op_free(MPI_Op *op);

extern int MPI_Group_size(MPI_Group group, /*@out@*/ int *size)
    /*@modifies size@*/ ;

extern int MPI_Group_rank(MPI_Group group, /*@out@*/ int *rank)
    /*@modifies rank@*/ ;

extern int MPI_Group_translate_ranks(MPI_Group group_a, int n, int *ranks_a,
    MPI_Group group_b, /*@out@*/ int *ranks_b)
    /*@modifies ranks_b@*/ ;

extern int MPI_Group_compare(MPI_Group group1, MPI_Group group2,
    /*@out@*/ int *res)
    /*@modifies res@*/ ;

extern int MPI_Comm_group(MPI_Comm comm, /*@out@*/ MPI_Group *group)
    /*@modifies group@*/ ;

extern int MPI_Group_union(MPI_Group group1, MPI_Group group2,
    /*@out@*/ MPI_Group *newgroup)
    /*@modifies newgroup@*/ ;

extern int MPI_Group_intersection(MPI_Group group1, MPI_Group group2,
    /*@out@*/ MPI_Group *newgroup)
    /*@modifies newgroup@*/ ;

extern int MPI_Group_difference(MPI_Group group1, MPI_Group group2,
    /*@out@*/ MPI_Group *newgroup)
    /*@modifies newgroup@*/ ;

extern int MPI_Group_incl(MPI_Group group, int n, int *ranks,
    /*@out@*/ MPI_Group *newgroup)
    /*@modifies newgroup@*/
    /*@requires maxRead(ranks) >= (n-1)@*/ ;

extern int MPI_Group_excl(MPI_Group group, int n, int *ranks,
    /*@out@*/ MPI_Group *newgroup)
    /*@modifies newgroup@*/
    /*@requires maxRead(ranks) >= (n-1)@*/ ;

extern int MPI_Group_range_incl(MPI_Group group, int n, int ranges[][3],
    /*@out@*/ MPI_Group *newgroup)
    /*@modifies newgroup@*/
    /*@requires maxRead(ranges) >= (n-1)@*/ ;

extern int MPI_Group_range_excl(MPI_Group group, int n, int ranges[][3],
    /*@out@*/ MPI_Group *newgroup)
    /*@modifies newgroup@*/
    /*@requires maxRead(ranges) >= (n-1)@*/;

extern int MPI_Group_free(MPI_Group *group)
    /*@modifies group@*/ ;

extern int MPI_Comm_size(MPI_Comm comm, /*@out@*/ int *size)
    /*@modifies size@*/ ;

extern int MPI_Comm_rank(MPI_Comm comm, /*@out@*/ int *rank)
    /*@modifies rank@*/ ;

extern int MPI_Comm_compare(MPI_Comm comm1, MPI_Comm comm2, /*@out@*/ int *res)
    /*@modifies res@*/ ;

extern int MPI_Comm_dup(MPI_Comm comm, /*@out@*/ MPI_Comm *newcomm)
    /*@modifies newcomm@*/ ;

extern int MPI_Comm_create(MPI_Comm comm, MPI_Group group,
    /*@out@*/ MPI_Comm *comm_out)
    /*@modifies comm_out@*/ ;

extern int MPI_Comm_split(MPI_Comm comm, int color, int key,
    /*@out@*/ MPI_Comm *comm_out)
    /*@modifies comm_out@*/ ;

extern int MPI_Comm_free(MPI_Comm *comm)
    /*@modifies comm@*/ ;

extern int MPI_Comm_test_inter(MPI_Comm comm, /*@out@*/ int *flag)
    /*@modifies flag@*/ ;

extern int MPI_Comm_remote_size(MPI_Comm comm, /*@out@*/ int *size)
    /*@modifies size@*/ ;

extern int MPI_Comm_remote_group(MPI_Comm comm, /*@out@*/ MPI_Group *group)
    /*@modifies group@*/ ;

extern int MPI_Intercomm_create(MPI_Comm local_comm, int local_leader,
    MPI_Comm peer_comm, int remote_leader, int tag,
    /*@out@*/ MPI_Comm *comm_out)
    /*@modifies comm_out@*/ ;

extern int MPI_Intercomm_merge(MPI_Comm comm, int high,
    /*@out@*/ MPI_Comm *comm_out)
    /*@modifies comm_out@*/ ;

extern int MPI_Topo_test(MPI_Comm comm, /*@out@*/ int *type)
    /*@modifies type@*/ ;

extern int MPI_Cart_create(MPI_Comm comm_old, int ndims,
    int *dims, int *periods, int reorder, /*@out@*/ MPI_Comm *comm_cart)
    /*@modifies comm_cart@*/
    /*@requires maxRead(dims) >= (ndims-1)
             /\ maxRead(periods) >= (ndims-1)@*/ ;

extern int MPI_Dims_create(int nnodes, int ndims, /*@out@*/ int dims[])
    /*@modifies dims@*/
    /*@requires maxSet(dims) >= (ndims-1)@*/ ;

extern int MPI_Graph_create(MPI_Comm comm_old, int nnodes,
    int indx[], int edges[], int reorder, /*@out@*/ MPI_Comm *comm_graph)
    /*@modifies comm_graph@*/
    /*@requires maxRead(indx) >= (nnodes-1)@*/ ;

extern int MPI_Graphdims_get(MPI_Comm comm,
    /*@out@*/ int *nnodes, /*@out@*/ int *nedges)
    /*@modifies nnodes, nedges@*/ ;

extern int MPI_Graph_get(MPI_Comm comm, int maxindx, int maxedges,
    /*@out@*/ int indx[], /*@out@*/ int edges[])
    /*@modifies indx, edges@*/
    /*@requires maxSet(indx) >= (maxindx-1)
             /\ maxSet(edges) >= (maxedges-1)@*/
    /*@ensures maxRead(indx) == (maxindx-1)
            /\ maxRead(edges) == (maxedges-1)@*/ ;

extern int MPI_Cartdim_get(MPI_Comm comm, /*@out@*/ int *ndims)
    /*@modifies ndims@*/ ;

extern int MPI_Cart_get(MPI_Comm comm, int maxdims,
    /*@out@*/ int dims[], /*@out@*/ int periods[], /*@out@*/ int coords[])
    /*@modifies dims, periods, coords@*/
    /*@requires maxSet(dims) >= (maxdims-1)
             /\ maxSet(periods) >= (maxdims-1)
	     /\ maxSet(coords) >= (maxdims-1)@*/ ;

extern int MPI_Cart_rank(MPI_Comm comm, int coords[], /*@out@*/ int *rank)
    /*@modifies rank@*/ ;

extern int MPI_Cart_coords(MPI_Comm comm, int rank, int maxdims,
    /*@out@*/ int coords[])
    /*@modifies coords@*/
    /*@requires maxSet(coords) >= (maxdims-1)@*/
    /*@ensures maxRead(coords) == (maxdims-1)@*/ ;

extern int MPI_Graph_neighbors_count(MPI_Comm comm, int rank,
    /*@out@*/ int *nneighbors)
    /*@modifies nneighbors@*/ ;

extern int MPI_Graph_neighbors(MPI_Comm comm, int rank,
    int maxneighbors, /*@out@*/ int neighbors[])
    /*@modifies neighbors@*/
    /*@requires maxSet(neighbors) >= (maxneighbors-1)@*/
    /*@ensures maxRead(neighbors) == (maxneighbors-1)@*/ ;

extern int MPI_Cart_shift(MPI_Comm comm, int direction, int displ,
    /*@out@*/ int *source, /*@out@*/ int *dest)
    /*@modifies source, dest@*/ ;

extern int MPI_Cart_sub(MPI_Comm comm, int *remain_dims,
    /*@out@*/ MPI_Comm *comm_new)
    /*@modifies comm_new@*/ ;

extern int MPI_Cart_map(MPI_Comm comm_old, int ndims, int dims[], int periods[],
    /*@out@*/ int *newrank)
    /*@modifies newrank@*/
    /*@requires maxRead(dims) >= (ndims-1) 
             /\ maxRead(periods) >= (ndims-1)@*/ ;

extern int MPI_Graph_map(MPI_Comm comm_old, int nnodes,
    int indx[], int edges[], /*@out@*/ int *newrank)
    /*@modifies newrank@*/
    /*@requires maxRead(indx) >= (nnodes-1)@*/ ;

extern int MPI_Get_processor_name(/*@out@*/ char *name, /*@out@*/ int *resultlen)
    /*@modifies name, resultlen@*/
    /*:requires maxSet(name) >= (MPI_MAX_PROCESSOR_NAME-1):*/
    /*@ensures maxRead(name) == (resultlen-1)@*/ ;

#ifdef _NULLMPI_USE_DEPRECATED_MPI1_FEATURES

extern int MPI_Keyval_create(MPI_Copy_function *, MPI_Delete_function *,
    /*@out@*/ int *, void *);
extern int MPI_Keyval_free(int *);

extern int MPI_Attr_put(MPI_Comm, int, void *);
extern int MPI_Attr_get(MPI_Comm, int, /*@out@*/ void *, /*@out@*/ int *);
extern int MPI_Attr_delete(MPI_Comm, int);


/* MPI-1.2 */

extern int MPI_Errhandler_create(MPI_Handler_function *,
    /*@out@*/ /*@only@*/ MPI_Errhandler *);
extern int MPI_Errhandler_set(MPI_Comm, MPI_Errhandler);
extern int MPI_Errhandler_get(MPI_Comm, /*@out@*/ MPI_Errhandler *);
extern int MPI_Errhandler_free(/*@only@*/ MPI_Errhandler *);

#endif /* _NULLMPI_USE_DEPRECATED_MPI1_FEATURES */

extern int MPI_Get_version(/*@out@*/ int *version, /*@out@*/ int *subversion)
    /*@modifies version, subversion@*/ ;

extern int MPI_Error_string(int errorcode,
    /*@out@*/ char *errstring, /*@out@*/ int *resultlen)
    /*@modifies errstring@*/
    /*:requires maxSet(errstring) >= (MPI_MAX_ERROR_STRING-1):*/
    /*@ensures maxRead(errstring) >= *resultlen@*/ ;

extern int MPI_Error_class(int errorcode, /*@out@*/ int *errorclass)
    /*@modifies errorclass@*/ ;

extern double MPI_Wtime(void) /*@*/ ;
extern double MPI_Wtick(void) /*@*/ ;


/* MPI_Init and MPI_Finalize should be called in a complete MPI program,
 * everything else is optional.
 */
/*@=fcnuse@*/

#ifdef _NULLMPI_USE_MPI2_FEATURES

/* MPI2 allows passing NULL instead of argv, argc
 * in order to allow libraries to do independent initialization
 */
extern int MPI_Init(/*@null@*/ int *argc, /*@null@*/ char ***argv)
  /*@globals internalState@*/
  /*@modifies internalState, *argc, *argv@*/ ;

#include "mpi2.h"

#else /* !_NULLMPI_USE_MPI2_FEATURES */

extern int MPI_Init(int *argc, char ***argv)
  /*@globals internalState@*/
  /*@modifies internalState, *argc, *argv@*/ ;

#endif /* !_NULLMPI_USE_MPI2_FEATURES */

extern int MPI_Finalize(void)
  /*@globals internalState@*/
  /*@modifies internalState@*/ ;

/*@-fcnuse@*/

extern int MPI_Initialized(/*@out@*/ int *);
/*@exits@*/ int MPI_Abort(MPI_Comm, int);

extern int MPI_Pcontrol(const int, ...);


/*@=declundef@*/
/*@=constuse@*/
/*@=fcnuse@*/
/*@=typeuse@*/
/*@=exporttype@*/
/*@=exportconst@*/
/*@=exportfcn@*/
/*@=protoparamname@*/

#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif /* ! __NULLMPI_INCLUDE_MPI_H__ */
