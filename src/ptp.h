#ifndef PTP_H
#define PTP_H

#define ISRECV 0
#define ISSEND 1

struct ptplist;
typedef struct ptplist ptplist;

/*@null@*/ /*@only@*/ ptplist *
nullmpi_queue_ptp(/*@dependent@*/ void *buf, size_t size, int tag, MPI_Comm comm, int issend);

int
nullmpi_blockptp(/*@dependent@*/ void *buf, int count, MPI_Datatype type, int tag,
    MPI_Comm comm, MPI_Status *status, int issend);

int
nullmpi_waithandle(int count, MPI_Request *requests, int *completed, MPI_Status *status);

#endif /* !PTP_H */
