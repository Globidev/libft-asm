#include <algorithm>
#include <cstring>

#include "../tests.hpp"

extern "C" {
    void ft_bzero(void *, size_t);
}

template <class T, size_t n, class Generator>
static bool test_one(Generator generator)
{
    T buff1[n];
    T buff2[n];
    constexpr size_t mem_size = n * sizeof(T);

    std::generate(buff1, buff1 + n, generator);
    std::generate(buff2, buff2 + n, generator);

    ::ft_bzero(buff1, mem_size);
    ::bzero(buff2, mem_size);

    return !std::memcmp(buff1, buff2, mem_size);
}

void test_bzero_t::run()
{
    struct test_t { int a; char c; double d; };
    auto gen_test = []() {
        return test_t {
            std::rand(),
            (char)std::rand(),
            (double)std::rand()
        };
    };

    assert(test_one<char, 42>(std::rand), "42 random chars");
    assert(test_one<int, 1337>(std::rand), "1337 random ints");
    assert(test_one<double, 42>(std::rand), "42 random doubles");
    assert(test_one<test_t, 42>(gen_test), "42 random structs");

}
