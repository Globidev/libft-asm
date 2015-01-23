#include "../tests.hpp"

extern "C" {
    int ft_toupper(int c);
}

void test_toupper_t::run()
{
    for (int i = 0; i <= (1 << sizeof(char) * 8); i++)
        assert(toupper(i) == ft_toupper(i), std::to_string(i));
}
