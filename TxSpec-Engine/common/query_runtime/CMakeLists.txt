cmake_minimum_required(VERSION 3.10) 

# set the project name 
# project(CalculateSqrt VERSION 1.0) 
# option(USE_MYMATH "Use tutorial provided math implementation" ON) 
# configure_file(CalculateSqrtConfig.h.in CalculateSqrtConfig.h) 

# specify the C++ standard 
set(CMAKE_CXX_STANDARD 11) 
set(CMAKE_CXX_STANDARD_REQUIRED True) 

# add debug compile flag
SET(CMAKE_BUILD_TYPE "Debug") 
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb ")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

# add the MathFunctions library,Add a subdirectory to the build，将新加的子目录用于build 
# add_subdirectory(binding) 

# add the executable 
# add_executable(CalculateSqrt Calculate.cpp) 

# 使用特定的源码为项目增加lib

# cpp file

# 2. self
aux_source_directory(. source_list)
aux_source_directory(../json_lib jsonlist)
aux_source_directory(../../protos/request_proto protolist)

add_executable(QueryRuntime ${source_list} ${jsonlist} ${protolist})

target_link_directories(QueryRuntime PUBLIC /home/liyue/Regchain/compliance-engine/common/protobuf/untrusted_lib)

# link_libraries()
# include_directories()

# 该指令的作用为将目标文件与库文件进行链接 
# target_link_libraries官方文档:https://cmake.org/cmake/help/latest/command/target_link_libraries.html 
target_link_libraries(QueryRuntime PUBLIC libprotobuf.a)
target_link_libraries(QueryRuntime PUBLIC libprotoc.a)
target_link_libraries(QueryRuntime PUBLIC libprotobuf-lite.a) 
target_link_libraries(QueryRuntime PUBLIC spdlog::spdlog);

target_include_directories(QueryRuntime PUBLIC 
                            ../utils/third_party/spdlog-1.4.2/include/
                           "${PROJECT_SOURCE_DIR}"
                           "${PROJECT_SOURCE_DIR}/../json_lib" 
                           "${PROJECT_SOURCE_DIR}/../protobuf/untrusted_protobuf_include"
                           "${PROJECT_SOURCE_DIR}/../../protos"
                           ) 