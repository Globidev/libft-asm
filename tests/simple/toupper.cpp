#include "../tests.hpp"

extern "C" {
    int ft_toupper(int c);
}

static bool test_range(int start, int end)
{
    bool ok = true;
    for (int i = start; i < end; ++i)
        ok &= (std::toupper(i) == ::ft_toupper(i));
    return ok;
}

void test_toupper_t::run()
{
    constexpr auto char_max = 1 << sizeof(char) * 8;

    assert(test_range(0, char_max), "int from 0 to " + std::to_string(char_max));
    assert(test_range(char_max, char_max * 2), "int from " + std::to_string(char_max) +
                                               " to " + std::to_string(char_max * 2));
    assert(test_range(-char_max, 0), "int from " + std::to_string(-char_max) + " to 0");
}
