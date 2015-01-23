#include <cstring>
#include <iostream>

#include "../tests.hpp"

extern "C" {
    char    *ft_strncpy(char *, const char *, size_t);
}

template <size_t n>
static bool test_one(const char (&dst)[n], const char * src, size_t i)
{
    char    buff1[n];
    char    buff2[n];

    std::memcpy(buff1, dst, n);
    std::memcpy(buff2, dst, n);

    auto ret = std::strncpy(buff1, src, i);
    auto ft_ret = ::ft_strncpy(buff2, src, i);

    debug(ret, ft_ret);

    return !strcmp(ret, ft_ret);
}

template <size_t n>
static bool test_two(const char (&dst)[n], const char * src, size_t i)
{
    char    buff1[50];
    char    buff2[50];

    std::memcpy(buff1, dst, n);
    std::memcpy(buff2, dst, n);

    auto ret = std::strncpy(buff1, src, i);
    auto ft_ret = ::ft_strncpy(buff2, src, i);

    debug(ret, ft_ret);

    return !strcmp(ret, ft_ret);
}


void test_strncpy_t::run()
{
    assert(test_one("Hello World!", "abc", 3), "\"Hello World!\" \"abc\" 3");
    assert(test_one("Hello World!", "abc", 6), "\"Hello World!\" \"abc\" 6");
    assert(test_one("Hello World!", "abc", 0), "\"Hello World!\" \"abc\" 0");
    assert(test_two("abc", "Hello World!", 50), "\"abc\" \"Hello World!\" 50");
}