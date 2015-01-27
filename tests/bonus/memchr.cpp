#include <cstring>

#include "../tests.hpp"

extern "C" {
    void    *ft_memchr(const void *, int, size_t);
}

template <class T, size_t n>
static bool test_one(const T (&t)[n], int c)
{
    return ::memchr(t, c, n) == ::ft_memchr(t, c, n);
}

template <class T, size_t n>
static bool test_two(const T (&t)[n], int c, size_t len)
{
    return ::memchr(t, c, len) == ::ft_memchr(t, c, len);
}

void test_memchr_t::run()
{
    assert(test_one("Hello World!", 'o'), "\"Hello World!\" 'o'");
    assert(test_one("Hello World!", 'q'), "\"Hello World!\" 'q'");
    assert(test_one("Hello World!", '!'), "\"Hello World!\" '!'");
    assert(test_one("", '?'), "empty '?'");
    assert(test_one("lol", '\0'), "\"lol\" 0");
    assert(test_two("lol", 'l', 0), "\"lol\" 'l' 0");
    assert(test_two("lol", 'p', 42), "\"lol\" 'p' 42");
    assert(test_two("", '?', 42), "empty '?' 42");
}
