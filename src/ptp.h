#ifndef PTP_H
#define PTP_H

typedef enum {
  ISRECV = 0,
  ISSEND = 1
} ptp_sendrecv_tag;

struct ptplist;
typedef struct ptplist ptplist;

/*@null@*/ /*@only@*/ ptplist *
nullmpi_queue_ptp(/*@dependent@*/ void *buf, size_t size, int tag,
    MPI_Comm comm, ptp_sendrecv_tag issend);

int
nullmpi_blockptp(/*@dependent@*/ void *buf, int count, MPI_Datatype type, int tag,
    MPI_Comm comm, MPI_Status *status, ptp_sendrecv_tag issend);

int
nullmpi_waithandle(int count, MPI_Request *requests, int *completed, MPI_Status *status);

#endif /* !PTP_H */
