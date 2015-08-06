# CaloLayer1Sandbox
An area to play around with SWATCH, etc., for the Stage 2, Layer 1 calo trigger online software
BREACH: rearrange

# Checkout & make: 
git clone --recursive -b rearrange git@github.com:uwcms/CaloLayer1Sandbox.git
cd CaloLayer1Sandbox
source environment.sh
make

# All should compile, there will be error message related to unused variables in BOOST...



# We are in the process of getting a test module to run.
cd cactusprojects/caloLayer1/ts/cell/test/
source runStandalone.sh

# There will be errors
