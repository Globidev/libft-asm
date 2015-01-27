#include <cstring>
#include <iostream>

#include "../tests.hpp"

extern "C" {
    char    *ft_strcpy(char *, const char *);
}

template <size_t n>
static bool test_one(const char (&dst)[n], const char * src)
{
    char    buff1[n];
    char    buff2[n];

    std::memcpy(buff1, dst, n);
    std::memcpy(buff2, dst, n);

    auto ret = std::strcpy(buff1, src);
    auto ft_ret = ::ft_strcpy(buff2, src);

    return !strcmp(ret, ft_ret);
}

void test_strcpy_t::run()
{
    assert(test_one("Hello World!", "lol"), "\"Hello World!\" \"lol\"");
    assert(test_one("abc", "lol"), "\"abc\" \"lol\"");
    assert(test_one("loul", "ab\0c"), "\"loul\" \"ab\\0c\"");
}
