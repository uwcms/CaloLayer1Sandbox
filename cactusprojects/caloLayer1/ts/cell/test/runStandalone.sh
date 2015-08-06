#!/bin/bash

#################################################
# 1. PARSE SCRIPT ARGUMENTS

# A POSIX variable
OPTIND=1         # Reset in case getopts has been used previously in the shell.

RUN_GDB=0

while getopts ":g" opt; do
case $opt in
    g)
        echo "-g was triggered, Parameter: $OPTARG" >&2
        RUN_GDB=1
        ;;
    \?)
        echo "Invalid option: -$OPTARG" >&2
        exit 1
        ;;
esac
done


##################################################
# 2. SET ENVIRONMENT VARIABLES

export XDAQ_ROOT=/opt/xdaq
export XDAQ_DOCUMENT_ROOT=/opt/xdaq/htdocs

export LD_LIBRARY_PATH=/opt/xdaq/lib:/opt/cactus/lib:$LD_LIBRARY_PATH

HERE=$(python -c "import os.path; print os.path.dirname(os.path.abspath('$BASH_SOURCE'))")

SWATCH_ROOT=/opt/cactus/include/swatch
LOCAL_SWATCH_ROOT=${HERE}/../../.. # I think this is correct, we want to be at 'caloLayer1'
export LD_LIBRARY_PATH=${SWATCH_ROOT}/logger/lib:${SWATCH_ROOT}/core/lib:${SWATCH_ROOT}/processor/lib:${SWATCH_ROOT}/system/lib:${LD_LIBRARY_PATH}
export LD_LIBRARY_PATH=${LOCAL_SWATCH_ROOT}/ctp7/lib:${LD_LIBRARY_PATH}

export swatchexample_ROOT=${HERE}/..
export swatchframework_ROOT=${swatchexample_ROOT}/../framework

export LD_LIBRARY_PATH=${swatchframework_ROOT}/lib/linux/x86_64_slc6:${LD_LIBRARY_PATH}


#################################################
# 3. START THE CELL (interactively)

mkdir -p /tmp/swatchcell/
CONFIGURE_FILE=/tmp/swatchcell/standalone.configure

sed "s/__HOSTNAME__PORT__/`hostname`:2979/" ${swatchexample_ROOT}/test/standalone.configure > $CONFIGURE_FILE

CMD="/opt/xdaq/bin/xdaq.exe -p 2979 -c ${CONFIGURE_FILE}"
if [[ "${RUN_GDB}" -eq 1 ]]; then
    gdb --args $CMD
else
    $CMD
fi
