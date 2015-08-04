#ifndef _swatchcell_CaloLayer1_version_h_
#define _swatchcell_CaloLayer1_version_h_

#include "config/PackageInfo.h"
// !!! Edit this line to reflect the latest package version !!!

#define SWATCHCELLCALOLAYER1_VERSION_MAJOR 0
#define SWATCHCELLCALOLAYER1_VERSION_MINOR 1
#define SWATCHCELLCALOLAYER1_VERSION_PATCH 0


//
// Template macros
//
#define SWATCHCELLCALOLAYER1_VERSION_CODE PACKAGE_VERSION_CODE(LEVEL1SWATCHCALOLAYER1_VERSION_MAJOR,LEVEL1SWATCHCALOLAYER1_VERSION_MINOR,LEVEL1SWATCHCALOLAYER1_VERSION_PATCH)
#ifndef SWATCHCELLCALOLAYER1_PREVIOUS_VERSIONS
#define SWATCHCELLCALOLAYER1_FULL_VERSION_LIST  PACKAGE_VERSION_STRING(LEVEL1SWATCHCALOLAYER1_VERSION_MAJOR,LEVEL1SWATCHCALOLAYER1_VERSION_MINOR,LEVEL1SWATCHCALOLAYER1_VERSION_PATCH)
#else
#define SWATCHCELLCALOLAYER1_FULL_VERSION_LIST  LEVEL1SWATCHCALOLAYER1_PREVIOUS_VERSIONS "," PACKAGE_VERSION_STRING(LEVEL1SWATCHCALOLAYER1_VERSION_MAJOR,LEVEL1SWATCHCALOLAYER1_VERSION_MINOR,LEVEL1SWATCHCALOLAYER1_VERSION_PATCH)
#endif

namespace swatchcellCaloLayer1
{
        const std::string package  = "swatchcellCaloLayer1";
        const std::string versions = SWATCHCELLCALOLAYER1_FULL_VERSION_LIST;
        const std::string description = "Calo Layer 1 Trigger Supervisor cell for SWATCH-based systems";
        const std::string authors = "Nate Woods & Tyler Ruggles";
        const std::string summary = "Contains an CaloLayer1 Trigger Supervisor cell for a SWATCH-based control system";
        const std::string link = "https://cactus.web.cern.ch";

        config::PackageInfo getPackageInfo();
        void checkPackageDependencies() throw (config::PackageInfo::VersionException);
        std::set<std::string, std::less<std::string> > getPackageDependencies();
}

#endif
