## process this file with automake to produce Makefile.in

SHELL	= /bin/sh
@SET_MAKE@
ACLOCAL_AMFLAGS = -I m4
SUBDIRS	= src
bin_SCRIPTS = bin/mpicc bin/mpiCC bin/mpiexec
EXTRA_DIST = bin/mpicc.in bin/mpiCC.in bin/mpiexec.in m4/ac_c_var_func.m4

install-exec-hook:
	cd $(DESTDIR)$(bindir) && \
	rm -f mpirun$(EXEEXT) && \
	$(LN_S) mpiexec$(EXEEXT) mpirun$(EXEEXT)

uninstall-hook:
	rm -f $(DESTDIR)$(bindir)/mpirun$(EXEEXT)
