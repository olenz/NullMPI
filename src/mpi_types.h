#ifndef __NULLMPI_INCLUDE_MPI_H__
# error "do not include this file directly, include mpi.h instead"
#endif

/* We're keeping the splint declarations of the types and constants
 * separate from the actual C declarations, because in the splint
 * version we absolutely want mininal implementation-specific information.
 */

#ifdef __LCLINT__

/* TODO: a lot to make it really splint-clean: */
/*@-declundef@*/
/*@-constuse@*/
/*@-typeuse@*/
/*@-exporttype@*/
/*@-exportconst@*/

/* typedefs */

/*@-fielduse@*/
typedef struct {
  int MPI_SOURCE;
  int MPI_TAG;
  int MPI_ERROR;
  /* more fields allowed here, order of above unspecified as well */
} MPI_Status;
/*@=fielduse@*/

/* opaque types
 * the application should not care about the actual type,
 * so we might as well use some splint-friendly types here
 */
typedef /*@abstract@*/ /*@mutable@*/ *MPI_Datatype;
typedef /*@abstract@*/ /*@mutable@*/ *MPI_Comm;
typedef /*@abstract@*/ /*@mutable@*/ *MPI_Group;
typedef /*@abstract@*/ /*@mutable@*/ *MPI_Op;
/* FIXME: next one should be pointer type, but this way checks are better */
typedef /*@abstract@*/ /*@immutable@*/ /*@integraltype@*/ MPI_Aint;
typedef /*@abstract@*/ /*@mutable@*/ *MPI_Errhandler;
typedef /*@abstract@*/ /*@mutable@*/ *MPI_Request;

typedef void (MPI_User_function)(void *, void *, int *, MPI_Datatype *);
#if _NULLMPI_USE_DEPRECATED_MPI1_FEATURES
typedef void (MPI_Handler_function)(MPI_Comm *, int *, ...);
typedef int (MPI_Copy_function)(MPI_Comm, int, void *, void *, void *, int *);
typedef int (MPI_Delete_function)(MPI_Comm, int, void *, void *);
#endif /* _NULLMPI_USE_DEPRECATED_MPI1_FEATURES */

/* datatypes */
/*@constant MPI_Datatype MPI_CHAR;@*/
/*@constant MPI_Datatype MPI_UNSIGNED_CHAR;@*/
/*@constant MPI_Datatype MPI_BYTE;@*/
/*@constant MPI_Datatype MPI_SHORT;@*/
/*@constant MPI_Datatype MPI_UNSIGNED_SHORT;@*/
/*@constant MPI_Datatype MPI_INT;@*/
/*@constant MPI_Datatype MPI_UNSIGNED;@*/
/*@constant MPI_Datatype MPI_LONG;@*/
/*@constant MPI_Datatype MPI_UNSIGNED_LONG;@*/
/*@constant MPI_Datatype MPI_FLOAT;@*/
/*@constant MPI_Datatype MPI_DOUBLE;@*/
/*@constant MPI_Datatype MPI_LONG_DOUBLE;@*/
/*@constant MPI_Datatype MPI_LONG_LONG_INT;@*/

/*@constant MPI_Datatype MPI_PACKED;@*/
#if _NULLMPI_USE_DEPRECATED_MPI1_FEATURES
/*@constant MPI_Datatype MPI_LB;@*/
/*@constant MPI_Datatype MPI_UB;@*/
#endif /* _NULLMPI_USE_DEPRECATED_MPI1_FEATURES */

/*@constant MPI_Datatype MPI_FLOAT_INT;@*/
/*@constant MPI_Datatype MPI_DOUBLE_INT;@*/
/*@constant MPI_Datatype MPI_LONG_INT;@*/
/*@constant MPI_Datatype MPI_SHORT_INT;@*/
/*@constant MPI_Datatype MPI_2INT;@*/
/*@constant MPI_Datatype MPI_LONG_DOUBLE_INT;@*/

/* Fortran types */
/*@constant MPI_Datatype MPI_COMPLEX;@*/
/*@constant MPI_Datatype MPI_DOUBLE_COMPLEX;@*/
/*@constant MPI_Datatype MPI_LOGICAL;@*/
/*@constant MPI_Datatype MPI_REAL;@*/
/*@constant MPI_Datatype MPI_DOUBLE_PRECISION;@*/
/*@constant MPI_Datatype MPI_INTEGER;@*/
/*@constant MPI_Datatype MPI_2INTEGER;@*/
/*@constant MPI_Datatype MPI_2COMPLEX;@*/
/*@constant MPI_Datatype MPI_2DOUBLE_COMPLEX;@*/
/*@constant MPI_Datatype MPI_2REAL;@*/
/*@constant MPI_Datatype MPI_2DOUBLE_PRECISION;@*/
/*@constant MPI_Datatype MPI_CHARACTER;@*/

