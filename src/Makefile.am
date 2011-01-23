## process this file with automake to produce Makefile.in

include_HEADERS = $(PUBLICHEADERS)
lib_LTLIBRARIES = libnullmpi.la
libnullmpi_la_SOURCES = $(PUBLICHEADERS) $(PRIVATEHEADERS) $(PRIVATESOURCES)

PUBLICHEADERS = \
	mpi.h \
	mpi_types.h \
	mpi2.h \
	nullmpi_conf.h

PRIVATEHEADERS = \
	nullmpi.h \
	ptp.h

PRIVATESOURCES = $(PRIVATEAPISOURCES) $(PRIVATEINTERNALSOURCES)

PRIVATEINTERNALSOURCES = \
	nullmpi.c \
	ptp.c

PRIVATEAPISOURCES = \
	mpi_abort.c \
	mpi_address.c \
	mpi_allgather.c \
	mpi_allgatherv.c \
	mpi_allreduce.c \
	mpi_alltoall.c \
	mpi_alltoallv.c \
	mpi_barrier.c \
	mpi_bcast.c \
	mpi_bsend.c \
	mpi_bsend_init.c \
	mpi_buffer_attach.c \
	mpi_buffer_detach.c \
	mpi_cancel.c \
	mpi_cart_coords.c \
	mpi_cart_create.c \
	mpi_cart_get.c \
	mpi_cart_map.c \
	mpi_cart_rank.c \
	mpi_cart_shift.c \
	mpi_cart_sub.c \
	mpi_cartdim_get.c \
	mpi_comm_compare.c \
	mpi_comm_create.c \
	mpi_comm_dup.c \
	mpi_comm_free.c \
	mpi_comm_group.c \
	mpi_comm_rank.c \
	mpi_comm_remote_group.c \
	mpi_comm_remote_size.c \
	mpi_comm_set_errhandler.c \
	mpi_comm_size.c \
	mpi_comm_split.c \
	mpi_comm_test_inter.c \
	mpi_error_class.c \
	mpi_error_string.c \
	mpi_finalize.c \
	mpi_gather.c \
	mpi_gatherv.c \
	mpi_get_count.c \
	mpi_get_elements.c \
	mpi_get_processor_name.c \
	mpi_get_version.c \
	mpi_graph_create.c \
	mpi_graph_get.c \
	mpi_graph_map.c \
	mpi_graph_neighbors.c \
	mpi_graph_neighbors_count.c \
	mpi_graphdims_get.c \
	mpi_group_compare.c \
	mpi_group_difference.c \
	mpi_group_excl.c \
	mpi_group_free.c \
	mpi_group_incl.c \
	mpi_group_intersection.c \
	mpi_group_range_excl.c \
	mpi_group_range_incl.c \
	mpi_group_rank.c \
	mpi_group_size.c \
	mpi_group_translate_ranks.c \
	mpi_group_union.c \
	mpi_ibsend.c \
	mpi_init.c \
	mpi_initialized.c \
	mpi_intercomm_create.c \
	mpi_intercomm_merge.c \
	mpi_iprobe.c \
	mpi_irecv.c \
	mpi_irsend.c \
	mpi_isend.c \
	mpi_issend.c \
	mpi_op_create.c \
	mpi_op_free.c \
	mpi_pack.c \
	mpi_pack_size.c \
	mpi_pcontrol.c \
	mpi_probe.c \
	mpi_recv.c \
	mpi_recv_init.c \
	mpi_reduce.c \
	mpi_reduce_scatter.c \
	mpi_request_free.c \
	mpi_rsend.c \
	mpi_rsend_init.c \
	mpi_scan.c \
	mpi_scatter.c \
	mpi_scatterv.c \
	mpi_send.c \
	mpi_send_init.c \
	mpi_sendrecv.c \
	mpi_sendrecv_replace.c \
	mpi_ssend.c \
	mpi_ssend_init.c \
	mpi_start.c \
	mpi_startall.c \
	mpi_test.c \
	mpi_test_cancelled.c \
	mpi_testall.c \
	mpi_testany.c \
	mpi_testsome.c \
	mpi_topo_test.c \
	mpi_type_commit.c \
	mpi_type_contiguous.c \
	mpi_type_count.c \
	mpi_type_free.c \
	mpi_type_indexed.c \
	mpi_type_size.c \
	mpi_type_struct.c \
	mpi_type_vector.c \
	mpi_unpack.c \
	mpi_wait.c \
	mpi_waitall.c \
	mpi_waitany.c \
	mpi_waitsome.c \
	wtime.c

#nullmpi_conf.h: config.h
#	cd $(top_builddir) && ./config.status src/config.h src/nullmpi_conf.h
