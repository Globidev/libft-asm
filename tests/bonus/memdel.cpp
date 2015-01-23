#include <cstring>
#include <cstdlib>

#include "../tests.hpp"

extern "C" {
    void    ft_memdel(void **);
}

template <class T, size_t n>
static bool test_one(const T (&t)[n])
{
    T * allocated = (T *)malloc(n * sizeof(T));

    std::memcpy(allocated, t, n * sizeof(T));
    ft_memdel((void**)&allocated);
    return !allocated;
}

void test_memdel_t::run()
{
    assert(test_one("Hello World!"), "\"Hello World!\"");
}
