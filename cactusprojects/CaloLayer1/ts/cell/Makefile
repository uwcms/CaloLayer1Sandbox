BUILD_HOME:=$(shell pwd)/../../..

-include $(BUILD_HOME)/config/Makefile.macros
SWATCH_PREFIX=$(shell pwd)/../../swatch

include $(XDAQ_ROOT)/config/mfAutoconf.rules
include $(XDAQ_ROOT)/config/mfDefs.$(XDAQ_OS)

Project=cactuscore
Package=swatchcell/CaloLayer1

Sources=\
        Cell.cc\
        version.cc

IncludeDirs = \
        $(BUILD_HOME)/$(Project)/swatchcell/framework/include \
        $(CACTUS_ROOT)/include \
        $(XDAQ_ROOT)/include \
        $(SWATCH_PREFIX)/core/include \
        $(SWATCH_PREFIX)/processor/include \
        $(SWATCH_PREFIX)/system/include
        

UserCCFlags = -g 

DependentLibraryDirs = \
        $(BUILD_HOME)/$(Project)/swatchcell/framework/lib/$(XDAQ_OS)/$(XDAQ_PLATFORM) \
        $(CACTUS_ROOT)/lib \
        $(XDAQ_ROOT)/lib \
        $(SWATCH_PREFIX)/core/lib \
        $(SWATCH_PREFIX)/processor/lib \
        $(SWATCH_PREFIX)/system/lib \
        $(SWATCH_PREFIX)/amc13/lib \
        $(SWATCH_PREFIX)/mp7/lib
        

DependentLibraries = \
                tsframework \
                tstoolbox \
                tsajaxell \
                tsitf \
                log4cplus \
                cactus_swatch_core \
                cactus_swatch_system \
                cactus_swatch_amc13 \
                cactus_swatch_mp7 \
                swatchcellframework

DynamicLibrary= swatchcellCaloLayer1


include $(XDAQ_ROOT)/config/Makefile.rules
include $(XDAQ_ROOT)/config/mfRPM.rules

