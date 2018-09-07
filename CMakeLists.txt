cmake_minimum_required (VERSION 2.8.12)

enable_language(CXX)

find_package(ProtonCpp REQUIRED)
set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(LOCAL_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
find_package(Threads)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(test)

include_directories(${ProtonCpp_INCLUDE_DIRS} ${GTest_INCLUDE_DIRS} ${LOCAL_INCLUDE_DIR})
link_libraries(${ProtonCpp_LIBRARIES})
add_definitions(${ProtonCpp_DEFINITIONS} ${GTest_DEFINITIONS})

add_executable(test test.cpp)
add_executable(amq_send amq_send.cpp)
add_executable(simple_recv simple_recv.cpp)