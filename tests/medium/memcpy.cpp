#include <cstring>

#include "../tests.hpp"

extern "C" {
    void    *ft_memcpy(void *, const void *, size_t);
}

template <size_t n, class T, size_t src_n>
static bool test_one(const T (&src)[src_n], const T * to_cpy)
{
    T buff1[n];
    T buff2[n];

    std::memcpy(buff1, src, src_n * sizeof(T));
    std::memcpy(buff2, src, src_n * sizeof(T));

    auto ret = std::memcpy(buff1, to_cpy, n * sizeof(T));
    auto ft_ret = std::memcpy(buff2, to_cpy, n * sizeof(T));

    return !memcmp(ret, ft_ret, n * sizeof(T));
}

void test_memcpy_t::run()
{
    assert(test_one<11>("Hello World", "lolilolilol"), "\"Hello World\" \"lolilolilol\" 11");
}
