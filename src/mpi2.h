

/* these are taken from mpi20-ps */

/* handles to structures */
typedef /*@abstract@*/ /*@mutable@*/ *MPI_File;
typedef /*@abstract@*/ /*@mutable@*/ *MPI_Info;
/* FIXME: check the next two */
typedef /*@abstract@*/ /*@mutable@*/ *MPI_Win;
typedef /*@abstract@*/ /*@mutable@*/ *MPI_Offset;

typedef /*@abstract@*/ /*@immutable@*/ /*@integraltype@*/ MPI_Fint;

/* user defined functions */
typedef int (MPI_Comm_copy_attr_function)(MPI_Comm oldcomm, int comm_keyval,
    void *extra_state, void *attribute_val_in,
    /*@out@*/ void *attribute_val_out, int *flag);
typedef int (MPI_Comm_delete_attr_function)(MPI_Comm comm, int comm_keyval,
    void *attribute_val, void *extra_state);
typedef void (MPI_Comm_errhandler_fn)(MPI_Comm *, int *, ...);
typedef int (MPI_Datarep_conversion_function)(void *userbuf,
    MPI_Datatype datatype, int count, void *filebuf,
    MPI_Offset position, void *extra_state);
typedef int (MPI_Datarep_extent_function)(MPI_Datatype datatype,
    MPI_Aint *file_extent, void *extra_state);
typedef void (MPI_File_errhandler_fn)(MPI_File *, int *, ...);
typedef int (MPI_Grequest_cancel_function)(void *extra_state, int complete);
typedef int (MPI_Grequest_free_function)(void *extra_state);
typedef int (MPI_Grequest_query_function)(void *extra_state,
    MPI_Status *status);
typedef int (MPI_Type_copy_attr_function)(MPI_Datatype oldtype,
    int type_keyval, void *extra_state, void *attribute_val_in,
    /*@out@*/ void *attribute_val_out, int *flag);
typedef int (MPI_Type_delete_attr_function)(MPI_Datatype type,
    int type_keyval, void *attribute_val, void *extra_state);
typedef int (MPI_Win_copy_attr_function)(MPI_Win oldwin,
    int win_keyval, void *extra_state, void *attribute_val_in,
    /*@out@*/ void *attribute_val_out, int *flag);
typedef int (MPI_Win_delete_attr_function)(MPI_Win win,
    int win_keyval, void *attribute_val, void *extra_state);
typedef void (MPI_Win_errhandler_fn)(MPI_Win *, int *, ...);

/* return codes */
/*@constant int MPI_ERR_ACCESS;@*/
/*@constant int MPI_ERR_AMODE;@*/
/*@constant int MPI_ERR_ASSERT;@*/
/*@constant int MPI_ERR_BAD_FILE;@*/
/*@constant int MPI_ERR_BASE;@*/
/*@constant int MPI_ERR_CONVERSION;@*/
/*@constant int MPI_ERR_DISP;@*/
/*@constant int MPI_ERR_DUP_DATAREP;@*/
/*@constant int MPI_ERR_FILE_EXISTS;@*/
/*@constant int MPI_ERR_FILE_IN_USE;@*/
/*@constant int MPI_ERR_FILE;@*/
/*@constant int MPI_ERR_INFO_KEY;@*/
/*@constant int MPI_ERR_INFO_NOKEY;@*/
/*@constant int MPI_ERR_INFO_VALUE;@*/
/*@constant int MPI_ERR_INFO;@*/
/*@constant int MPI_ERR_IO;@*/
/*@constant int MPI_ERR_KEYVAL;@*/
/*@constant int MPI_ERR_LOCKTYPE;@*/
/*@constant int MPI_ERR_NAME;@*/
/*@constant int MPI_ERR_NO_MEM;@*/
/*@constant int MPI_ERR_NOT_SAME;@*/
/*@constant int MPI_ERR_NO_SPACE;@*/
/*@constant int MPI_ERR_NO_SUCH_FILE;@*/
/*@constant int MPI_ERR_PORT;@*/
/*@constant int MPI_ERR_QOUTA;@*/
/*@constant int MPI_ERR_READ_ONLY;@*/
/*@constant int MPI_ERR_RMA_CONFLICT;@*/
/*@constant int MPI_ERR_RMA_SYNC;@*/
/*@constant int MPI_ERR_SERVICE;@*/
/*@constant int MPI_ERR_SIZE;@*/
/*@constant int MPI_ERR_SPAWN;@*/
/*@constant int MPI_ERR_UNSUPPORTED_DATAREP;@*/
/*@constant int MPI_ERR_UNSUPPORTED_OPERATION;@*/
/*@constant int MPI_ERR_WIN;@*/

