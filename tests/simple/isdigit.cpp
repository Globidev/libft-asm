#include <cassert>
#include <cctype>
#include <iostream>

extern "C" {
    int ft_isdigit(int c);
}

static void    test(int c) {
    int systemCall;
    int betonniereCall;

    systemCall = std::isdigit(c);
    betonniereCall = ft_isdigit(c);
    assert(systemCall == betonniereCall);
}

void test_isdigit() {
    for (int i = 48; i <= 57; i++)
        test(i);
}
