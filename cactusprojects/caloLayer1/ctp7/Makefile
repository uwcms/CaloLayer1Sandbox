BUILD_HOME:=$(shell pwd)/../../..

include $(XDAQ_ROOT)/config/mfAutoconf.rules
include $(XDAQ_ROOT)/config/mfDefs.$(XDAQ_OS)

$(info BUILD_HOME=$(BUILD_HOME))

Project=cactusprojects
Package=caloLayer1/ctp7
ProjectName=caloLayer1CTP7

Sources =\
	testLayer1CTP7.cpp

IncludeDirs=\
	$(XDAQ_ROOT)/include

UserCFlags= -g -DLINUX -fPIC
UserCCFlags=\
	-g\
	-DLINUX

UserDynamicLinkFlags=

DependentLibraryDirs=\
	$(XDAQ_ROOT)/lib\

DependentLibraries=

LibraryDirs=\
	$(BUILD_HOME)/$(Project)/caloLayer1/lib

Libraries=

UserStaticLinkFlags=
UserExecutableLinkFlags=

#
## Compile the source files and create a shared library
#
DynamicLibrary=ctp7

StaticLibrary=ctp7

include $(XDAQ_ROOT)/config/Makefile.rules
include $(BUILD_HOME)/$(Project)/caloLayer1/Makefile.libcopy