/* assorted constants */
/*@constant void *MPI_IN_PLACE;@*/
/*@constant int MPI_LOCK_EXCLUSIVE;@*/
/*@constant int MPI_LOCK_SHARED;@*/
/*@constant int MPI_ROOT;@*/

/* maximum sizes for strings */
/*@constant int MPI_MAX_DATAREP_STRING;@*/
/*@constant int MPI_MAX_INFO_KEY;@*/
/*@constant int MPI_MAX_INFO_VAL;@*/
/*@constant int MPI_MAX_OBJECT_NAME;@*/
/*@constant int MPI_MAX_PORT_NAME;@*/

/* named predefined datatypes */
/*@constant MPI_Datatype MPI_WCHAR;@*/
/*@constant MPI_Datatype MPI_UNSIGNED_LONG_LONG;@*/
/*@constant MPI_Datatype MPI_SIGNED_CHAR;@*/

/* predefined attribute keys */
/*@constant int MPI_APPNUM;@*/
/*@constant int MPI_LASTUSEDCODE;@*/
/*@constant int MPI_UNIVERSE_SIZE;@*/
/*@constant int MPI_WIN_BASE;@*/
/*@constant int MPI_WIN_DISP_UNIT;@*/
/*@constant int MPI_WIN_SIZE;@*/

/* collective operations */
/* FIXME;
   MPI_REPLACE
*/

/* null handles */
/*@constant null MPI_File MPI_FILE_NULL;@*/
/*@constant null MPI_Info MPI_INFO_NULL;@*/
/*@constant null MPI_Win MPI_WIN_NULL;@*/
/*@constant MPI_Datarep_conversion_function MPI_CONVERSION_FN_NULL;@*/

/* mode constants */
/*@constant int MPI_MODE_APPEND;@*/
/*@constant int MPI_MODE_CREATE;@*/
/*@constant int MPI_MODE_DELETE_ON_CLOSE;@*/
/*@constant int MPI_MODE_EXCL;@*/
/*@constant int MPI_MODE_NOCHECK;@*/
/*@constant int MPI_MODE_NOPRECEDE;@*/
/*@constant int MPI_MODE_NOPUT;@*/
/*@constant int MPI_MODE_NOSTORE;@*/
/*@constant int MPI_MODE_NOSUCCEED;@*/
/*@constant int MPI_MODE_RDONLY;@*/
/*@constant int MPI_MODE_RDWR;@*/
/*@constant int MPI_MODE_SEQUENTIAL;@*/
/*@constant int MPI_MODE_UNIQUE_OPEN;@*/
/*@constant int MPI_MODE_WRONLY;@*/

/* datatype decoding constants */
/*@constant int MPI_COMBINER_CONTIGUOUS;@*/
/*@constant int MPI_COMBINER_DARRAY;@*/
/*@constant int MPI_COMBINER_DUP;@*/
/*@constant int MPI_COMBINER_F90_COMPLEX;@*/
/*@constant int MPI_COMBINER_F90_INTEGER;@*/
/*@constant int MPI_COMBINER_F90_REAL;@*/
/*@constant int MPI_COMBINER_HINDEXED_INTEGER;@*/
/*@constant int MPI_COMBINER_HINDEXED;@*/
/*@constant int MPI_COMBINER_HVECTOR_INTEGER;@*/
/*@constant int MPI_COMBINER_HVECTOR;@*/
/*@constant int MPI_COMBINER_INDEXED_BLOCK;@*/
/*@constant int MPI_COMBINER_INDEXED;@*/
/*@constant int MPI_COMBINER_NAMED;@*/
/*@constant int MPI_COMBINER_RESIZED;@*/
/*@constant int MPI_COMBINER_STRUCT_INTEGER;@*/
/*@constant int MPI_COMBINER_STRUCT;@*/
/*@constant int MPI_COMBINER_SUBARRAY;@*/
/*@constant int MPI_COMBINER_VECTOR;@*/

