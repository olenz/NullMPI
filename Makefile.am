## process this file with automake to produce Makefile.in

SHELL	= /bin/sh
@SET_MAKE@
ACLOCAL_AMFLAGS = -I m4
SUBDIRS	= src
bin_SCRIPTS = bin/mpicc bin/mpiCC bin/mpiexec
man1_MANS = man/mpicc.1 man/mpiCC.1 man/mpiexec.1 man/mpirun.1
EXTRA_DIST = bin/mpicc.in bin/mpiCC.in bin/mpiexec.in \
	     m4/ax_prefix_config_h.m4 m4/ac_c_var_func.m4 \
	     man/mpicc.1.in man/mpiCC.1.in man/mpiexec.1.in man/mpirun.1
DISTCLEANFILES = _configs.sed src/nullmpi_conf.h

install-exec-hook:
	cd $(DESTDIR)$(bindir) && \
	rm -f mpirun$(EXEEXT) && \
	$(LN_S) mpiexec$(EXEEXT) mpirun$(EXEEXT)

uninstall-hook:
	rm -f $(DESTDIR)$(bindir)/mpirun$(EXEEXT)