/* communicators */
/*@constant MPI_Comm MPI_COMM_WORLD;@*/
/*@constant MPI_Comm MPI_COMM_SELF;@*/

/* groups */
/*@constant MPI_Group MPI_GROUP_EMPTY;@*/

/* collective operations */
/*@constant MPI_Op MPI_MAX;@*/
/*@constant MPI_Op MPI_MIN;@*/
/*@constant MPI_Op MPI_SUM;@*/
/*@constant MPI_Op MPI_PROD;@*/
/*@constant MPI_Op MPI_LAND;@*/
/*@constant MPI_Op MPI_BAND;@*/
/*@constant MPI_Op MPI_LOR;@*/
/*@constant MPI_Op MPI_BOR;@*/
/*@constant MPI_Op MPI_LXOR;@*/
/*@constant MPI_Op MPI_BXOR;@*/
/*@constant MPI_Op MPI_MINLOC;@*/
/*@constant MPI_Op MPI_MAXLOC;@*/

/* permanent key values */
/* The actual types of these can be different depending on the
 * implementation, but since the user should not depend on them,
 * we should be ok here.
 */
/*@constant int MPI_TAG_UB;@*/
/*@constant int MPI_HOST;@*/
/*@constant int MPI_IO;@*/
/*@constant int MPI_WTIME_IS_GLOBAL;@*/

/*@constant int MPI_MAX_PROCESSOR_NAME;@*/
/*@constant int MPI_MAX_ERROR_STRING;@*/
/*@constant int MPI_MAX_NAME_STRING;@*/

/* pre-defined constants */
/*@constant int MPI_UNDEFINED;@*/
/*@constant int MPI_UNDEFINED_RANK;@*/
/*@constant int MPI_KEYVAL_INVALID;@*/

/* upper bound on the overhead in bsend for each message buffer */
/*@constant int MPI_BSEND_OVERHEAD;@*/

/* topology types */
/*@constant int MPI_GRAPH;@*/
/*@constant int MPI_CART;@*/

/* various */
/*@constant void *MPI_BOTTOM;@*/

/*@constant int MPI_PROC_NULL;@*/
/*@constant int MPI_ANY_SOURCE;@*/
/*@constant int MPI_ANY_TAG;@*/

/* MPI_STATUS_SIZE is not strictly required in C; however, it should match
   the value for Fortran */
/*@constant int MPI_STATUS_SIZE;@*/

/* MPI error handlers */
/*@constant MPI_Errhandler MPI_ERRORS_ARE_FATAL;@*/
/*@constant MPI_Errhandler MPI_ERRORS_RETURN;@*/
/*@constant MPI_Errhandler MPIR_ERRORS_WARN;@*/    /*FIXME*/

#if _NULLMPI_USE_DEPRECATED_MPI1_FEATURES
/*@constant null MPI_Copy_function MPI_NULL_COPY_FN;@*/
/*@constant null MPI_Delete_function MPI_NULL_DELETE_FN;@*/
/*@constant null MPI_Copy_function MPI_NULL_DUP_FN;@*/
#endif /* _NULLMPI_USE_DEPRECATED_MPI1_FEATURES */

/* define some null objects */
/*@constant null MPI_Comm MPI_COMM_NULL;@*/
/*@constant null MPI_Op MPI_OP_NULL;@*/
/*@constant null MPI_Group MPI_GROUP_NULL;@*/
/*@constant null MPI_Datatype MPI_DATATYPE_NULL;@*/
/*@constant null MPI_Request MPI_REQUEST_NULL;@*/
/*@constant null MPI_Errhandler MPI_ERRHANDLER_NULL;@*/

/* MPI-1.2 */
/*@constant int MPI_VERSION;@*/
/*@constant int MPI_SUBVERSION;@*/

/* MPI's error classes */
/*@constant int MPI_SUCCESS;@*/
/*@constant int MPI_ERR_IN_STATUS;@*/
/*@constant int MPI_ERR_PENDING;@*/
/* all other ones are implementation dependent in MPI-1.2,
 * but see below for more with MPI-2
 */

/* output of MPI_Group_compare and MPI_Comm_compare */
/*@constant int MPI_IDENT;@*/
/*@constant int MPI_SIMILAR;@*/
/*@constant int MPI_UNEQUAL;@*/
/*@constant int MPI_CONGRUENT;@*/

/*@=declundef@*/
/*@=constuse@*/
/*@=typeuse@*/
/*@=exporttype@*/
/*@=exportconst@*/

#else /* ! __LCLINT__ */


/* now the real declarations used by nullmpi */

