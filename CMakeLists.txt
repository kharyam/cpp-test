cmake_minimum_required (VERSION 2.8.12)

enable_language(CXX)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(ProtonCpp REQUIRED)
find_package(Protobuf REQUIRED)
find_package(Threads)

protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS person.proto)

set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(LOCAL_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(test)

include_directories(${ProtonCpp_INCLUDE_DIRS} ${GTest_INCLUDE_DIRS} ${LOCAL_INCLUDE_DIR} ${PROTO_HDRS})
include_directories(${PROTOBUF_INCLUDE_DIRS})
link_libraries(${ProtonCpp_LIBRARIES} ${PROTOBUF_LIBRARY})
add_definitions(${ProtonCpp_DEFINITIONS} ${GTest_DEFINITIONS})

add_executable(test test.cpp)
add_executable(amq_send amq_send.cpp ${PROTO_SRCS})
add_executable(simple_recv simple_recv.cpp ${PROTO_SRCS})