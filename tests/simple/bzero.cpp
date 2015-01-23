#include <algorithm>
#include <cstring>

#include "../tests.hpp"

extern "C" {
    void ft_bzero(void *, size_t);
}

template <class T, size_t n, class Generator>
static bool test_full_range(Generator generator)
{
    T buff_ref[n];
    T buff1[n];
    T buff2[n];
    constexpr size_t mem_size = n * sizeof(T);

    std::generate(buff_ref, buff_ref + n, generator);
    std::memcpy(buff1, buff_ref, mem_size);
    std::memcpy(buff2, buff_ref, mem_size);

    ::ft_bzero(buff1, mem_size);
    ::bzero(buff2, mem_size);

    return !std::memcmp(buff1, buff2, mem_size);
}

template <class T, size_t n, class Generator>
static bool test_partial(Generator generator, size_t len)
{
    T buff_ref[n];
    T buff1[n];
    T buff2[n];
    constexpr size_t mem_size = n * sizeof(T);

    std::generate(buff_ref, buff_ref + n, generator);
    std::memcpy(buff1, buff_ref, mem_size);
    std::memcpy(buff2, buff_ref, mem_size);

    ::ft_bzero(buff1, len * sizeof(T));
    ::bzero(buff2, len * sizeof(T));

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

    assert(test_full_range<char, 42>(std::rand), "42 random chars");
    assert(test_full_range<int, 1337>(std::rand), "1337 random ints");
    assert(test_full_range<double, 42>(std::rand), "42 random doubles");
    assert(test_full_range<test_t, 42>(gen_test), "42 random structs");

    assert(test_partial <char, 42>(std::rand, 10), "42 random chars (10 firsts)");
    assert(test_partial <int, 1337>(std::rand, 10), "1337 random ints (10 firsts)");
    assert(test_partial <double, 42>(std::rand, 10), "42 random doubles (10 firsts)");
    assert(test_partial <test_t, 42>(gen_test, 10), "42 random structs (10 firsts)");
}