/* typedefs */
typedef enum
{
  MPI_DATATYPE_NULL,
  MPI_CHAR,
  MPI_UNSIGNED_CHAR,
  MPI_BYTE,
  MPI_SHORT,
  MPI_UNSIGNED_SHORT,
  MPI_INT,
  MPI_UNSIGNED,
  MPI_LONG,
  MPI_UNSIGNED_LONG,
  MPI_FLOAT,
  MPI_DOUBLE,
  MPI_LONG_DOUBLE,
  MPI_LONG_LONG_INT,

  MPI_PACKED,

  MPI_LB,		/* deprecated */
  MPI_UB,		/* deprecated */

  MPI_FLOAT_INT,
  MPI_DOUBLE_INT,
  MPI_LONG_INT,
  MPI_SHORT_INT,
  MPI_2INT,
  MPI_LONG_DOUBLE_INT,

  MPI_COMPLEX,
  MPI_DOUBLE_COMPLEX,
  MPI_LOGICAL,
  MPI_REAL,
  MPI_DOUBLE_PRECISION,
  MPI_INTEGER,
  MPI_2INTEGER,
  MPI_2COMPLEX,
  MPI_2DOUBLE_COMPLEX,
  MPI_2REAL,
  MPI_2DOUBLE_PRECISION,
  MPI_CHARACTER
} MPI_Datatype;

/* Communicators */
typedef enum
{
  MPI_COMM_NULL,
  MPI_COMM_WORLD,
  MPI_COMM_SELF
} MPI_Comm;

typedef enum
{
  MPI_GROUP_NULL,
  MPI_GROUP_EMPTY
} MPI_Group;

typedef enum
{
  MPI_OP_NULL,
  MPI_MAX,
  MPI_MIN,
  MPI_SUM,
  MPI_PROD,
  MPI_LAND,
  MPI_BAND,
  MPI_LOR,
  MPI_BOR,
  MPI_LXOR,
  MPI_BXOR,
  MPI_MINLOC,
  MPI_MAXLOC
} MPI_Op;

typedef void *MPI_Aint;
typedef int MPI_Errhandler;

typedef struct
{
  int MPI_SOURCE;
  int MPI_TAG;
  int MPI_ERROR;
  int count;
  int private_count;
} MPI_Status;

typedef struct
{
  int dummy;
} MPI_Request;

typedef void (MPI_User_function)(void *, void *, int *, MPI_Datatype *);
#if _NULLMPI_USE_DEPRECATED_MPI1_FEATURES
typedef void (MPI_Handler_function)(MPI_Comm *, int *, ...);
typedef int (MPI_Copy_function)(MPI_Comm, int, void *, void *, void *, int *);
typedef int (MPI_Delete_function)(MPI_Comm, int, void *, void *);
#endif /* _NULLMPI_USE_DEPRECATED_MPI1_FEATURES */


/* non-enumerated constants */

/* null types */
#define MPI_BOTTOM		(MPI_Aint)0
#define MPI_REQUEST_NULL	(MPI_Request)0
#define MPI_ERRHANDLER_NULL	(MPI_Errhandler)0
#if _NULLMPI_USE_DEPRECATED_MPI1_FEATURES
#define MPI_NULL_COPY_FN	(MPI_Copy_function)0
#define MPI_NULL_DELETE_FN	(MPI_Delete_function)0
#define MPI_NULL_DUP_FN		(MPI_Copy_function)0
#endif /* _NULLMPI_USE_DEPRECATED_MPI1_FEATURES */

/* MPI error handlers */
#define MPI_ERRORS_ARE_FATAL	(MPI_Errhandler)1
#define MPI_ERRORS_RETURN	(MPI_Errhandler)2
#define MPIR_ERRORS_WARN	(MPI_Errhandler)3	/*FIXME*/

/* permanent key values */
#define MPI_TAG_UB		9999
#define MPI_HOST		0
#define MPI_IO			0
#define MPI_WTIME_IS_GLOBAL	1

/* pre-defined constants */
#define MPI_UNDEFINED		-8
#define MPI_UNDEFINED_RANK	-9
#define MPI_KEYVAL_INVALID	-10

/* topology types */
#define MPI_GRAPH		11
#define MPI_CART		12

/* various */
#define MPI_PROC_NULL		-13
#define MPI_ANY_SOURCE		-14
#define MPI_ANY_TAG		(MPI_TAG_UB+1)

/* output of MPI_Group_compare and MPI_Comm_compare */
#define MPI_IDENT		16
#define MPI_SIMILAR		17
#define MPI_UNEQUAL		18
#define MPI_CONGRUENT		19

/* MPI's error classes */
/* Error types.  If we were mean we would define MPI_SUCCESS to != 0 here. */
#define MPI_SUCCESS		0
#define MPI_ERR_IN_STATUS	1
#define MPI_ERR_PENDING		2

/* Miscellany */
#define MPI_MAX_PROCESSOR_NAME	256
#define MPI_MAX_ERROR_STRING    256
#define MPI_MAX_NAME_STRING     256

#define MPI_BSEND_OVERHEAD	66
#define MPI_STATUS_SIZE		987

/* MPI-1.2 */
#define MPI_VERSION		1
#define MPI_SUBVERSION		2

#endif /* !__LCLINT__ */
