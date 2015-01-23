#include "../tests.hpp"

extern "C" {
    int ft_isprint(int c);
}

void test_isprint_t::run()
{
    bool all_chars = true;
    for (int i = 0; i <= (1 << sizeof(char) * 8); i++)
        all_chars &= (std::isprint(i) == ::ft_isprint(i));
    assert(all_chars, "int from 0 to " + std::to_string(1 << sizeof(char) * 8));
}
