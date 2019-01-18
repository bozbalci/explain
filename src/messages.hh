#ifndef EXPLAIN_MESSAGES_HH
#define EXPLAIN_MESSAGES_HH

#include "location.hh"

#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>

namespace explain {

class MessageIssuer
{
    int warningCount, errorCount;

    static constexpr auto RESET = "\033[0m";
    static constexpr auto BLACK = "\033[30m";
    static constexpr auto RED =  "\033[31m";
    static constexpr auto GREEN = "\033[32m";
    static constexpr auto YELLOW = "\033[33m";
    static constexpr auto BLUE = "\033[34m";
    static constexpr auto MAGENTA = "\033[35m";
    static constexpr auto CYAN = "\033[36m";
    static constexpr auto WHITE = "\033[37m";

    static constexpr auto BOLD = "\033[1m";

    void
    location(const yy::location& loc)
    {
        std::cerr << loc.begin << ": ";
    }

    void
    issue(const std::string& prefix, const std::string& color, const std::string& msg, const yy::location *loc)
    {
        std::cerr << BOLD;
        if (loc)
            location(*loc);
        std::cerr << color << prefix << ": " << RESET << msg << std::endl;
    }
public:
    MessageIssuer()
        : warningCount(0), errorCount(0) {}

    void
    note(const std::string& msg, const yy::location *loc = nullptr)
    {
        issue("note", CYAN, msg, loc);
    }

    void
    warning(const std::string& msg, const yy::location *loc = nullptr)
    {
        issue("warning", MAGENTA, msg, loc);

        warningCount++;
    }

    void
    error(const std::string& msg, const yy::location *loc = nullptr)
    {
        issue("error", RED, msg, loc);

        errorCount++;
    }

    void
    fatal_error(const std::string& msg, const yy::location *loc = nullptr)
    {
        issue("fatal error", WHITE, msg, loc);
        std::exit(EXIT_FAILURE);
    }

    void
    checkpoint()
    {
        std::stringstream ss;
        bool haveMessages = false, shouldDie = false;

        if (warningCount > 0)
        {
            std::string pluralized = (warningCount == 1) ? "warning" : "warnings";
            ss << warningCount << " " << pluralized;

            if (errorCount > 0)
                ss << " and ";

            haveMessages = true;

            // Reset warning count for future checkpoints
            warningCount = 0;
        }

        if (errorCount > 0)
        {
            std::string pluralized = (errorCount == 1) ? "error" : "errors";
            ss << errorCount << " " << pluralized;

            haveMessages = true;
            shouldDie = true;
        }

        if (haveMessages)
        {
            ss << " generated.";
            std::cerr << ss.str() << std::endl;
        }

        if (shouldDie)
            std::exit(EXIT_FAILURE);
    }
};

}

#endif //EXPLAIN_MESSAGES_HH
