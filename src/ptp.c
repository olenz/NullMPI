#include "nullmpi.h"
#include "ptp.h"

/*@access MPI_Comm@*/
/*@access MPI_Request@*/

struct ptplist {
  /*@null@*/ /*@dependent@*/ ptplist *next;
  /*@null@*/ /*@dependent@*/ ptplist *prev;
  /*@dependent@*/ void *buf;
  size_t size;
  int tag;
  MPI_Comm comm;
  int done;
  int issend;
};

static ptplist sendlist[1] = { { sendlist, sendlist, NULL, 0, 0, MPI_COMM_NULL, 0, 0 } };
static ptplist recvlist[1] = { { recvlist, recvlist, NULL, 0, 0, MPI_COMM_NULL, 0, 0 } };

static void
nullmpi_append_ptp(/*@dependent@*/ ptplist *list, /*@null@*/ /*@dependent@*/ ptplist *r)
  /*@requires notnull list->next, list->prev@*/
{
  if (r) {
    nullmpi_assert(r->next == NULL);
    nullmpi_assert(r->prev == NULL);
    r->next = list;
    r->prev = list->prev;
    list->prev->next = r;
    list->prev = r;
  }
}

static void
nullmpi_dequeue_ptp(ptplist *r)
{
  nullmpi_assert(r != NULL);
  nullmpi_assert(r->next != NULL);
  nullmpi_assert(r->prev != NULL);
  r->prev->next = r->next;
  r->next->prev = r->prev;
  r->next = NULL;
  r->prev = NULL;
}

static int
request_match(const ptplist *r1, const ptplist *r2)
{
  if (r1->done == r2->done &&
      r1->comm == r2->comm &&
      (r1->tag == MPI_ANY_TAG || r2->tag == MPI_ANY_TAG || r1->tag == r2->tag))
    return 1;
  else
    return 0;
}

static /*@null@*/ /*@dependent@*/ ptplist *
nullmpi_find_ptp(ptplist *list, const ptplist *request)
{
  ptplist *l;
  for (l = list->next; l != list; l = l->next) {
    nullmpi_assert(l != NULL);
    nullmpi_assert(!l->done);
    if (request_match(l, request))
      break;
  }
  return l == list ? NULL : l;
}

static int
nullmpi_process_ptp(/*@null@*/ ptplist *send, /*@null@*/ ptplist *recv)
{
  if (send && recv) {
    nullmpi_assert( send->issend);
    nullmpi_assert(!recv->issend);
    nullmpi_assert(request_match(send, recv));
    nullmpi_assert(send->size <= recv->size);
    memcpy(recv->buf, send->buf, send->size);
    send->done = 1;
    recv->done = 1;
  }
  return 0;
}

static void
nullmpi_ptp(/*@out@*/ ptplist *r, /*@dependent@*/ void *buf, size_t size,
    int tag, MPI_Comm comm, int issend)
{
  nullmpi_assert(buf != NULL);
  nullmpi_assert(tag >= 0 && (tag <= MPI_TAG_UB || tag == MPI_ANY_TAG));
  r->next = NULL;
  r->prev = NULL;
  r->buf = buf;
  r->size = size;
  r->tag = tag;
  r->comm = comm;
  r->done = 0;
  r->issend = issend;
}

static /*@null@*/ /*@only@*/ ptplist *
nullmpi_new_ptp(/*@dependent@*/ void *buf, size_t size, int tag, MPI_Comm comm, int issend)
{
  ptplist *r = (ptplist*) malloc(sizeof *r);
  if (r)
    nullmpi_ptp(r, buf, size, tag, comm, issend);
  return r;
}

/*@null@*/ /*@only@*/ ptplist *
nullmpi_queue_ptp(/*@dependent@*/ void *buf, size_t size, int tag, MPI_Comm comm, int issend)
{
  ptplist *other;
  ptplist *r = nullmpi_new_ptp(buf, size, tag, comm, issend);
  if (r) {
    switch (issend) {
    case ISSEND:
      if ((other = nullmpi_find_ptp(recvlist, r))) {
	if (!nullmpi_process_ptp(r, other))
	  nullmpi_dequeue_ptp(other);
      } else
	nullmpi_append_ptp(sendlist, r);
      break;
    case ISRECV:
      if ((other = nullmpi_find_ptp(sendlist, r))) {
	if (!nullmpi_process_ptp(other, r))
	  nullmpi_dequeue_ptp(other);
      } else
	nullmpi_append_ptp(recvlist, r);
      break;
    default:
      /*NOTREACHED*/ ;
    }
  }
  return r;
}

static void
nullmpi_delete_ptp(/*@null@*/ /*@only@*/ ptplist *r)
{
  if (r) {
    nullmpi_assert(r->next == NULL);
    nullmpi_assert(r->prev == NULL);
    free(r);
  }
}

int
nullmpi_blockptp(void *buf, int count, MPI_Datatype type, int tag,
    MPI_Comm comm, MPI_Status *status, int issend)
{
  int err = -1;
  ptplist r;
  ptplist *other;

  nullmpi_ptp(&r, buf, nullmpi_sizeof_datatype (type) * count, tag, comm, issend);
  switch (issend) {
  case ISSEND:
    if ((other = nullmpi_find_ptp(recvlist, &r))) {
      err = nullmpi_process_ptp(&r, other);
      if (!err)
	nullmpi_dequeue_ptp(other);
    } else
      nullmpi_deadlock();
    break;
  case ISRECV:
    if ((other = nullmpi_find_ptp(sendlist, &r))) {
      err = nullmpi_process_ptp(other, &r);
      if (!err)
	nullmpi_dequeue_ptp(other);
    } else
      nullmpi_deadlock();
  }
  return err;
}

int
nullmpi_waithandle(int count, MPI_Request *requests, int *completed, MPI_Status *status)
{
  int err = MPI_SUCCESS;
  ptplist *r;
  ptplist *other;
  MPI_Request *request;

  nullmpi_assert(count == 1);
  request = requests;

  nullmpi_assert(request && *request);
  r = *request;
  if (!r->done) {
    switch (r->issend) {
    case ISSEND:
      if ((other = nullmpi_find_ptp(recvlist, r))) {
	nullmpi_assert(!other->done);
	err = nullmpi_process_ptp(r, other);
	if (!err)
	  nullmpi_dequeue_ptp(r);
      }
      break;
    case ISRECV:
      if ((other = nullmpi_find_ptp(sendlist, r))) {
	nullmpi_assert(!other->done);
	err = nullmpi_process_ptp(other, r);
	if (!err)
	  nullmpi_dequeue_ptp(r);
      }
    }
  }
  status->MPI_SOURCE = 0;
  status->MPI_TAG = r->tag;
  status->MPI_ERROR = err;
  status->size = r->size;
  if (r->done && !err) {
    nullmpi_delete_ptp(r);
    *request = MPI_REQUEST_NULL;
  }
  return err;
}