/* thread constants */
/*@constant int MPI_THREAD_FUNNELED;@*/
/*@constant int MPI_THREAD_MULTIPLE;@*/
/*@constant int MPI_THREAD_SERIALIZED;@*/
/*@constant int MPI_THREAD_SINGLE;@*/

/* file operations constants */
/*@constant MPI_Offset MPI_DISPLACEMENT_CURRENT;@*/
/*@constant int MPI_DISTRIBUTE_BLOCK;@*/
/*@constant int MPI_DISTRIBUTE_CYCLIC;@*/
/*@constant int MPI_DISTRIBUTE_DFLT_DARG;@*/
/*@constant int MPI_DISTRIBUTE_NONE;@*/
/*@constant int MPI_ORDER_C;@*/
/*@constant int MPI_ORDER_FORTRAN;@*/
/*@constant int MPI_SEEK_CUR;@*/
/*@constant int MPI_SEEK_END;@*/
/*@constant int MPI_SEEK_SET;@*/

/* F90 datatype matching constants */
/*@constant int MPI_TYPECLASS_COMPLEX;@*/
/*@constant int MPI_TYPECLASS_INTEGER;@*/
/*@constant int MPI_TYPECLASS_REAL;@*/

/* constants specifying empty or ignored input */
/*@constant null MPI_ARGVS_NULL;@*/
/*@constant null MPI_ARGV_NULL;@*/
/*@constant null MPI_ERRCODES_IGNORE;@*/
/*@constant null MPI_Status *MPI_STATUS_IGNORE;@*/
/*@constant null MPI_Status *MPI_STATUSES_IGNORE;@*/

/* C constants specifying ignored input */
/*@constant null MPI_Fint *MPI_F_STATUSES_IGNORE;@*/
/*@constant null MPI_Fint *MPI_F_STATUS_IGNORE;@*/


/* C bindings */

/* miscellany */
extern int MPI_Alloc_mem(MPI_Aint size, /*@null@*/ MPI_Info info,
    /*@out@*/ /*@only@*/ void *baseptr);

extern MPI_Fint MPI_Comm_c2f(MPI_Comm comm);
extern int MPI_Comm_create_errhandler(MPI_Comm_errhandler_fn *function,
    /*@out@*/ /*@only@*/ MPI_Errhandler *errhandler);
extern MPI_Comm MPI_Comm_f2c(MPI_Fint comm);

extern int MPI_Comm_get_errhandler(MPI_Comm comm,
    /*@out@*/ MPI_Errhandler *errhandler);
extern int MPI_Comm_set_errhandler(MPI_Comm comm,
    MPI_Errhandler errhandler);

extern MPI_Fint MPI_File_c2f(MPI_File file);
extern int MPI_File_create_errhandler(MPI_Comm_errhandler_fn *function,
    /*@out@*/ /*@only@*/ MPI_Errhandler *errhandler);
extern MPI_File MPI_File_f2c(MPI_Fint file);
extern int MPI_File_get_errhandler(MPI_File file,
    /*@out@*/ MPI_Errhandler *errhandler);
extern int MPI_File_set_errhandler(MPI_File file,
    MPI_Errhandler errhandler);

extern int MPI_Finalized(/*@out@*/ int *);

extern int MPI_Free_mem(/*@out@*/ /*@only@*/ void *base);

extern int MPI_Get_address(void *location, /*@out@*/ MPI_Aint *address);

extern MPI_Fint MPI_Group_c2f(MPI_Group group);
extern MPI_Group MPI_Group_f2c(MPI_Fint group);

