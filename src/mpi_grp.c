#include "nullmpi.h"

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

