#include <cstring>

#include "../tests.hpp"

extern "C" {
    size_t ft_strlen(const char *);
}

static bool test_one(const char * str)
{
    auto strlen_ret = ::strlen(str); // System call
    auto ft_strlen_ret = ::ft_strlen(str); // Betonic call
    return strlen_ret == ft_strlen_ret;
}

void test_strlen_t::run()
{
    assert(test_one("Hello World"), "\"Hello World\"");
    assert(test_one(""), "empty string");
}
