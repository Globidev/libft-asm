#include <cstring>

#include "../tests.hpp"

extern "C" {
    char *ft_strcat(char *dest, const char *src);
}

template <size_t n1, size_t n2>
static bool test_one(const char (&s1)[n1], const char (&s2)[n2])
{
    char dest[n1 + n2 - 1];
    char ft_dest[n1 + n2 - 1];

    std::memcpy(dest, s1, n1);
    std::memcpy(ft_dest, s1, n1);
    ::strcat(dest, s2);
    ::ft_strcat(ft_dest, s2);
    return !std::memcmp(dest, ft_dest, n1 + n2 - 1);
}

void test_strcat_t::run()
{
    assert(test_one("a", "b"), "\"a\" + \"b\"");
    assert(test_one("Hello", " World!"), "\"Hello\" + \"World!\"");
    assert(test_one("", ""), "empty");
}
