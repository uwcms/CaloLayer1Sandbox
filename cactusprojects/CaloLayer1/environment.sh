#!/bin/bash

setupFile=`echo $BASH_SOURCE`
setupFileDir=`dirname $setupFile`
if [ $setupFileDir == "." ]; then
    setupFileDir=$PWD
fi

export BUILD_HOME=$setupFileDir

echo Loading environment for $setupFileDir

export RCT_BASE_HOME=$BUILD_HOME



domain=`hostname -d`
echo "Setting up environment for $domain"


#Calo Layer 1
export CALOLAYER1=$BUILD_HOME/ts/cell/

#MKDEP
export MKDEPDIR=$BUILD_HOME/mkdep_makefile/

echo SWATCH Calo Layer 1 2015-08-04 environment loaded

#EOF
