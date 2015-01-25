#include <cstring>

#include "../tests.hpp"

extern "C" {
    void    *ft_memset(void *, int, size_t);
}

template <size_t n, class T, size_t n_src>
static bool test_one(const T (&src)[n_src], int c)
{
    T buff1[n];
    T buff2[n];

    std::memcpy(buff1, src, n_src * sizeof(T));
    std::memcpy(buff1, src, n_src * sizeof(T));

    auto ret = std::memset(buff1, c, n);
    auto ft_ret = ::ft_memset(buff2, c, n);

    return !std::memcmp(ret, ft_ret, n * sizeof(T));
}

void test_memset_t::run()
{
    assert(test_one<11>("Hello World!", 'a'), "\"Hello World!\" 'a' 11");
    assert(test_one<1>("Hello World!", 'a'), "\"Hello World!\" 'a' 1");
    assert(test_one<0>("Hello World!", 'a'), "\"Hello World!\" 'a' 0");
}
