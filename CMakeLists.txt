cmake_minimum_required(VERSION 3.10)
project(TestCppClient)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include headers
include_directories(
    ${PROJECT_SOURCE_DIR}/IBJts/samples/Cpp/TestCppClient
    ${PROJECT_SOURCE_DIR}/IBJts/source
    ${PROJECT_SOURCE_DIR}/IBJts/source/posix
    ${PROJECT_SOURCE_DIR}/IBJts/source/cppclient/client
    ${PROJECT_SOURCE_DIR}/IBJts/source/cppclient/client/protobufUnix
    ${PROJECT_SOURCE_DIR}/IBJts/source/cppclient/client/OrderCondition
    ${PROJECT_SOURCE_DIR}/IBJts/source/cppclient/common
    ${PROJECT_SOURCE_DIR}/IBClient/include
    ${PROJECT_SOURCE_DIR}/UDF/config/include
    ${PROJECT_SOURCE_DIR}/UDF/MakeContract/include
    ${PROJECT_SOURCE_DIR}/UDF/models/Combinatorics/include
    ${PROJECT_SOURCE_DIR}/UDF/models/OrnsteinUhlenbeck/include
    ${PROJECT_SOURCE_DIR}/UDF/models/Smoothing/include
    ${PROJECT_SOURCE_DIR}/strategy/Portfolio/include
    ${PROJECT_SOURCE_DIR}/strategy/MeanRevertingPortfolio/include
)

