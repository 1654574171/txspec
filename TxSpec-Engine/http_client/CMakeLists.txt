cmake_minimum_required(VERSION 3.10)

project(http-test)

add_subdirectory(../common/utils/third_party/spdlog-1.4.2 ./third_party/spdlog)

file(GLOB_RECURSE SRCS_COMMON_UNTRUSTED
    LIST_DIRECTORIES false 
    CONFIGURE_DEPENDS
    ../common/json_lib/*.cpp)

add_executable(http-test main.cc HttpClient.cpp ${SRCS_COMMON_UNTRUSTED})

target_link_libraries(http-test 
                           spdlog::spdlog)

target_include_directories(http-test PRIVATE . ..
                           ../common/utils/third_party/spdlog-1.4.2/include
                           ../common/json_lib)
