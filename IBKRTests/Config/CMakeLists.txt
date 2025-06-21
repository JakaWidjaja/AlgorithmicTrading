cmake_minimum_required(VERSION 3.10)
project(TestMainConfig)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define ROOT directory from current folder up 2 levels
get_filename_component(ROOT_DIR "${CMAKE_SOURCE_DIR}/../../" ABSOLUTE)

# Include directories
include_directories(
    ${ROOT_DIR}/IBJts/source
    ${ROOT_DIR}/IBJts/source/posix
    ${ROOT_DIR}/IBJts/source/cppclient/client
    ${ROOT_DIR}/IBJts/source/cppclient/client/protobufUnix
    ${ROOT_DIR}/IBJts/source/cppclient/client/OrderCondition
    ${ROOT_DIR}/IBJts/source/cppclient/common
    ${ROOT_DIR}/IBClient/include
    ${ROOT_DIR}/UDF/config/include
    ${ROOT_DIR}/external/OpenXLSX
    ${ROOT_DIR}/external/eigen
    ${CMAKE_BINARY_DIR}/external/nlopt/include
)

# External dependencies
add_subdirectory(${ROOT_DIR}/external/OpenXLSX ${CMAKE_BINARY_DIR}/external/OpenXLSX)
add_subdirectory(${ROOT_DIR}/external/nlopt ${CMAKE_BINARY_DIR}/external/nlopt)

# Protobuf
find_package(Protobuf REQUIRED)
include_directories(${Protobuf_INCLUDE_DIRS})

# Protobuf generated source files
set(PROTOBUF_SRCS
    ${ROOT_DIR}/IBJts/source/cppclient/client/protobufUnix/SoftDollarTier.pb.cc
    ${ROOT_DIR}/IBJts/source/cppclient/client/protobufUnix/PlaceOrderRequest.pb.cc
    ${ROOT_DIR}/IBJts/source/cppclient/client/protobufUnix/OrderStatus.pb.cc
    ${ROOT_DIR}/IBJts/source/cppclient/client/protobufUnix/OrderState.pb.cc
    ${ROOT_DIR}/IBJts/source/cppclient/client/protobufUnix/OrderCondition.pb.cc
    ${ROOT_DIR}/IBJts/source/cppclient/client/protobufUnix/OrderCancel.pb.cc
    ${ROOT_DIR}/IBJts/source/cppclient/client/protobufUnix/OrderAllocation.pb.cc
    ${ROOT_DIR}/IBJts/source/cppclient/client/protobufUnix/Order.pb.cc
    ${ROOT_DIR}/IBJts/source/cppclient/client/protobufUnix/OpenOrdersEnd.pb.cc
    ${ROOT_DIR}/IBJts/source/cppclient/client/protobufUnix/OpenOrder.pb.cc
    ${ROOT_DIR}/IBJts/source/cppclient/client/protobufUnix/GlobalCancelRequest.pb.cc
    ${ROOT_DIR}/IBJts/source/cppclient/client/protobufUnix/ExecutionRequest.pb.cc
    ${ROOT_DIR}/IBJts/source/cppclient/client/protobufUnix/ExecutionFilter.pb.cc
    ${ROOT_DIR}/IBJts/source/cppclient/client/protobufUnix/ExecutionDetailsEnd.pb.cc
    ${ROOT_DIR}/IBJts/source/cppclient/client/protobufUnix/ExecutionDetails.pb.cc
    ${ROOT_DIR}/IBJts/source/cppclient/client/protobufUnix/Execution.pb.cc
    ${ROOT_DIR}/IBJts/source/cppclient/client/protobufUnix/ErrorMessage.pb.cc
    ${ROOT_DIR}/IBJts/source/cppclient/client/protobufUnix/DeltaNeutralContract.pb.cc
    ${ROOT_DIR}/IBJts/source/cppclient/client/protobufUnix/Contract.pb.cc
    ${ROOT_DIR}/IBJts/source/cppclient/client/protobufUnix/ComboLeg.pb.cc
    ${ROOT_DIR}/IBJts/source/cppclient/client/protobufUnix/CancelOrderRequest.pb.cc
)

# Source files
file(GLOB_RECURSE IBKR_SOURCES
    ${ROOT_DIR}/IBJts/source/*.cpp
    ${ROOT_DIR}/IBClient/source/*.cpp
    ${ROOT_DIR}/UDF/config/source/*.cpp
)

set(MAIN_SOURCE ${ROOT_DIR}/IBKRTests/Config/mainConfig.cpp)

# Define the executable
add_executable(mainConfig
    ${MAIN_SOURCE}
    ${IBKR_SOURCES}
    ${PROTOBUF_SRCS}
)

# Link libraries
target_link_libraries(mainConfig
    ${Protobuf_LIBRARIES}
    OpenXLSX
    nlopt
)