extern MPI_Fint MPI_Info_c2f(MPI_Info);
extern int MPI_Info_create(/*@out@*/ /*@only@*/ MPI_Info *);
extern int MPI_Info_delete(MPI_Info, char *key);
extern int MPI_Info_dup(MPI_Info, /*@out@*/ MPI_Info *newinfo);
extern MPI_Info MPI_Info_f2c(MPI_Fint);
extern int MPI_Info_free(/*@only@*/ MPI_Info *info);
extern int MPI_Info_get(MPI_Info, char *key, int valuelen,
    /*@out@*/ char *value, /*@out@*/ int *flag);
extern int MPI_Info_get_nkeys(MPI_Info, /*@out@*/ int *nkeys);
extern int MPI_Info_get_nthkey(MPI_Info, int n, /*@out@*/ char *key);
extern int MPI_Info_get_valuelen(MPI_Info, char *key,
    /*@out@*/ int *valuelen, /*@out@*/ int *flag);
extern int MPI_Info_set(MPI_Info, char *key, char *value);


extern MPI_Fint MPI_Op_c2f(MPI_Op op);
extern MPI_Op MPI_Op_f2c(MPI_Fint op);

extern int MPI_Pack_external(char *datarep, void *inbuf, int incount,
    MPI_Datatype datatype, void *outbuf, MPI_Aint outsize,
    MPI_Aint *position);
extern int MPI_Pack_external_size(char *datarep, int incount,
    MPI_Datatype datatype, MPI_Aint *size);

extern MPI_Fint MPI_Request_c2f(MPI_Request);
extern MPI_Request MPI_Request_f2c(MPI_Fint);

extern int MPI_Request_get_status(MPI_Request request,
    /*@out@*/ int *flag, /*@out@*/ MPI_Status *status);

extern int MPI_Status_f2c(MPI_Fint *, /*@out@*/ MPI_Status *);
extern int MPI_Status_c2f(MPI_Status *, /*@out@*/ MPI_Fint *);


extern MPI_Fint MPI_Type_c2f(MPI_Datatype datatype);

extern int MPI_Type_create_darray(int, int, int, int *, int *, int *, int *,
    int, MPI_Datatype, /*@out@*/ MPI_Datatype *);

extern int MPI_Type_create_hindexed(int count, int array_of_blocklengths[],
    MPI_Aint array_of_displacements[], MPI_Datatype oldtype,
    /*@out@*/ MPI_Datatype *newtype);

extern int MPI_Type_create_hvector(int count, int blocklength,
    MPI_Aint stride, MPI_Datatype oldtype,
    /*@out@*/ MPI_Datatype *newtype);

extern int MPI_Type_create_indexed_block(int, int, int *, MPI_Datatype,
    /*@out@*/ MPI_Datatype *);

extern int MPI_Type_create_resized(MPI_Datatype oldtype, MPI_Aint lb,
    MPI_Aint extent, /*@out@*/ MPI_Datatype *newtype);

extern int MPI_Type_create_struct(int count, int array_of_blocklengths[],
    MPI_Aint array_of_displacements[], MPI_Datatype array_of_types[],
    /*@out@*/ MPI_Datatype *newtype);

extern int MPI_Type_create_subarray(int, int *, int *, int *, int,
    MPI_Datatype, /*@out@*/ MPI_Datatype *);

extern MPI_Datatype MPI_Type_f2c(MPI_Fint datatype);

extern int MPI_Type_get_extent(MPI_Datatype datatype, MPI_Aint *lb,
    /*@out@*/ MPI_Aint *extent);


extern int MPI_Type_get_true_extent(MPI_Datatype datatype,
    MPI_Aint *true_lb, /*@out@*/ MPI_Aint *true_extent);

extern int MPI_Unpack_external(char *datarep, void *inbuf,
    MPI_Aint insize, MPI_Aint *position, /*@out@*/ void *outbuf,
    int outcount, MPI_Datatype datatype);

extern MPI_Fint MPI_Win_c2f(MPI_Win win);

extern int MPI_Win_create_errhandler(MPI_Win_errhandler_fn *function,
    /*@out@*/ MPI_Errhandler *errhandler);
