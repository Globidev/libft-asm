#include "../tests.hpp"

extern "C" {
    int ft_tolower(int c);
}

void test_tolower_t::run()
{
    bool all_chars = true;
    for (int i = 0; i <= (1 << sizeof(char) * 8); i++)
        all_chars &= (std::tolower(i) == ::ft_tolower(i));
    assert(all_chars, "int from 0 to " + std::to_string(1 << sizeof(char) * 8));
}
