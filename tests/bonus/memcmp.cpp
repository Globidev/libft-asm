#include <cstring>

#include "../tests.hpp"

extern "C" {
    int     ft_memcmp(const void *, const void *, size_t);
}

template <class T, size_t n, size_t m>
static bool test(const T (&t1)[n], const T (&t2)[m], size_t size)
{
    int     ret = ::memcmp(t1, t2, size);
    int     ft_ret = ::ft_memcmp(t1, t2, size);

    return (ret == ft_ret);
}

void test_memcmp_t::run()
{
    int     tab1[3] = {1, 2, 4};
    int     tab2[3] = {1, 2, 3};

    assert(test("lol", "lol", 3 * sizeof(char)), "\"lol\" \"lol\"");
    assert(test("Hello World!", "lolilolilol!", 12 * sizeof(char)), "\"Hello World!\" \"lolilolilol!\"");
    assert(test("\200", "\0", 1 * sizeof(char)), "\"\\200\" \"\\0\"");
    assert(test(tab1, tab1, 3 * sizeof(int)), "\"{1, 2, 3}\" \"{1, 2, 3}\"");
    assert(test(tab1, tab2, 3 * sizeof(int)), "\"{1, 2, 3}\" \"{1, 2, 4}\"");
    assert(test(tab1, tab2, 2 * sizeof(int)), "\"{1, 2, 3}\" \"{1, 2, 4}\" 2 firsts");
}
