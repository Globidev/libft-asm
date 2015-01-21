#include <iostream>
#include <cstring>
#include <cassert>

extern "C" {
    char *ft_strcat(char *dest, const char *src);
}

template <size_t n1, size_t n2>
static void test_one(const char (&s1)[n1], const char (&s2)[n2])
{
    char dest[n1 + n2 - 1];
    char ft_dest[n1 + n2 - 1];

    std::memcpy(dest, s1, n1);
    std::memcpy(ft_dest, s1, n1);
    ::strcat(dest, s2);
    ::ft_strcat(ft_dest, s2);
    assert (!std::memcmp(dest, ft_dest, n1 + n2 - 1));
}

void    test_strcat()
{
    test_one("a", "b");
    test_one("Hello", " World!");
    test_one("", "");
}
