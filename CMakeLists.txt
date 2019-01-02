cmake_minimum_required(VERSION 3.13)
project(explain)

set(CMAKE_PREFIX_PATH /usr/local/opt/bison/)

# Set up project dependencies
find_package(FLEX 2.5 REQUIRED)
find_package(BISON 3.2)
find_package(LLVM 7.0 REQUIRED)

# TODO Get rid of this ugly hack
set(MACOS_OVERRIDE_BISON_PATH /usr/local/opt/bison/bin/bison)
if(CMAKE_SYSTEM_NAME MATCHES "Darwin")
    if(EXISTS ${MACOS_OVERRIDE_BISON_PATH})
        set(BISON_EXECUTABLE ${MACOS_OVERRIDE_BISON_PATH})
        set(BISON_VERSION 3.2)
        message(STATUS "Overriding system bison found at: ${MACOS_OVERRIDE_BISON_PATH}")
        message(WARNING "*IMPORTANT* Do NOT rely on the Bison version stated in build messages!\n"
                        "You are using Bison >= 3.2 installed by Homebrew.")
    endif()
endif()

message(STATUS "Found flex ${FLEX_VERSION} at: ${FLEX_EXECUTABLE}")
message(STATUS "Found bison ${BISON_VERSION} at: ${BISON_EXECUTABLE}")
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION} at: ${LLVM_DIR}")

# Set up sources and headers
set(SOURCE_COMMON
        src/ast.cc
        src/driver.cc
        src/parser.yy
        src/scanner.ll
        src/main.cc
        src/codegen.cc)

set(HEADER_COMMON
        src/ast.hh
        src/driver.hh
        src/codegen.hh
        src/util.hh)

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

# Get required LLVM libraries
llvm_map_components_to_libnames(LLVM_LIBS core)

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

# Set up flex and bison dependency
flex_target(Scanner src/scanner.ll ${CMAKE_CURRENT_BINARY_DIR}/scanner.cc COMPILE_FLAGS "-i")
bison_target(Parser src/parser.yy ${CMAKE_CURRENT_BINARY_DIR}/parser.cc)
add_flex_bison_dependency(Scanner Parser)

add_executable(explain ${SOURCE_COMMON} ${HEADER_COMMON}
        ${FLEX_Scanner_OUTPUTS}
        ${BISON_Parser_OUTPUTS})

# Link LLVM libraries to the compiler
target_link_libraries(explain ${LLVM_LIBS})