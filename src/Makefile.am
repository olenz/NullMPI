## process this file with automake to produce Makefile.in

SHELL	= /bin/sh
include_HEADERS = $(PUBLICHEADERS)
lib_LIBRARIES = libnullmpi.a
libnullmpi_a_SOURCES = $(PUBLICHEADERS) $(PRIVATEHEADERS) $(PRIVATESOURCES)

PUBLICHEADERS = mpi.h mpi_types.h mpi2.h
PRIVATEHEADERS = nullmpi.h
PRIVATESOURCES = mpi.c mpi_coll.c mpi_comm.c mpi_ptp.c
