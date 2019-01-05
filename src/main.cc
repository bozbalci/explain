#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>

#include <boost/filesystem.hpp>
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
    po::options_description opts("General options");
    opts.add_options()
            ("help,h", "print this help message and exit")
            ("version,v", "print version and exit")
            ("input,i", po::value<std::string>(), "input file")
            ("output,o", po::value<std::string>(), "output file")
            ;

    po::options_description debug("Debugging options");
    debug.add_options()
            ("trace-scan", "run scanner in debug mode")
            ("trace-parse", "run parser in debug mode")
            ;

    po::options_description ssel("Stage selection options");
    ssel.add_options()
            ("emit-ast", "emit AST in pretty-printed form")
            ("emit-llvm", "emit LLVM representation only")
            (",c", "generate object file")
            ;

    opts.add(debug).add(ssel);

    po::positional_options_description p;
    p.add("input", 1);

    po::variables_map vm;
    po::store(po::command_line_parser(argc, argv)
                .options(opts)
                .positional(p)
                .run(), vm);
    po::notify(vm);

    Driver d;
    explain::MessageIssuer mi;

    if (vm.count("help"))
    {
        std::cout << "explain, the industrial grade XPLN compiler\n" << std::endl;
        std::cout << opts << std::endl;
        std::cout << "If no stage selection option is specified, then every stage will be run and"
                     "\nthe linker is run to produce an executable." << std::endl;
        std::exit(EXIT_SUCCESS);
    }

    if (vm.count("version"))
    {
        std::cout << "explain, the industrial grade XPLN compiler" << std::endl;
        std::cout << "version: 1.0.0" << std::endl;
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
    mi.checkpoint();

    if (vm.count("emit-ast"))
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

    std::string moduleName;

    if (inputFileName == "-")
        moduleName = "stdin";
    else
    {
        boost::filesystem::path p(inputFileName);
        moduleName = p.filename().string();
    }

    explain::CodeGenerator codeGenerator(&mi, moduleName);
    d.accept(codeGenerator);
    mi.checkpoint();

    if (vm.count("emit-llvm"))
    {
        codeGenerator.printModule(outputFileName);
        std::exit(EXIT_SUCCESS);
    }


    if (vm.count("c"))
    {
        codeGenerator.emitObject(outputFileName);
        std::exit(EXIT_SUCCESS);
    }

    // All options have been exhausted -- emit object and link.
    std::string objectDestination = boost::filesystem::unique_path("%%%%-%%%%-%%%%-%%%%.o").string();
    std::string driverDestination = boost::filesystem::unique_path("%%%%-%%%%-%%%%-%%%%.c").string();

    codeGenerator.emitObject(objectDestination);
    codeGenerator.emitDriver(driverDestination);

    std::stringstream cmd;
    cmd << "cc -o " << outputFileName << " " << objectDestination << " " << driverDestination;

    std::system(cmd.str().c_str());
    std::remove(objectDestination.c_str());
    std::remove(driverDestination.c_str());

    mi.checkpoint();
}