extern MPI_Win MPI_Win_f2c(MPI_Fint win);
extern int MPI_Win_get_errhandler(MPI_Win win,
    /*@out@*/ MPI_Errhandler *errhandler);
extern int MPI_Win_set_errhandler(MPI_Win win,
    MPI_Errhandler errhandler);


/* process creation and management */
extern int MPI_Close_port(char *port_name);
extern int MPI_Comm_accept(char *port_name, MPI_Info info, int root,
    MPI_Comm comm, /*@out@*/ MPI_Comm *newcomm);

extern int MPI_Comm_connect(char *port_name, MPI_Info info, int root,
    MPI_Comm comm, /*@out@*/ MPI_Comm *newcomm);
extern int MPI_Comm_disconnect(MPI_Comm *comm);

extern int MPI_Comm_get_parent(/*@out@*/ MPI_Comm *parent);
extern int MPI_Comm_join(int fd, MPI_Comm *intercomm);

extern int MPI_Comm_spawn(char *command, char *argv[], int maxprocs,
    MPI_Info info, int root, MPI_Comm comm,
    /*@out@*/ MPI_Comm *intercomm, /*@out@*/ int array_of_errcodes[]);

extern int MPI_Comm_spawn_multiple(int count, char *array_of_commands[],
    char **array_of_argv[], int array_of_maxprocs[],
    MPI_Info array_of_info[], int root, MPI_Comm comm,
    /*@out@*/ MPI_Comm *intercomm, /*@out@*/ int array_of_errcodes[]);

extern int MPI_Lookup_name(char *service_name, MPI_Info info,
    /*@out@*/ char *port_name);
extern int MPI_Open_port(MPI_Info info, /*@out@*/ char *port_name);
extern int MPI_Publish_name(char *service_name, MPI_Info info, char *port_name);
extern int MPI_Unpublish_name(char *service_name, MPI_Info info, char *port_name);


/* one sided communications */
extern int MPI_Accumulate(void *origin_addr, int origin_count,
    MPI_Datatype origin_datatype, int target_rank,
    MPI_Aint target_disp, int target_count,
    MPI_Datatype target_datatype, MPI_Op op, MPI_Win win);

extern int MPI_Get(/*@out@*/ void *origin_addr, int origin_count,
    MPI_Datatype origin_datatype, int target_rank,
    MPI_Aint target_disp, int target_count,
    MPI_Datatype target_datatype, MPI_Win win);

extern int MPI_Put(void *origin_addr, int origin_count,
    MPI_Datatype origin_datatype, int target_rank,
    MPI_Aint target_disp, int target_count,
    MPI_Datatype target_datatype, MPI_Win win);

extern int MPI_Win_complete(MPI_Win win);
extern int MPI_Win_create(void *base, MPI_Aint size, int disp_unit,
    MPI_Info info, MPI_Comm comm, /*@out@*/ MPI_Win *win);

extern int MPI_Win_fence(int assert, MPI_Win win);
extern int MPI_Win_free(MPI_Win *win);
extern int MPI_Win_get_group(MPI_Win win, /*@out@*/ MPI_Group *group);
extern int MPI_Win_lock(int lock_type, int rank, int assert, MPI_Win win);
extern int MPI_Win_post(MPI_Group group, int assert, MPI_Win win);
extern int MPI_Win_start(MPI_Group group, int assert, MPI_Win win);
extern int MPI_Win_test(MPI_Win win, /*@out@*/ int *flag);
extern int MPI_Win_unlock(int rank, MPI_Win win);
extern int MPI_Win_wait(MPI_Win win);

/* extended collective operations */
extern int MPI_Alltoallw(void *sendbuf, int sendcounts[],
    int sdispls[], MPI_Datatype sendtypes[],
    /*@out@*/ void *recvbuf, int recvcounts[], int rdispls[],
    MPI_Datatype recvtypes[], MPI_Comm comm);

extern int MPI_Exscan(void *sendbuf, /*@out@*/ void *recvbuf, int count,
    MPI_Datatype datatype, MPI_Op op, MPI_Comm comm);

