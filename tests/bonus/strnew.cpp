#include <cstring>
#include <limits>

#include "../tests.hpp"

extern "C" {
    char    *ft_strnew(size_t);
}

template <size_t n>
static bool test_one()
{
    const char zero[n + 1] = { 0 };

    char * ret = ft_strnew(n);
    bool result = strcmp(ret, zero);
    free(ret);
    return !result;
}

void test_strnew_t::run()
{
    assert(test_one<42>(), "Allocate 42 bytes");
    assert(ft_strnew(std::numeric_limits<size_t>::max()) == nullptr, "Too much");
}
