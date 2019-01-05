#include <iostream>
#include <utility>

#include "canonicalizer.hh"
#include "driver.hh"
#include "messages.hh"
#include "printer.hh"
#include "codegen.hh"

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
            explain::MessageIssuer mi;
            explain::Canonicalizer cn(&mi);
            // explain::PrettyPrinter pp(&mi);
            explain::CodeGenerator cg(&mi);

            drv.root->accept(cn);
            // drv.root->accept(pp);
            drv.root->accept(cg);

            cg.emitObject();
        }
        else
        {
            res = 1;
        }
    }

    return res;
}
