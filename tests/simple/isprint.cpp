#include <iostream>
#include <ctype.h>
#include <assert.h>

extern "C" {
    int ft_isprint(int c);
}

void test_isprint() {
    for (int i = 32; i <= 126; i++)
        assert(isprint(i) == ft_isprint(i));
}