#include <cstring>
#include <cassert>
#include <iostream>

extern "C" {
    void    *ft_memchr(const void *, int, size_t);
}

void test_memchr()
{
    char    *systemCall;
    char    *betonicCall;
    size_t  size = 20;
    char    str[] = "Hello World";

    systemCall = (char*)memchr(str, 111, size);
    betonicCall = (char*)ft_memchr(str, 111, size);

    std::cout << (void*)systemCall << std::endl;
    std::cout << (void*)betonicCall << std::endl;

    if (systemCall && betonicCall)
        assert(!memcmp(systemCall, betonicCall, size));
}
