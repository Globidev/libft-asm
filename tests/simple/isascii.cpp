#include "../tests.hpp"

extern "C" {
    int ft_isascii(int c);
}

void test_isascii_t::run()
{
    for (int i = 0; i <= (1 << sizeof(char) * 8); i++)
        assert(isascii(i) == ft_isascii(i), std::to_string(i));
}
