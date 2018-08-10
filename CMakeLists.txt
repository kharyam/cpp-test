#
# Licensed to the Apache Software Foundation (ASF) under one
# or more contributor license agreements.  See the NOTICE file
# distributed with this work for additional information
# regarding copyright ownership.  The ASF licenses this file
# to you under the Apache License, Version 2.0 (the
# "License"); you may not use this file except in compliance
# with the License.  You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing,
# software distributed under the License is distributed on an
# "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
# KIND, either express or implied.  See the License for the
# specific language governing permissions and limitations
# under the License.
#
cmake_minimum_required (VERSION 2.8.12)

enable_language(CXX)

find_package(ProtonCpp REQUIRED)
set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
find_package(Threads)

# Enable code coverage
# TODO - need to make these flags applicable only to unit test executable, not the main executable
set(CMAKE_CXX_FLAGS "-fprofile-arcs -ftest-coverage -lpthread -O0 ${CMAKE_CXX_FLAGS}")

include_directories(${ProtonCpp_INCLUDE_DIRS} /usr/local/include/gtest/)
link_libraries(${ProtonCpp_LIBRARIES} /usr/local/lib64/libgtest.a /usr/local/lib64/libgtest_main.a
)
add_definitions(${ProtonCpp_DEFINITIONS})


macro (has_cxx_features result)
set(${result} OFF)
if (DEFINED CMAKE_CXX_COMPILE_FEATURES)
  set(${result} ON)
  foreach(feature ${ARGN})
    list(FIND CMAKE_CXX_COMPILE_FEATURES cxx_${feature} N)
    if (N EQUAL -1)
      set(${result} OFF)
      break()
    endif()
  endforeach()
endif()
endmacro()

set (BUILD_CPP_03 OFF CACHE BOOL "Compile as C++03 even when C++11 is available")
# This effectively checks for cmake version 3.1 or later
if (DEFINED CMAKE_CXX_COMPILE_FEATURES)
  if (BUILD_CPP_03)
    set(STD 98)
  else ()
    set(STD 11)
    has_cxx_features(HAS_ENOUGH_CPP11 lambdas variadic_templates)
    message(STATUS "Compiling C++11 examples: ${HAS_ENOUGH_CPP11}")
  endif ()
  set(CMAKE_CXX_STANDARD ${STD})
  set(CMAKE_CXX_EXTENSIONS OFF)
endif()

# Single-threaded examples that work on C++03
foreach(example
    test
    amq_send
    unit_test
)
  add_executable(${example} ${example}.cpp)
endforeach()
