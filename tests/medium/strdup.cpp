#include <cstring>
#include <cstdlib>

#include "../tests.hpp"

extern "C" {
    char    *ft_strdup(const char *);
}

static bool test_one(const char * str)
{
    char * dup;
    char * ft_dup;

    dup = ::strdup(str);
    ft_dup = ::ft_strdup(str);
    bool ok = strlen(dup) == strlen(ft_dup) && !memcmp(str, dup, strlen(dup));
    free(dup);
    free(ft_dup);
    return ok;
}

void test_strdup_t::run()
{
    assert(test_one("Hello"), "\"Hello\"");
    assert(test_one(""), "empty");
}
