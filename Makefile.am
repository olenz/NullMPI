## process this file with automake to produce Makefile.in

SHELL	= /bin/sh
@SET_MAKE@
SUBDIRS	= src
bin_SCRIPTS = bin/mpicc bin/mpiCC bin/mpiexec
#EXTRA_DIST = 

install-exec-hook:
	cd $(DESTDIR)$(bindir) && \
	rm -f mpirun$(EXEEXT) && \
	$(LN_S) mpiexec$(EXEEXT) mpirun$(EXEEXT)

uninstall-hook:
	rm -f $(DESTDIR)$(bindir)/mpirun$(EXEEXT)
