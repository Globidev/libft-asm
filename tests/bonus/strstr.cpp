#include <cstring>
#include <iostream>

#include "../tests.hpp"

extern "C" {
    char    *ft_strstr(const char *, const char *);
}

static bool test_one(const char *s1, const char *s2)
{
    auto ret = std::strstr(s1, s2);
    auto ft_ret = ::ft_strstr(s1, s2);

    if (ret && ft_ret)
        return !strcmp(ret, ft_ret);
    else if (!ret && !ft_ret)
        return true;
    else
        return false;
}

void test_strstr_t::run()
{
    assert(test_one("Hello World!", "World"), "\"Hello World!\" \"World\"");
    assert(test_one("Worl World!", "World"), "\"Worl World!\" \"World\"");
    assert(test_one("Hello Worl", "World"), "\"Hello Worl\" \"World\"");
    assert(test_one("Hello World!", "Worlz"), "\"Hello World!\" \"Worlz\"");
    assert(test_one("Hello World!", "fail"), "\"Hello World!\" \"fail\"");
    assert(test_one("Hello World!", ""), "\"Hello World!\" \"\"");
    assert(test_one("", ""), "\"\" \"\"");
    assert(test_one("", "str"), "\"\" \"str\"");
}
