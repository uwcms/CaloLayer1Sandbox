#############################################################################
# CaloLayer1 Trigger Supervisor Cell                                        #
# Nate Woods, U. Wisconsin                                                  #
#############################################################################
BUILD_HOME:=$(shell pwd)/../../../..
XDAQ_ROOT:=/opt/xdaq

include $(XDAQ_ROOT)/config/mfAutoconf.rules
include $(XDAQ_ROOT)/config/mfDefs.$(XDAQ_OS)

include $(XDAQ_ROOT)/config/mfDefs.extern_coretools
include $(XDAQ_ROOT)/config/mfDefs.coretools

-include $(BUILD_HOME)/config/Makefile.macros

CACTUS_HOME:=/opt/cactus
SWATCH_HOME:=$(CACTUS_HOME)/include/swatch

Project=cactusprojects
Package=CaloLayer1/ts/cell
PackageName=CaloLayer1TSCell

Description=Calo Layer 1 TS Cell
Summary=
Authors=Nate Woods, Tyler Ruggles
Link=

PACKAGE_VER_MAJOR=0
PACKAGE_VER_MINOR=1
PACKAGE_VER_PATCH=0

Executables=
Sources=\
	version.cc\
	Cell.cc

IncludeDirs = \
	$(BUILD_HOME)/$(Project)/$(Package)/include \
	$(CACTUS_HOME)/include \
	$(XDAQ_ROOT)/include \
	$(SWATCH_HOME)/core \
	$(SWATCH_HOME)/processor \
	$(SWATCH_HOME)/system \
	$(BUILD_HOME)/UCT2016

UserCCFlags = -g

DependentLibraryDirs = \
	$(BUILD_HOME)/$(Project)/swatchcell/framework/lib/$(XDAQ_OS)/$(XDAQ_PLATFORM) \
	$(XDAQ_ROOT)/lib \
	$(CACTUS_HOME)/lib \
	$(BUILD_HOME)/UCT2016


DependentLibraries = \
	tsframework \
	tstoolbox \
	tsajaxell \
	tsitf \
	log4cplus \
	cactus_swatch_core \
	cactus_swatch_system \
	swatchcellframework

DynamicLibrary= CaloLayer1TSCell


include $(XDAQ_ROOT)/config/Makefile.rules
include $(XDAQ_ROOT)/config/mfRPM.rules