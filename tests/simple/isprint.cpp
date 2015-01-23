#include "../tests.hpp"

extern "C" {
    int ft_isprint(int c);
}

void test_isprint_t::run()
{
    for (int i = 0; i <= (1 << sizeof(char) * 8); i++)
        assert(isprint(i) == ft_isprint(i), std::to_string(i));
}
