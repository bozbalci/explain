cmake_minimum_required(VERSION 3.13)
project(explain)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_PREFIX_PATH /usr/local/opt/bison/)

# Set up project dependencies
find_package(Boost 1.67 REQUIRED COMPONENTS
        filesystem program_options)
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

set(SOURCE_COMMON
        src/canonicalizer.cc
        src/codegen.cc
        src/driver.cc
        src/main.cc
        src/parser.yy
        src/printer.cc
        src/scanner.ll)

set(HEADER_COMMON
        src/ast.hh
        src/canonicalizer.hh
        src/codegen.hh
        src/driver.hh
        src/messages.hh
        src/printer.hh)

flex_target(Scanner src/scanner.ll
        ${CMAKE_CURRENT_BINARY_DIR}/scanner.cc
        COMPILE_FLAGS "-i") # Case insensitive scanning
bison_target(Parser src/parser.yy
        ${CMAKE_CURRENT_BINARY_DIR}/parser.cc
        COMPILE_FLAGS "-v" # Verbose description of parser states and actions
        )
add_flex_bison_dependency(Scanner Parser)

add_executable(explain
        ${SOURCE_COMMON}
        ${HEADER_COMMON}
        ${FLEX_Scanner_OUTPUTS}
        ${BISON_Parser_OUTPUTS})

llvm_map_components_to_libnames(LLVM_LIBS core mcjit all support)

add_definitions(${LLVM_DEFINITIONS})

include_directories(${LLVM_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${Boost_INCLUDE_DIRS})

target_link_libraries(explain ${LLVM_LIBS})
target_link_libraries(explain ${Boost_LIBRARIES})

# Uncomment to enable AddressSanitizer
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fsanitize=leak -g")
# set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address -fsanitize=address -fsanitize=leak -g")
# set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=address -fsanitize=leak -g")
# set(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} -fsanitize=address -fsanitize-leak -g")
