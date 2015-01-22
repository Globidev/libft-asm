#include <cassert>
#include <cctype>

extern "C" {
    int ft_isalpha(int c);
}

void test_isalpha() {
    for (int i = 0; i <= (1 << sizeof(char) * 8); i++)
        assert(std::isalpha(i) == ft_isalpha(i));
}