/* external interfaces */
extern int MPI_Add_error_class(int *errorclass);
extern int MPI_Add_error_code(int errorclass, /*@out@*/ int *errorcode);
extern int MPI_Add_error_string(int errorcode, char *string);
extern int MPI_Comm_call_errhandler(MPI_Comm comm, int errorcode);

extern int MPI_Comm_create_keyval(MPI_Comm_copy_attr_function *comm_copy_attr_fn,
    MPI_Comm_delete_attr_function *comm_delete_attr_fn,
    /*@out@*/ int *comm_keyval, void *extra_state);

extern int MPI_Comm_delete_attr(MPI_Comm comm, int comm_keyval);
extern int MPI_Comm_free_keyval(int *comm_keyval);
extern int MPI_Comm_get_attr(MPI_Comm comm, int comm_keyval,
    /*@out@*/ void *attribute_val, /*@out@*/ int *flag);

extern int MPI_Comm_get_name(MPI_Comm comm,
    /*@out@*/ char *comm_name, /*@out@*/ int *resultlen);
extern int MPI_Comm_set_attr(MPI_Comm comm,
    int comm_keyval, void *attribute_val);
extern int MPI_Comm_set_name(MPI_Comm comm, char *comm_name);
extern int MPI_File_call_errhandler(MPI_File fh, int errorcode);

extern int MPI_Grequest_complete(MPI_Request request);

extern int MPI_Grequest_start(MPI_Grequest_query_function *query_fn,
    MPI_Grequest_free_function *free_fn,
    MPI_Grequest_cancel_function *cancel_fn,
    void *extra_state, /*@out@*/ MPI_Request *request);

extern int MPI_Init_thread(int *argc, char *((*argv)[]),
    int required, /*@out@*/ int *provided);

extern int MPI_Is_thread_main(/*@out@*/ int *flag);
extern int MPI_Query_thread(/*@out@*/ int *provided);

extern int MPI_Status_set_cancelled(MPI_Status *status, int flag);
extern int MPI_Status_set_elements(MPI_Status *status,
    MPI_Datatype datatype, int count);

extern int MPI_Type_create_keyval(MPI_Type_copy_attr_function *type_copy_attr_fn,
    MPI_Type_delete_attr_function *type_delete_attr_fn,
    /*@out@*/ int *type_keyval, void *extra_state);

extern int MPI_Type_delete_attr(MPI_Datatype type, int type_keyval);
extern int MPI_Type_dup(MPI_Datatype type, /*@out@*/ MPI_Datatype *newtype);
extern int MPI_Type_free_keyval(int *type_keyval);

extern int MPI_Type_get_attr(MPI_Datatype type, int type_keyval,
    /*@out@*/ void *attribute_val, /*@out@*/ int *flag);

extern int MPI_Type_get_contents(MPI_Datatype datatype, int max_integers,
    int max_addresses, int max_datatypes,
    /*@out@*/ int array_of_integers[],
    /*@out@*/ MPI_Aint array_of_addresses[],
    /*@out@*/ MPI_Datatype array_of_datatypes[]);

extern int MPI_Type_get_envelope(MPI_Datatype datatype,
    /*@out@*/ int *num_integers, /*@out@*/ int *num_addresses,
    /*@out@*/ int *num_datatypes, /*@out@*/ int *combiner);

extern int MPI_Type_get_name(MPI_Datatype type, char *type_name, int *resultlen);
extern int MPI_Type_set_attr(MPI_Datatype type, int type_keyval, void *attribute_val);

extern int MPI_Type_set_name(MPI_Datatype type, char *type_name);
extern int MPI_Win_call_errhandler(MPI_Win win, int errorcode);

extern int MPI_Win_create_keyval(MPI_Win_copy_attr_function *win_copy_attr_fn,
    MPI_Win_delete_attr_function *win_delete_attr_fn,
    /*@out@*/ int *win_keyval, void *extra_state);

