#include "../tests.hpp"

extern "C" {
    int ft_isalnum(int c);
}

void test_isalnum_t::run()
{
    for (int i = 0; i <= (1 << sizeof(char) * 8); i++)
        assert(std::isalnum(i) == ::ft_isalnum(i), std::to_string(i));
}
