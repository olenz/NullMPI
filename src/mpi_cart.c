/* $Id$ */
/* Topology handling */

#include "nullmpi.h"

int MPI_Cart_create(MPI_Comm comm_old, int ndims,
    int *dims, int *periods, int reorder, MPI_Comm *comm_cart)
{
  NULLMPI_STATS;
  return MPI_SUCCESS;
}

int MPI_Dims_create(int nnodes, int ndims, int dims[]);

int MPI_Graph_create(MPI_Comm comm_old, int nnodes,
    int indx[], int edges[], int reorder, MPI_Comm *comm_graph);

int MPI_Graphdims_get(MPI_Comm comm, int *nnodes, int *nedges);

int MPI_Graph_get(MPI_Comm comm, int maxindx, int maxedges,
                  int indx[], int edges[]);

int MPI_Cartdim_get(MPI_Comm comm, int *ndims)
{
  NULLMPI_STATS;
  *ndims = 1; /*FIXME*/
  return -1;
}

int MPI_Cart_get(MPI_Comm comm, int maxdims,
                 int dims[], int periods[], int coords[]);

int MPI_Cart_rank(MPI_Comm comm, int coords[], int *rank)
{
  NULLMPI_STATS;
  *rank = 0;
  return MPI_SUCCESS;
}

int MPI_Cart_coords(MPI_Comm comm, int rank, int maxdims, int coords[])
{
  int i;
  NULLMPI_STATS;
  /* FIXME: we rely on maxdims being correct here, instead of using comm.cart.dim */
  for (i=0; i<maxdims; ++i)
    coords[i] = 0;
  return MPI_SUCCESS;
}

int MPI_Graph_neighbors_count(MPI_Comm comm, int rank, int *nneighbors);

int MPI_Graph_neighbors(MPI_Comm comm, int rank,
                        int maxneighbors, int neighbors[]);

int MPI_Cart_shift(MPI_Comm comm, int direction, int displ,
                   int *source, int *dest);

int MPI_Cart_sub(MPI_Comm comm, int *remain_dims, MPI_Comm *comm_new);

int MPI_Cart_map(MPI_Comm comm_old, int ndims, int dims[], int periods[],
                 int *newrank);

int MPI_Graph_map(MPI_Comm comm_old, int nnodes,
                  int indx[], int edges[], int *newrank);
