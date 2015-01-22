#include <cstring>
#include <cassert>
#include <iostream>

extern "C" {
    char    *ft_strdup(const char *);
}

static void test_one(const char * str)
{
    char * dup;
    char * ft_dup;

    dup = ::strdup(str);
    ft_dup = ft_strdup(str);
    assert(strlen(dup) == strlen(ft_dup));
    assert(!memcmp(str, dup, strlen(dup)));
    free(dup);
    free(ft_dup);
}

void test_strdup()
{
    test_one("Hello");
    test_one("");
}
