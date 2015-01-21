#include <cassert>
#include <cctype>
#include <iostream>

extern "C" {
    int ft_isalpha(int c);
}

static void    test(int c) {
    int systemCall;
    int betonniereCall;

    systemCall = std::isalpha(c);
    betonniereCall = ft_isalpha(c);
    assert(systemCall == betonniereCall);
}

void test_isalpha() {
    for (int i = 0; i <= (2 << sizeof(char)); i++)
        test(i);
}