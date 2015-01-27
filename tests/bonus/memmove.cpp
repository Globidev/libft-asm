#include <cstring>

#include "../tests.hpp"

extern "C" {
    void    *ft_memmove(void *, const void *, size_t);
}

template <class T, size_t n, size_t m>
static bool test_one(const T (&t1)[n], const T (&t2)[m], size_t size)
{
    T buff1[n];
    T buff2[n];

    std::memcpy(buff1, t1, n * sizeof(T));
    std::memcpy(buff2, t1, n * sizeof(T));

    auto ret = std::memmove(buff1, t2, size * sizeof(T));
    auto ft_ret = ::ft_memmove(buff2, t2, size * sizeof(T));

    return !memcmp(ret, ft_ret, size * sizeof(T));
}

void test_memmove_t::run()
{
    assert(test_one("Hello World", "lolilolilol", 12), "\"Hello World\" \"lolilolilol\" 12");
    assert(test_one("Hello World", "lolilol", 8), "\"Hello World\" \"lolilol\" 8");
    assert(test_one("Hello World", "", 1), "\"Hello World\" empty 1");
    assert(test_one("", "Hello World", 12), "empty \"Hello World\" 12");
    assert(test_one("", "", 10), "empty empty 10");
}
