#include <cstring>

#include "../tests.hpp"

extern "C" {
    int		ft_atoi(const char *);
}

template <class T, size_t n>
static bool test(const T (&t1)[n])
{
	int		ret = ::atoi(t1);
	int		ft_ret = ::ft_atoi(t1);

	// debug(ret, ft_ret);

    return (ret == ft_ret);
}

void test_atoi_t::run()
{
    assert(test(""), "\"\"");
    assert(test("0"), "\"0\"");
    assert(test("1"), "\"1\"");
    assert(test("-1"), "\"-1\"");
    assert(test("123"), "\"123\"");
    assert(test("2147483647"), "\"2147483647\"");
    assert(test("-2147483648"), "\"-2147483648\"");
    assert(test("abcdefg"), "\"abcdefg\"");
    assert(test("L O L404"), "\"L O L404\"");
    assert(test("404Hype"), "\"404Hype\"");
}
