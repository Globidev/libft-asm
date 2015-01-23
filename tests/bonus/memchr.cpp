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

void test_memchr_t::run()
{
    assert(test_one("Hello World!", 'o'), "\"Hello World!\" 'o'");
}
