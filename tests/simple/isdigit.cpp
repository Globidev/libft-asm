#include <cassert>
#include <cctype>
#include <iostream>

extern "C" {
    int ft_isdigit(int c);
}

void test_isdigit() {
    for (int i = 0; i <= (1 << sizeof(char) * 8); i++)
        assert(std::isdigit(i) == ft_isdigit(i));
}
