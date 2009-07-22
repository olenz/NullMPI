## process this file with automake to produce Makefile.in

ACLOCAL_AMFLAGS = -I m4
SUBDIRS	= src pmpi tests
bin_SCRIPTS = bin/mpicc bin/mpicxx bin/mpiexec
man1_MANS = man/mpicc.1 man/mpicxx.1 man/mpiexec.1 man/mpirun.1
man3_MANS = man/MPI_Init.3
EXTRA_DIST = bin/mpicc.in bin/mpicxx.in bin/mpiexec.in \
	     m4/ax_prefix_config_h.m4 m4/ac_c_var_func.m4 \
	     man/mpicc.1.in man/mpicxx.1.in \
	     man/mpiexec.1.in man/mpirun.1 man/MPI_Init.3
if CASE_SENSITIVE_FILE_SYSTEM
man1_MANS += man/mpiCC.1
man/mpiCC.1:
	echo '.so mpicxx.1' > $@
CLEANFILES = man/mpiCC.1
endif

DISTCLEANFILES = _configs.sed src/nullmpi_conf.h

install-exec-hook:
	cd "$(DESTDIR)$(bindir)" && rm -f mpirun && $(LN_S) mpiexec mpirun
if CASE_SENSITIVE_FILE_SYSTEM
	cd "$(DESTDIR)$(bindir)" && rm -f mpiCC && $(LN_S) mpicxx mpiCC
endif

uninstall-hook:
	rm -f "$(DESTDIR)$(bindir)/mpirun"
if CASE_SENSITIVE_FILE_SYSTEM
	rm -f "$(DESTDIR)$(bindir)/mpicxx"
endif

GIT = git

dist-hook:
	-cd $(srcdir) && test -d .git && ( $(GIT) --version ) >/dev/null 2>&1 && $(GIT) log > ChangeLog
	-cp $(srcdir)/ChangeLog $(distdir)
