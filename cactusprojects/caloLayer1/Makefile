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
	$(ECHO) '==> Compiling CTP7'
	if [ -d $(CTP7_HOME) ]; then cd $(CTP7_HOME); make; fi
	$(ECHO)
	$(ECHO)
	$(ECHO) '==> Compiling Trigger Supervisor'
	if [ -d $(TSCELL_HOME) ]; then cd $(TSCELL_HOME); make; fi
	$(ECHO)

clean :
	$(ECHO)
	$(ECHO) '==> Cleaning up libraries and executables'
	$(ECHO)
	rm -f lib/*
	rm -f bin/*
	#cd $(MKDEPDIR) && make clean # Removed b/c mkdep cleans as it makes
	cd $(CTP7_HOME) && make clean
	cd $(TSCELL_HOME) && make clean
