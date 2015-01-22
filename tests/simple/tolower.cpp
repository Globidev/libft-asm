#include <cassert>
#include <cctype>

extern "C" {
    int ft_tolower(int c);
}

void test_tolower() {
    for (int i = 0; i <= (1 << sizeof(char) * 8); i++)
        assert(std::tolower(i) == ft_tolower(i));
}
