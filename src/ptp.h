#ifndef PTP_H
#define PTP_H

#define ISRECV 0
#define ISSEND 1

struct ptplist;
typedef struct ptplist ptplist;

/*@null@*/ /*@dependent@*/ ptplist *
nullmpi_append_ptp(ptplist *list, /*@null@*/ /*@only@*/ ptplist *r);

ptplist *
nullmpi_remove_ptp(ptplist *r);

/*@null@*/ /*@dependent@*/ ptplist *
nullmpi_find_ptp(ptplist *list, const ptplist *request);

int
nullmpi_process_ptp(/*@null@*/ ptplist *send, /*@null@*/ ptplist *recv);

void
nullmpi_ptp(/*@out@*/ ptplist *r, void *buf, size_t size, int tag, int comm, int issend);

/*@null@*/ /*@only@*/ ptplist *
nullmpi_new_ptp(void *buf, size_t size, int tag, int comm, int issend);

void nullmpi_delete_ptp(/*@null@*/ /*@out@*/ /*@only@*/ ptplist *r);

/*@null@*/ /*@dependent@*/ ptplist *
nullmpi_queue_ptp(void *buf, size_t size, int tag, int comm, int issend);

int
nullmpi_blockptp(void *buf, int count, MPI_Datatype type, int tag,
    MPI_Comm comm, MPI_Status *status, int issend);
int
nullmpi_waithandle(int count, MPI_Request *requests, int *completed, MPI_Status *status);

#endif /* !PTP_H */
