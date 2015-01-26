#include <cstring>

#include "../tests.hpp"

extern "C" {
    void    *ft_memccpy(void *, const void *, int, size_t);
}

template <size_t n, class T, size_t src_n>
static bool test_one(const T (&src)[src_n], const T * to_cpy, int c)
{
    T buff1[src_n];
    T buff2[src_n];

    std::memcpy(buff1, src, src_n * sizeof(T));
    std::memcpy(buff2, src, src_n * sizeof(T));

    auto ret = ::memccpy(buff1, to_cpy, c, n * sizeof(T));
    auto ft_ret = ::ft_memccpy(buff2, to_cpy, c, n * sizeof(T));

    bool mem_ok = !memcmp(buff1, buff2, src_n * sizeof(T));
    return mem_ok && ((!ret && !ft_ret) ||
                      ((char *)ret - buff1) == ((char *)ft_ret - buff2));
}

void test_memccpy_t::run()
{
    assert(test_one<11>("Hello World", "lolilolilol", 'o'), "\"Hello World\" \"lolilolilol\" 'o' 11");
    assert(test_one<2>("Hello World", "lolilolilol", 'o'), "\"Hello World\" \"lolilolilol\" 'o' 2");
    assert(test_one<0>("Hello World", "lolilolilol", 'o'), "\"Hello World\" \"lolilolilol\" 'o' 0");
    assert(test_one<42>("", "", 0), "empty empty 0 42");
    assert(::memccpy(0, 0, 0, 0) == ::ft_memccpy(0, 0, 0, 0), "0 0 0 0");
}
