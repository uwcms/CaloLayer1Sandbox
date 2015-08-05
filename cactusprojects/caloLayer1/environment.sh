#!/bin/bash

setupFile=`echo $BASH_SOURCE`
setupFileDir=`dirname $setupFile`
if [ $setupFileDir == "." ]; then
    setupFileDir=$PWD
fi

export BUILD_HOME=$setupFileDir

echo Loading environment for $setupFileDir

domain=`hostname -d`
echo "Setting up environment for $domain"

# TS Cell
export TSCELL_HOME=$BUILD_HOME/ts/cell

# MKDEP
export MKDEPDIR=$BUILD_HOME/mkdep_makefile

# CTP7
export CTP7_HOME=$CALOLAYER1_HOME/ctp7

#Append 'bin' path
export PATH=$PATH:/$BUILD_HOME/bin

echo SWATCH Calo Layer 1 2015-08-05 environment loaded

#EOF
