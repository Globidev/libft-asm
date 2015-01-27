#include <cstring>

#include "../tests.hpp"

extern "C" {
    char *ft_strncat(char *dest, const char *src, size_t n);
}

template <size_t n1, size_t n2>
static bool test_full(const char (&s1)[n1], const char (&s2)[n2], size_t size)
{
    char dest[n1 + n2 - 1];
    char ft_dest[n1 + n2 - 1];

    std::memcpy(dest, s1, n1);
    std::memcpy(ft_dest, s1, n1);
    ::strncat(dest, s2, size);
    ::ft_strncat(ft_dest, s2, size);

    return !std::memcmp(dest, ft_dest, n1 + size - 1);
}

void test_strncat_t::run()
{
    assert(test_full("a", "b", 1), "\"a\" + \"b\" 1");
    assert(test_full("Hello", " World!", 7), "\"Hello\" + \"World!\" 7");
    assert(test_full("", "", 1), "empty 1");
    assert(test_full("lol", "", 1), "\"lol\" empty 1");
    assert(test_full("", "lol", 4), "empty \"lol\" 4");
}
