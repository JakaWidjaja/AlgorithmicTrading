# stop on first error
set -e

# home directory
cd "/home/lun/Desktop/Folder 2/AlgoTradingC++/IBKRTests/TWSOrder"

# build directory
mkdir -p build
cd build

# Run CMake and make
cmake ..
make -j > build_output.txt 2>&1 # Store error(s) in txt file

# Run
./mainTWSOrder