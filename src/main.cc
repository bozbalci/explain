#include <iostream>
#include <utility>

#include "driver.hh"
#include "canonicalizer.hh"
#include "printer.hh"

int
main(int argc, char *argv[])
{
    int res = 0;
    Driver drv;

    for (int i = 1; i < argc; ++i)
    {
        if (argv[i] == std::string("-p"))
        {
            drv.trace_parsing = true;
        }
        else if (argv[i] == std::string("-s"))
        {
            drv.trace_scanning = true;
        }
        else if (!drv.parse(argv[i]))
        {
            explain::Canonicalizer c;
            explain::PrettyPrinter p;

            drv.root->accept(c);
            drv.root->accept(p);

            /*explain::CodeGen::Context ctx;
            ctx.initialize();

            ctx.codegen(std::move(drv.root));

            std::string Str;
            llvm::raw_string_ostream OS(Str);
            OS << *ctx.TheModule;
            OS.flush();

            std::cout << Str << std::endl;*/
        }
        else
        {
            res = 1;
        }
    }

    return res;
}
