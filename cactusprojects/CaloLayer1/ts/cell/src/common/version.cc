#include "config/version.h"
#include "CaloLayer1/ts/cell/version.h"

GETPACKAGEINFO(swatchcellCaloLayer1)

void
swatchcellCaloLayer1::checkPackageDependencies() throw (config::PackageInfo::VersionException)
{
        CHECKDEPENDENCY(config);
}


std::set<std::string, std::less<std::string> >
swatchcellCaloLayer1::getPackageDependencies()
{
        std::set<std::string, std::less<std::string> > dependencies;
        ADDDEPENDENCY(dependencies,config);
        return dependencies;
}  
