cmake_minimum_required(VERSION 3.16)
project(Protobuffer)

set(target ProtobufferExample)


include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()
 

# we'll find the protobuffer dependency which was downloaded with conan
find_package(Protobuf REQUIRED)

# add the Animal.proto here to create the generic classes with protobuf_generate(...)
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

# the output directory for the proto compiler is our build directory
# if we want to access the generic animal header we need to include this directory
target_include_directories(${target} PUBLIC
  ${CMAKE_CURRENT_BINARY_DIR}
)
