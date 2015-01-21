#include <algorithm>
#include <cstring>
#include <cassert>

extern "C" {
	void ft_bzero(void *, size_t);
}

template <class T, size_t n, class Generator>
static void test_one(Generator generator)
{
	T buff1[n];
	T buff2[n];
	constexpr size_t mem_size = n * sizeof(T);
	std::generate(buff1, buff1 + n, generator);
	std::generate(buff2, buff2 + n, generator);

	ft_bzero(buff1, mem_size);
	::bzero(buff2, mem_size);

	assert(!std::memcmp(buff1, buff2, mem_size));
}

void test_bzero()
{
	struct test_t { int a; char c; double d; };
	auto gen_test = []() {
		return test_t { std::rand(), (char)std::rand(), (double)std::rand() };
	};
	test_one<char, 42>(std::rand);
	test_one<int, 1337>(std::rand);
	test_one<double, 10>(std::rand);
	test_one<test_t, 42>(gen_test);
}
