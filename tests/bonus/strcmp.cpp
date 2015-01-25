#include <cstring>

#include "../tests.hpp"

extern "C" {
    int     ft_strcmp(const char *, const char *);
}

template <class T, size_t n, size_t m>
static bool test(const T (&t1)[n], const T (&t2)[m])
{
    int     ret = ::strcmp(t1, t2);
    int     ft_ret = ::ft_strcmp(t1, t2);

    debug(ret, ft_ret);

    return (ret == ft_ret);
}

void test_strcmp_t::run()
{
    assert(test("lol", "lol"), "\"lol\" \"lol\"");
    assert(test("Hello World!", "lolilolilol!"), "\"Hello World!\" \"lolilolilol!\"");
    assert(test("lol", "lolilol"), "\"lol\" \"lolilol\"");
    assert(test("lol\0a", "lol\0b"), "\"lol\\0a\" \"lol\\0b\"");
    assert(test("\200", "\0"), "\"\\200\" \"\\0\"");
    assert(test("", "lol"), "\"\" \"lol\"");
}