extern int MPI_Win_delete_attr(MPI_Win win, int win_keyval);
extern int MPI_Win_free_keyval(int *win_keyval);
extern int MPI_Win_get_attr(MPI_Win win, int win_keyval,
    /*@out@*/ void *attribute_val, /*@out@*/ int *flag);

extern int MPI_Win_get_name(MPI_Win win,
    /*@out@*/ char *win_name, /*@out@*/ int *resultlen);
extern int MPI_Win_set_attr(MPI_Win win, int win_keyval, void *attribute_val);
extern int MPI_Win_set_name(MPI_Win win, char *win_name);

/* I/O */
extern int MPI_File_close(MPI_File *fh);
extern int MPI_File_delete(char *filename, MPI_Info info);
extern int MPI_File_get_amode(MPI_File fh, /*@out@*/ int *amode);
extern int MPI_File_get_atomicity(MPI_File fh, /*@out@*/ int *flag);
extern int MPI_File_get_byte_offset(MPI_File fh, MPI_Offset offset,
    /*@out@*/ MPI_Offset *disp);

extern int MPI_File_get_group(MPI_File fh, /*@out@*/ MPI_Group *group);
extern int MPI_File_get_info(MPI_File fh, /*@out@*/ MPI_Info *info_used);
extern int MPI_File_get_position(MPI_File fh, /*@out@*/ MPI_Offset *offset);
extern int MPI_File_get_position_shared(MPI_File fh, /*@out@*/ MPI_Offset *offset);
extern int MPI_File_get_size(MPI_File fh, /*@out@*/ MPI_Offset *size);
extern int MPI_File_get_type_extent(MPI_File fh, MPI_Datatype datatype,
    /*@out@*/ MPI_Aint *extent);

extern int MPI_File_get_view(MPI_File fh,
    /*@out@*/ MPI_Offset *disp, /*@out@*/ MPI_Datatype *etype,
    /*@out@*/ MPI_Datatype *filetype, /*@out@*/ char *datarep);

extern int MPI_File_iread(MPI_File fh, /*@out@*/ void *buf, int count,
    MPI_Datatype datatype, /*@out@*/ MPI_Request *request);

extern int MPI_File_iread_at(MPI_File fh, MPI_Offset offset,
    /*@out@*/ void *buf, int count, MPI_Datatype datatype,
    /*@out@*/ MPI_Request *request);

extern int MPI_File_iread_shared(MPI_File fh, void *buf, int count,
    MPI_Datatype datatype, MPI_Request *request);

extern int MPI_File_iwrite(MPI_File fh, void *buf, int count,
    MPI_Datatype datatype, /*@out@*/ MPI_Request *request);

extern int MPI_File_iwrite_at(MPI_File fh, MPI_Offset offset, void *buf,
    int count, MPI_Datatype datatype, /*@out@*/ MPI_Request *request);

extern int MPI_File_iwrite_shared(MPI_File fh, void *buf, int count,
    MPI_Datatype datatype, MPI_Request *request);

extern int MPI_File_open(MPI_Comm comm, char *filename, int amode,
    MPI_Info info, /*@out@*/ MPI_File *fh);

extern int MPI_File_preallocate(MPI_File fh, MPI_Offset size);

extern int MPI_File_read(MPI_File fh, /*@out@*/ void *buf, int count,
    MPI_Datatype datatype, /*@out@*/ MPI_Status *status);

extern int MPI_File_read_all(MPI_File fh, /*@out@*/ void *buf, int count,
    MPI_Datatype datatype, /*@out@*/ MPI_Status *status);
extern int MPI_File_read_all_begin(MPI_File fh, void *buf,
    int count, MPI_Datatype datatype);
extern int MPI_File_read_all_end(MPI_File fh, void *buf, MPI_Status *status);

extern int MPI_File_read_at(MPI_File fh, MPI_Offset offset,
    /*@out@*/ void *buf, int count, MPI_Datatype datatype,
    /*@out@*/ MPI_Status *status);

extern int MPI_File_read_at_all(MPI_File fh, MPI_Offset offset,
    /*@out@*/ void *buf, int count, MPI_Datatype datatype,
    /*@out@*/ MPI_Status *status);
