#include "../tests.hpp"

extern "C" {
    int ft_tolower(int c);
}

void test_tolower_t::run()
{
    for (int i = 0; i <= (1 << sizeof(char) * 8); i++)
        assert(tolower(i) == ft_tolower(i), std::to_string(i));
}
