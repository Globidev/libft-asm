#include <cstring>
#include <cassert>
#include <iostream>

extern "C" {
    size_t ft_strlen(const char *);
}

static void test_one(const char * str)
{
    auto strlen_ret = ::strlen(str); // System call
    auto ft_strlen_ret = ::ft_strlen(str); // Betonic call
    assert(strlen_ret == ft_strlen_ret);
}

void test_strlen()
{
    test_one("Hello World");
    test_one("");
}
