#ifndef EXPLAIN_DRIVER_HH
#define EXPLAIN_DRIVER_HH

#include <map>
#include <memory>
#include <string>
#include <utility>

#include "parser.hh"
#include "ast.hh"

// Give Flex the prototype of yylex we want ...
#define YY_DECL \
    yy::parser::symbol_type yylex (Driver& drv)
// ... and declare it for the parser's sake.
YY_DECL;

class Driver
{
public:
    std::unique_ptr<explain::AST::Root> root;
    std::string file;
    bool trace_parsing, trace_scanning;
    yy::location location;

    Driver()
        : trace_parsing(false), trace_scanning(false), root(nullptr) {}
    int parse(const std::string& f);
    void scan_begin();
    void scan_end();
};

#endif // EXPLAIN_DRIVER_HH