# Add all required source files
file(GLOB_RECURSE SOURCES
    ${PROJECT_SOURCE_DIR}/IBJts/source/*.cpp
    ${PROJECT_SOURCE_DIR}/IBJts/source/posix/*.cpp
    ${PROJECT_SOURCE_DIR}/IBJts/source/cppclient/client/*.cpp
    ${PROJECT_SOURCE_DIR}/IBJts/source/cppclient/client/protobufUnix/*.cpp
    ${PROJECT_SOURCE_DIR}/IBJts/source/cppclient/client/OrderCondition/*.cpp
    ${PROJECT_SOURCE_DIR}/IBJts/source/cppclient/common/*.cpp
    ${PROJECT_SOURCE_DIR}/IBClient/source/*.cpp
)

list(APPEND SOURCES
    ${PROJECT_SOURCE_DIR}/main.cpp
    ${PROJECT_SOURCE_DIR}/IBJts/samples/Cpp/TestCppClient/TestCppClient.cpp
    ${PROJECT_SOURCE_DIR}/IBJts/samples/Cpp/TestCppClient/ContractSamples.cpp
    ${PROJECT_SOURCE_DIR}/IBJts/samples/Cpp/TestCppClient/OrderSamples.cpp
    ${PROJECT_SOURCE_DIR}/IBJts/samples/Cpp/TestCppClient/AvailableAlgoParams.cpp
    ${PROJECT_SOURCE_DIR}/IBJts/samples/Cpp/TestCppClient/Utils.cpp
    ${PROJECT_SOURCE_DIR}/IBJts/samples/Cpp/TestCppClient/ScannerSubscriptionSamples.cpp
    ${PROJECT_SOURCE_DIR}/IBJts/samples/Cpp/TestCppClient/AccountSummaryTags.cpp
    ${PROJECT_SOURCE_DIR}/UDF/config/source/Config.cpp
    ${PROJECT_SOURCE_DIR}/UDF/config/source/ConfigTWS.cpp
    ${PROJECT_SOURCE_DIR}/UDF/config/source/ConfigModel.cpp
    ${PROJECT_SOURCE_DIR}/UDF/config/source/ConfigParams.cpp
    ${PROJECT_SOURCE_DIR}/UDF/config/source/ConfigContract.cpp
    ${PROJECT_SOURCE_DIR}/UDF/MakeContract/source/MakeContract.cpp
    ${PROJECT_SOURCE_DIR}/UDF/models/Combinatorics/source/Combinations.cpp
    ${PROJECT_SOURCE_DIR}/UDF/models/OrnsteinUhlenbeck/source/MethodOfMoment.cpp
    ${PROJECT_SOURCE_DIR}/UDF/models/Smoothing/source/SavitzkyGolay.cpp
    ${PROJECT_SOURCE_DIR}/strategy/Portfolio/source/PortfolioSelection.cpp
    ${PROJECT_SOURCE_DIR}/strategy/Portfolio/source/PortfolioWeightsOH.cpp
    ${PROJECT_SOURCE_DIR}/strategy/MeanRevertingPortfolio/source/MeanRevertingPortfolio.cpp
)

# Add external libraries
add_subdirectory(external/OpenXLSX)
add_subdirectory(external/nlopt)
include_directories(${PROJECT_SOURCE_DIR}/external/OpenXLSX)
include_directories(${PROJECT_BINARY_DIR}/external/nlopt/include)
include_directories(${PROJECT_SOURCE_DIR}/external/eigen)

# Find and link protobuf
find_package(Protobuf REQUIRED)
include_directories(${Protobuf_INCLUDE_DIRS})

# Explicitly list all IB-provided Protobuf source files
set(PROTOBUF_SRCS
    ${PROJECT_SOURCE_DIR}/IBJts/source/cppclient/client/protobufUnix/SoftDollarTier.pb.cc
    ${PROJECT_SOURCE_DIR}/IBJts/source/cppclient/client/protobufUnix/PlaceOrderRequest.pb.cc
    ${PROJECT_SOURCE_DIR}/IBJts/source/cppclient/client/protobufUnix/OrderStatus.pb.cc
    ${PROJECT_SOURCE_DIR}/IBJts/source/cppclient/client/protobufUnix/OrderState.pb.cc
    ${PROJECT_SOURCE_DIR}/IBJts/source/cppclient/client/protobufUnix/OrderCondition.pb.cc
    ${PROJECT_SOURCE_DIR}/IBJts/source/cppclient/client/protobufUnix/OrderCancel.pb.cc
    ${PROJECT_SOURCE_DIR}/IBJts/source/cppclient/client/protobufUnix/OrderAllocation.pb.cc
    ${PROJECT_SOURCE_DIR}/IBJts/source/cppclient/client/protobufUnix/Order.pb.cc
    ${PROJECT_SOURCE_DIR}/IBJts/source/cppclient/client/protobufUnix/OpenOrdersEnd.pb.cc
    ${PROJECT_SOURCE_DIR}/IBJts/source/cppclient/client/protobufUnix/OpenOrder.pb.cc
    ${PROJECT_SOURCE_DIR}/IBJts/source/cppclient/client/protobufUnix/GlobalCancelRequest.pb.cc
    ${PROJECT_SOURCE_DIR}/IBJts/source/cppclient/client/protobufUnix/ExecutionRequest.pb.cc
    ${PROJECT_SOURCE_DIR}/IBJts/source/cppclient/client/protobufUnix/ExecutionFilter.pb.cc
    ${PROJECT_SOURCE_DIR}/IBJts/source/cppclient/client/protobufUnix/ExecutionDetailsEnd.pb.cc
    ${PROJECT_SOURCE_DIR}/IBJts/source/cppclient/client/protobufUnix/ExecutionDetails.pb.cc
    ${PROJECT_SOURCE_DIR}/IBJts/source/cppclient/client/protobufUnix/Execution.pb.cc
    ${PROJECT_SOURCE_DIR}/IBJts/source/cppclient/client/protobufUnix/ErrorMessage.pb.cc
    ${PROJECT_SOURCE_DIR}/IBJts/source/cppclient/client/protobufUnix/DeltaNeutralContract.pb.cc
    ${PROJECT_SOURCE_DIR}/IBJts/source/cppclient/client/protobufUnix/Contract.pb.cc
    ${PROJECT_SOURCE_DIR}/IBJts/source/cppclient/client/protobufUnix/ComboLeg.pb.cc
    ${PROJECT_SOURCE_DIR}/IBJts/source/cppclient/client/protobufUnix/CancelOrderRequest.pb.cc
)

add_executable(main ${SOURCES} ${PROTOBUF_SRCS})
target_link_libraries(main ${Protobuf_LIBRARIES})
target_link_libraries(main OpenXLSX)
target_link_libraries(main nlopt)