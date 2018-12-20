cmake_minimum_required(VERSION 3.13)
project(explain)

set(CMAKE_PREFIX_PATH /usr/local/opt/bison/)

# Set up project dependencies
find_package(FLEX 2.5 REQUIRED)
find_package(BISON 3.2 REQUIRED)
find_package(LLVM 7.0 REQUIRED)

message(STATUS "Found flex ${FLEX_VERSION} at: ${FLEX_EXECUTABLE}")
message(STATUS "Found bison ${BISON_VERSION} at: ${BISON_EXECUTABLE}")
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION} at: ${LLVM_DIR}")

# Set up flex and bison dependency
FLEX_TARGET(Scanner src/Parser/tokens.l ${CMAKE_CURRENT_BINARY_DIR}/tokens.cc)
BISON_TARGET(Parser src/Parser/parser.y ${CMAKE_CURRENT_BINARY_DIR}/parser.cc)
ADD_FLEX_BISON_DEPENDENCY(Scanner Parser)

# Set up sources and headers
set(SOURCE_COMMON
        src/AST/Conditional/Conditional.cc
        src/AST/Conditional/ConditionalBinaryOp.cc
        src/AST/Conditional/ConditionalCompOp.cc
        src/AST/Conditional/ConditionalUnaryOp.cc
        src/AST/Expression/Expression.cc
        src/AST/Expression/ExpressionBinaryOp.cc
        src/AST/Function/FunctionDeclaration.cc
        src/AST/Identifier/Identifier.cc
        src/AST/Statement/AssignmentStatement.cc
        src/AST/Statement/BlockStatement.cc
        src/AST/Statement/IOStatement.cc
        src/AST/Statement/IfStatement.cc
        src/AST/Statement/ReturnStatement.cc
        src/AST/Statement/Statement.cc
        src/AST/Statement/WhileStatement.cc
        src/Parser/parser.y
        src/Parser/tokens.l
        src/Visitor/Visitor.cc
        src/main.cc
)

set(HEADER_COMMON
        src/AST/ASTNode.h
        src/AST/Conditional/Conditional.h
        src/AST/Conditional/ConditionalBinaryOp.h
        src/AST/Conditional/ConditionalCompOp.h
        src/AST/Conditional/ConditionalUnaryOp.h
        src/AST/Expression/Expression.h
        src/AST/Expression/ExpressionBinaryOp.h
        src/AST/Function/FunctionDeclaration.h
        src/AST/Identifier/Identifier.h
        src/AST/Misc/Operator.h
        src/AST/Statement/AssignmentStatement.h
        src/AST/Statement/BlockStatement.h
        src/AST/Statement/IOStatement.h
        src/AST/Statement/IfStatement.h
        src/AST/Statement/ReturnStatement.h
        src/AST/Statement/Statement.h
        src/AST/Statement/WhileStatement.h
        src/Visitor/Visitor.h
)

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

# Get required LLVM libraries
llvm_map_components_to_libnames(LLVM_LIBS core)

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_executable(explain ${SOURCE_COMMON} ${HEADER_COMMON}
        ${FLEX_Scanner_OUTPUTS}
        ${BISON_Parser_OUTPUTS})

# Link LLVM libraries to the compiler
target_link_libraries(explain ${LLVM_LIBS})