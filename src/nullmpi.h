/* nullmpi.h */

#include "config.h"

#if STDC_HEADERS
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
#else
# if !HAVE_MEMCPY
#  define memcpy(d, s, n) bcopy ((s), (d), (n))
# endif
#endif

#if HAVE_ASSERT_H
# include <assert.h> /* for __ASSERT_FUNCTION */
#endif

#include "mpi.h"

/* DEBUG */
/* #define __PRINT_ASSERT_FUNCTION */

