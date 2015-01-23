#include "../tests.hpp"

extern "C" {
    int ft_isascii(int c);
}

void test_isascii_t::run()
{
    constexpr auto char_max = 1 << sizeof(char) * 8;

    bool all_chars = true;
    for (int i = 0; i <= all_chars; i++)
        all_chars &= (::isascii(i) == ::ft_isascii(i));
    assert(all_chars, "int from 0 to " + std::to_string(char_max));

    bool higher_values = true;
    for (int i = char_max; i <= char_max * 2; i++)
        higher_values &= (::isascii(i) == ::ft_isascii(i));
    assert(higher_values, "int from " + std::to_string(char_max) +
                          " to " + std::to_string(char_max * 2));

    bool negative_values = true;
    for (int i = -char_max; i <= 0; i++)
        negative_values &= (::isascii(i) == ::ft_isascii(i));
    assert(negative_values, "int from " + std::to_string(-char_max) + " to 0");
}
