#include <ctype.h>
#include <assert.h>

extern "C" {
    int ft_isascii(int c);
}

void test_isascii() {
    for (int i = 0; i <= 127; i++)
        assert(isascii(i) == ft_isascii(i));
}