extern int MPI_File_read_at_all_begin(MPI_File fh, MPI_Offset offset,
    /*@out@*/ void *buf, int count, MPI_Datatype datatype);
extern int MPI_File_read_at_all_end(MPI_File fh,
    /*@out@*/ void *buf, /*@out@*/ MPI_Status *status);

extern int MPI_File_read_ordered(MPI_File fh, /*@out@*/ void *buf, int count,
    MPI_Datatype datatype, /*@out@*/ MPI_Status *status);
extern int MPI_File_read_ordered_begin(MPI_File fh, /*@out@*/ void *buf,
    int count, MPI_Datatype datatype);
extern int MPI_File_read_ordered_end(MPI_File fh,
    /*@out@*/ void *buf, /*@out@*/ MPI_Status *status);

extern int MPI_File_read_shared(MPI_File fh, /*@out@*/ void *buf, int count,
    MPI_Datatype datatype, /*@out@*/ MPI_Status *status);

extern int MPI_File_seek(MPI_File fh, MPI_Offset offset, int whence);

extern int MPI_File_seek_shared(MPI_File fh, MPI_Offset offset, int whence);
extern int MPI_File_set_atomicity(MPI_File fh, int flag);
extern int MPI_File_set_info(MPI_File fh, MPI_Info info);
extern int MPI_File_set_size(MPI_File fh, MPI_Offset size);
extern int MPI_File_set_view(MPI_File fh, MPI_Offset disp, MPI_Datatype etype,
    MPI_Datatype filetype, char *datarep, MPI_Info info);

extern int MPI_File_sync(MPI_File fh);
extern int MPI_File_write(MPI_File fh, void *buf, int count,
    MPI_Datatype datatype, /*@out@*/ MPI_Status *status);

extern int MPI_File_write_all(MPI_File fh, void *buf, int count,
    MPI_Datatype datatype, /*@out@*/ MPI_Status *status);
extern int MPI_File_write_all_begin(MPI_File fh, void *buf,
    int count, MPI_Datatype datatype);
extern int MPI_File_write_all_end(MPI_File fh, void *buf,
    /*@out@*/ MPI_Status *status);

extern int MPI_File_write_at(MPI_File fh, MPI_Offset offset, void *buf,
    int count, MPI_Datatype datatype, /*@out@*/ MPI_Status *status);

extern int MPI_File_write_at_all(MPI_File fh, MPI_Offset offset,
    void *buf, int count, MPI_Datatype datatype, /*@out@*/ MPI_Status *status);
extern int MPI_File_write_at_all_begin(MPI_File fh, MPI_Offset offset,
    void *buf, int count, MPI_Datatype datatype);
extern int MPI_File_write_at_all_end(MPI_File fh, void *buf,
    /*@out@*/ MPI_Status *status);

extern int MPI_File_write_ordered(MPI_File fh, void *buf,
    int count, MPI_Datatype datatype, /*@out@*/ MPI_Status *status);
extern int MPI_File_write_ordered_begin(MPI_File fh, void *buf,
    int count, MPI_Datatype datatype);
extern int MPI_File_write_ordered_end(MPI_File fh, void *buf,
    /*@out@*/ MPI_Status *status);

extern int MPI_File_write_shared(MPI_File fh, void *buf,
    int count, MPI_Datatype datatype, /*@out@*/ MPI_Status *status);

extern int MPI_Register_datarep(char *datarep,
    MPI_Datarep_conversion_function *read_conversion_fn,
    MPI_Datarep_conversion_function *write_conversion_fn,
    MPI_Datarep_extent_function *dtype_file_extent_fn,
    void *extra_state);

/* language bindings */
extern int MPI_Type_create_f90_complex(int p, int r, /*@out@*/ MPI_Datatype *newtype);
extern int MPI_Type_create_f90_integer(int r, /*@out@*/ MPI_Datatype *newtype);
extern int MPI_Type_create_f90_real(int p, int r, /*@out@*/ MPI_Datatype *newtype);
extern int MPI_Type_match_size(int typeclass, int size, /*@out@*/ MPI_Datatype *type);

