cmake_minimum_required(VERSION 3.10)

project(monitor VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

link_directories("../third_party/prometheus-cpp/lib")

if(NOT BUILD_INTEGRATED)
    add_executable(monitor main.cpp prometheus_client/client.cpp)
else()
    add_library(monitor STATIC prometheus_client/client.cpp)
endif()

target_link_libraries(monitor PRIVATE
    "libprometheus-cpp-push.so"
    "libprometheus-cpp-core.so"
    )
target_include_directories(monitor PRIVATE
    ../../include
    ../../common/third_party/spdlog-1.4.2/include
    ../../common/third_party/prometheus-cpp
    )