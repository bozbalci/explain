#include <cstdlib>
#include <fstream>
#include <iostream>

#include <boost/program_options.hpp>

#include "canonicalizer.hh"
#include "driver.hh"
#include "messages.hh"
#include "printer.hh"
#include "codegen.hh"

namespace po = boost::program_options;

int
main(int argc, char *argv[])
{
    po::options_description desc("Allowed options");
    desc.add_options()
            ("help,h", "produce this help message and exit")
            ("trace-scan", "run scanner in debug mode")
            ("trace-parse", "run parser in debug mode")
            ("pretty-ast", "pretty-print the AST")
            ("emit-llvm", "dump LLVM IR to output")
            ("output,o", po::value<std::string>(), "file to save LLVM IR or object file to")
            ("input", po::value<std::string>(), "input file")
            ;

    po::positional_options_description p;
    p.add("input", -1);

    po::variables_map vm;
    po::store(po::command_line_parser(argc, argv)
                .options(desc)
                .positional(p)
                .run(), vm);
    po::notify(vm);

    Driver d;
    explain::MessageIssuer mi;

    if (vm.count("help"))
    {
        std::cout << desc << std::endl;
        std::exit(EXIT_SUCCESS);
    }

    if (!vm.count("input"))
        mi.fatal_error("no input file specified");
    if (!vm.count("output"))
        mi.fatal_error("no output file specified");

    auto inputFileName = vm["input"].as<std::string>();
    auto outputFileName = vm["output"].as<std::string>();

    if (vm.count("trace-scan"))
        d.trace_scanning = true;

    if (vm.count("trace-parse"))
        d.trace_parsing = true;

    if (d.parse(inputFileName))
        std::exit(EXIT_FAILURE);

    explain::Canonicalizer canonicalizer(&mi);
    d.accept(canonicalizer);

    if (vm.count("pretty-ast"))
    {
        std::ofstream outputFile(outputFileName);

        if (outputFile)
        {
            explain::PrettyPrinter printer(&mi, &outputFile);
            d.accept(printer);
            outputFile.flush();
            std::exit(EXIT_SUCCESS);
        }
    }

    explain::CodeGenerator codeGenerator(&mi);
    d.accept(codeGenerator);

    if (vm.count("emit-llvm"))
    {
        codeGenerator.printModule(outputFileName);
        std::exit(EXIT_SUCCESS);
    }

    codeGenerator.emitObject(outputFileName);
}
