## process this file with automake to produce Makefile.in

SHELL	= /bin/sh
@SET_MAKE@
ACLOCAL_AMFLAGS = -I m4
SUBDIRS	= src pmpi tests
bin_SCRIPTS = bin/mpicc bin/mpiCC bin/mpiexec
man1_MANS = man/mpicc.1 man/mpiCC.1 man/mpicxx.1 man/mpiexec.1 man/mpirun.1
man3_MANS = man/MPI_Init.3
EXTRA_DIST = bin/mpicc.in bin/mpiCC.in bin/mpiexec.in \
	     m4/ax_prefix_config_h.m4 m4/ac_c_var_func.m4 \
	     man/mpicc.1.in man/mpiCC.1.in man/mpicxx.1 \
	     man/mpiexec.1.in man/mpirun.1 man/MPI_Init.3
DISTCLEANFILES = _configs.sed src/nullmpi_conf.h
CVS2CL = touch ChangeLog && cvs2cl
CVS2CLFLAGS = --accum

install-exec-hook:
	cd $(DESTDIR)$(bindir) && \
	rm -f mpirun$(EXEEXT) && \
	$(LN_S) mpiexec$(EXEEXT) mpirun$(EXEEXT) && \
	$(LN_S) mpiCC$(EXEEXT) mpicxx$(EXEEXT)

uninstall-hook:
	rm -f $(DESTDIR)$(bindir)/mpirun$(EXEEXT) \
	      $(DESTDIR)$(bindir)/mpicxx$(EXEEXT)

dist-hook:
	-cd $(srcdir) && test -d CVS && $(CVS2CL) $(CVS2CLFLAGS)
	-cp $(srcdir)/ChangeLog $(distdir)
