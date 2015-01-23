#include "test_base.hpp"

#include <iostream>

void test_base_t::assert(bool passed, const std::string & description)
{
    if (verbose)
    {
        std::cout.width(42);
        std::cout << std::endl;
    }

    if (passed)
    {
        if (verbose)
            std::cout << std::left << description << "\033[38;5;2m (passed)\033[0m";
        else
            std::cout << "\033[38;5;2m.\033[0m";
    }
    else
    {
        if (verbose)
            std::cout << std::left << description << "\033[38;5;1m (failed)\033[0m";
        else
            std::cout << "\033[38;5;1m.\033[0m";
    }
}
