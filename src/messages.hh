#ifndef EXPLAIN_MESSAGES_HH
#define EXPLAIN_MESSAGES_HH

#include <cstdlib>
#include <iostream>
#include <string>


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

    static constexpr auto BOLD_BLACK = "\033[1m\033[30m";
    static constexpr auto BOLD_RED = "\033[1m\033[31m";
    static constexpr auto BOLD_GREEN = "\033[1m\033[32m";
    static constexpr auto BOLD_YELLOW = "\033[1m\033[33m";
    static constexpr auto BOLD_BLUE = "\033[1m\033[34m";
    static constexpr auto BOLD_MAGENTA = "\033[1m\033[35m";
    static constexpr auto BOLD_CYAN = "\033[1m\033[36m";
    static constexpr auto BOLD_WHITE = "\033[1m\033[37m";
public:
    MessageIssuer()
        : warningCount(0), errorCount(0) {}

    void
    message(const std::string& msg)
    {
        std::cerr << BOLD_YELLOW << "message: " << RESET << msg << std::endl;
    }

    void
    warning(const std::string& msg)
    {
        std::cerr << BOLD_MAGENTA << "warning: " << RESET << msg << std::endl;

        warningCount++;
    }

    void
    error(const std::string& msg)
    {
        std::cerr << BOLD_RED << "error: " << RESET << msg << std::endl;

        errorCount++;
    }

    void
    fatal_error(const std::string& msg)
    {
        std::cerr << BOLD_WHITE << "fatal error: " << RESET << msg << std::endl;
        std::exit(EXIT_FAILURE);
    }

    int
    getErrorCount()
    {
        return errorCount;
    }
};

}

#endif //EXPLAIN_MESSAGES_HH
