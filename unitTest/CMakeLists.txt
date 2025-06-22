cmake_minimum_required(VERSION 3.10)
project(UnitTests)

set(CMAKE_CXX_STANDARD 20)

# Include GoogleTest and your source
add_subdirectory(external/googletest)

include_directories(
    external/googletest/googletest/include
    external/eigen  
    ../UDF/models/TechnicalIndicator/include
    ../UDF/models/Smoothing/include
    ../UDF/models/OrnsteinUhlenbeck/include
    ../UDF/models/Combinatorics/include
)

function(add_unit_test name)
    add_executable(${name} ${ARGN})
    target_link_libraries(${name} gtest gtest_main pthread)
endfunction()

add_unit_test(testAutocovariance   testAutocovariance.cpp   ../UDF/models/TechnicalIndicator/source/Autocovariance.cpp)
add_unit_test(testHurst            testHurstExponent.cpp    ../UDF/models/TechnicalIndicator/source/HurstExponent.cpp)
add_unit_test(testDoubleSMA        testDoubleSMA.cpp        ../UDF/models/TechnicalIndicator/source/DoubleSMA.cpp)
add_unit_test(testVarianceRatio    testVarianceRatio.cpp    ../UDF/models/TechnicalIndicator/source/VarianceRatio.cpp)
add_unit_test(testHalfLife         testHalfLife.cpp         ../UDF/models/TechnicalIndicator/source/HalfLife.cpp)
add_unit_test(testSingleSMA        testSingleSMA.cpp        ../UDF/models/TechnicalIndicator/source/SingleSMA.cpp)
add_unit_test(testSavitzkyGolay    testSavitzkyGolay.cpp    ../UDF/models/Smoothing/source/SavitzkyGolay.cpp)
add_unit_test(testOHMaxLikelihood  testOHMaxLikelihood.cpp  ../UDF/models/OrnsteinUhlenbeck/source/MaxLikelihood.cpp)
add_unit_test(testOHMethodOfMoment testOHMethodOfMoment.cpp ../UDF/models/OrnsteinUhlenbeck/source/MethodOfMoment.cpp)
add_unit_test(testCombinations     testCombinations.cpp     ../UDF/models/Combinatorics/source/Combinations.cpp)
add_unit_test(testPermutations     testPermutations.cpp     ../UDF/models/Combinatorics/source/Permutations.cpp 
														    ../UDF/models/Combinatorics/source/Combinations.cpp
														    ../UDF/models/Combinatorics/source/CombinatoricsGenerator.cpp)

