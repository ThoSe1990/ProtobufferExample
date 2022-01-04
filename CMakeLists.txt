cmake_minimum_required(VERSION 3.16)
project(Protobuffer)

set(target ProtobufferExample)


include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
# EDIT: after adding cmake_paths in conanfile.txt we can include conan_paths.cmake
include(${CMAKE_BINARY_DIR}/conan_paths.cmake)
conan_basic_setup()
 

# find_package(Protobuf REQUIRED)
# EDIT: and we can get rid of the find_package command by including protoc-config.cmake
include(${CONAN_PROTOC_INSTALLER_ROOT}/lib/cmake/protoc/protoc-config.cmake)

add_executable(${target}
  ${PROJECT_SOURCE_DIR}/proto/Animal.proto
  ${PROJECT_SOURCE_DIR}/src/main.cpp
)
 
protobuf_generate(TARGET ${target}
  PROTOS ${PROJECT_SOURCE_DIR}/proto/Animal.proto    
)
 
target_link_libraries(${target}
  ${CONAN_LIBS}
)

target_include_directories(${target} PUBLIC
  ${CMAKE_CURRENT_BINARY_DIR}
)
