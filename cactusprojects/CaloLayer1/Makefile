RM      = rm
ECHO    = echo
SHELL   = /bin/sh

.SILENT :

all:
	mkdir -p bin
	mkdir -p lib
	$(ECHO)
	$(ECHO) '==> Compiling Dependancies (mkdep_makefile)'
	if [ -d $(MKDEPDIR) ]; then cd $(MKDEPDIR); make; fi
	$(ECHO)
	$(ECHO)
	$(ECHO) '==> Compiling Calo Layer 1'
	if [ -d $(CALOLAYER1) ]; then cd $(CALOLAYER1); make; fi
	$(ECHO)

clean :
	$(ECHO)
	$(ECHO) '==> Cleaning up libraries and executables'
	$(ECHO)
	rm -f lib/*
	rm -f bin/*
	cd MKDEPDIR && make clean
	cd CALOLAYER1 && make clean
