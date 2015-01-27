#include <cstring>

#include "../tests.hpp"

extern "C" {
    int     ft_strncmp(const char *, const char *, size_t);
}

template <class T, size_t n, size_t m>
static bool test(const T (&t1)[n], const T (&t2)[m], size_t size)
{
    int     ret = ::strncmp(t1, t2, size);
    int     ft_ret = ::ft_strncmp(t1, t2, size);

    return (ret == ft_ret);
}

void test_strncmp_t::run()
{
    assert(test("lol", "lol", 3), "\"lol\" \"lol\"");
    assert(test("lal", "lel", 1), "\"lal\" \"lel\"");
    assert(test("Hello World!", "lolilolilol!", 12), "\"Hello World!\" \"lolilolilol!\"");
    assert(test("lol", "lolilol", 5), "\"lol\" \"lolilol\"");
    assert(test("lol\0a", "lol\0b", 5), "\"lol\\0a\" \"lol\\0b\"");
    assert(test("\200", "\0", 1), "\"\\200\" \"\\0\"");
    assert(test("", "lol", 3), "\"\" \"lol\"");
}
