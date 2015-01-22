#include <cassert>
#include <cctype>

extern "C" {
    int ft_toupper(int c);
}

// Thanks bchevali for your test

void test_toupper() {
    for (int i = 0; i <= (1 << sizeof(char) * 8); i++)
        assert(std::toupper(i) == ft_toupper(i));
}
