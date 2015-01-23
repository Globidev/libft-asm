#include <cstring>

#include "../tests.hpp"

extern "C" {
    void    *ft_memalloc(size_t);
}

template <size_t n>
static bool test_one()
{
    char zero[n] = { 0 };

    void * ret = ft_memalloc(n);
    bool result = !std::memcmp(ret, zero, n);
    free(ret);
    return result;
}

void test_memalloc_t::run()
{
    assert(test_one<42>(), "Allocate 42 bytes");
}
