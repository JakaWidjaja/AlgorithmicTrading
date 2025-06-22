#!/bin/bash

cd "$(dirname "$0")"
rm -rf build && mkdir build && cd build

cmake ..
make -j$(nproc)

echo ">> Running Autocovariance test..."
./testAutocovariance
echo ">> Running Hurst Exponent test..."
./testHurst
echo ">> Running DoubleSMA test..."
./testDoubleSMA
echo ">> Running Variance Ratio test..."
./testVarianceRatio
echo ">> Running Half-Life test..."
./testHalfLife
echo ">> Running SingleSMA test..."
./testSingleSMA
echo ">> Running Savitzky Golay test..."
./testSavitzkyGolay
echo ">> Running OH MaxLikelihood test..."
./testOHMaxLikelihood
echo ">> Running OH Method of Moment test..."
./testOHMethodOfMoment
echo ">> Running Combinations test..."
./testCombinations
echo ">> Running Permutations test..."
./testPermutations

echo ">> All unit tests completed."
