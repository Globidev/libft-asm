#include "../tests.hpp"

extern "C" {
    int ft_toupper(int c);
}

void test_toupper_t::run()
{
    bool all_chars = true;
    for (int i = 0; i <= (1 << sizeof(char) * 8); i++)
        all_chars &= (std::toupper(i) == ::ft_toupper(i));
    assert(all_chars, "int from 0 to " + std::to_string(1 << sizeof(char) * 8));
}
