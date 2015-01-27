#include <cstring>
#include <iostream>

#include "../tests.hpp"

extern "C" {
    char    *ft_strchr(const char *, int);
}

static bool test_one(const char *s, int i)
{
    auto ret = std::strchr(s, i);
    auto ft_ret = ::ft_strchr(s, i);

    if (ret && ft_ret)
        return !strcmp(ret, ft_ret);
    else if (!ret && !ft_ret)
        return true;
    else
        return false;
}

void test_strchr_t::run()
{
    assert(test_one("Hello World!", 'r'), "\"Hello World!\" \"r\"");
    assert(test_one("Hello World!", 'z'), "\"Hello World!\" \"z\"");
    assert(test_one("Hello World!", '\0'), "\"Hello World!\" \"\\0\"");
    assert(test_one("Hell\200o World!", '\200'), "\"Hell\200o World!\" \"\\200\"");
    assert(test_one("", '?'), "empty '?'");
    assert(test_one("lol", 'l'), "\"lol\" 'l'");
}
