cmake_minimum_required(VERSION 3.10)

project(compliance_engine VERSION 0.8)

# add debug compile flag
# SET(CMAKE_BUILD_TYPE "Debug")
# SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb ")
# SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

# Enable SGX SIM runtime
set(SGX_HW OFF)

# Enable Enclave Debug
set(SGX_MODE Debug)

# Only when build a single integrated application
set(BUILD_INTEGRATED ON)

# Do not build Test artifacts
set(BUILD_TEST OFF)

# Use asio standalone mode (instead of relying on boost)
add_definitions(-DASIO_STANDALONE)

# Turn on --use-prefix flag for each integrated Enclaves
add_definitions(-DUSE_ENCLAVE_PREFIX)

# Prepare SGX enabling environment
# Refer to https://github.com/xzhangxa/SGX-CMake
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/common/cmake)
find_package(SGX REQUIRED)

# Prepare Protobuf and gRPC enabling environment
include(common/cmake/ProtobufGRPC.cmake)

# === Enclave EDL files configuration ===
set(KEY_MANAGEMENT_EDL_FILE key_management/trusted/KeyManagementEnclave.edl)
set(RULE_EDL_FILE rule/trusted/RuleEnclave.edl)
set(BINDING_EDL_FILE binding/trusted/BindingEnclave.edl)
set(LOCAL_ATTESTATION_EDL_FILE common/local_attestation/trusted/LocalAttestation.edl)

set(EDL_SEARCH_PATHS common/local_attestation/trusted
                     common/registration/trusted
                     common/monitor/trusted)

# === Configure trusted (Enclave) compilation ===

# Compiles Key Management Module
add_subdirectory(key_management)

# Compiles Rule Check Module
add_subdirectory(rule)

# Compiles Binding Module
add_subdirectory(binding)

# === Configure untrusted (App) compilation ===

# === Configure untrusted (App) non-SGX part compilation ===

link_directories("common/third_party/prometheus-cpp/lib")
add_subdirectory(common/monitor)

# === Configure untrusted (App) SGX part compilation ===

# Entrypoint source files
set(M_SRCS main.cpp)

# Binding untrusted source files
file(GLOB_RECURSE SRCS_BINDING_UNTRUSTED
    LIST_DIRECTORIES false 
    CONFIGURE_DEPENDS
    binding/untrusted/*.cpp)

# Common untrusted source files
file(GLOB_RECURSE SRCS_COMMON_UNTRUSTED
    LIST_DIRECTORIES false 
    CONFIGURE_DEPENDS
    common/base64/*.cpp
    common/data_types/binding/*.cpp
    common/json_lib/*.cpp
    common/local_attestation/untrusted/*.cpp
    # common/query_runtime/*.cpp
    common/remote_attestation/*.cpp
    common/utils/untrusted/*.cpp
    common/monitor/untrusted/*.cpp)

# Rule untrusted source files
file(GLOB_RECURSE SRCS_RULE_UNTRUSTED
    LIST_DIRECTORIES false 
    CONFIGURE_DEPENDS
    rule/untrusted/*.cpp)

# Key Management untrusted source files
file(GLOB_RECURSE SRCS_KEY_MANAGEMENT_UNTRUSTED
    LIST_DIRECTORIES false 
    CONFIGURE_DEPENDS
    key_management/untrusted/*.cpp)

# Protos untrusted source files
file(GLOB_RECURSE SRCS_PROTOS_UNTRUSTED
    LIST_DIRECTORIES false 
    CONFIGURE_DEPENDS
    common/protos/untrusted_cpp/*.cc)

# Request Processor untrusted source files
file(GLOB_RECURSE SRCS_COMPLIANCE_ENGINE
    LIST_DIRECTORIES false 
    CONFIGURE_DEPENDS
    compliance_engine_server/*.cpp
    )

# Request Processor untrusted source files
file(GLOB_RECURSE SRCS_HTTP_CLIENT
    LIST_DIRECTORIES false 
    CONFIGURE_DEPENDS
    http_client/*.cpp
    )

list(APPEND U_SRCS 
                   ${SRCS_BINDING_UNTRUSTED} 
                   ${SRCS_COMMON_UNTRUSTED} 
                   ${SRCS_KEY_MANAGEMENT_UNTRUSTED}
                   ${SRCS_PROTOS_UNTRUSTED}
                   ${SRCS_REQUEST_PROCESSOR_UNTRUSTED}
                   ${SRCS_COMPLIANCE_ENGINE}
                   ${SRCS_RULE_UNTRUSTED}
                   ${SRCS_HTTP_CLIENT})
list(APPEND SRCS ${M_SRCS} ${U_SRCS})

# === Define Target for untrusted (App) compilation ===

# Main Entrypoint
add_untrusted_executable(main USE_PREFIX SRCS ${SRCS}
                        EDL 
                        ${KEY_MANAGEMENT_EDL_FILE} 
                        ${RULE_EDL_FILE} 
                        ${BINDING_EDL_FILE}
                        EDL_SEARCH_PATHS ${EDL_SEARCH_PATHS}
                        )

# add_executable(main ${SRCS})

# Link generated Enclaves into CMAKE_BINARY_DIR after main is built
add_custom_command(TARGET main POST_BUILD
                   COMMAND ln -s -f key_management/key_management_enclave.signed.so .
                   COMMAND ln -s -f rule/rule_enclave.signed.so .
                   COMMAND ln -s -f binding/binding_enclave.signed.so .
                   VERBATIM USES_TERMINAL)

# Third-Party libraries needed by Remote Attestation capability
add_subdirectory(common/third_party/spdlog-1.4.2 ./third_party/spdlog)
add_subdirectory(common/third_party/cppcodec-0.2 ./third_party/cppcodec)
add_subdirectory(common/third_party/yaml-cpp-0.7.0 ./third_party/yaml-cpp)

# OpenSSL is required for Remote Attestation capability
find_package(OpenSSL REQUIRED)

# Boost is required for http client
find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

# Link with Data Access and Request Processor static libraries
# target_link_libraries(main data_access request_processor)
# NOTE: Request Processor is no longer needed as a static lib, instead, we
#       build with main here in this CMakeLists.txt file
link_directories("common/monitor/build")
target_link_libraries(main 
                           ${_REFLECTION}
                           ${_GRPC_GRPCPP}
                           ${_PROTOBUF_LIBPROTOBUF}
                           spdlog::spdlog
                           OpenSSL::SSL
                           ${Boost_LIBRARIES}
                           yaml-cpp::yaml-cpp
                           monitor
                           )

# Setup include directories for Main Entrypoint
target_include_directories(main PRIVATE 
                                include
                                
                                common/third_party/asio-1.12.2/include
                                common/third_party/spdlog-1.4.2/include
                                common/third_party/cppcodec-0.2
                                common/third_party/yaml-cpp-0.7.0/include
                                common/third_party/prometheus-cpp
                                
                                common/protos/trusted_cpp
                                common/protos/untrusted_cpp
                                )
