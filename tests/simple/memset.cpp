#include <cstring>
#include <cassert>
#include <iostream>

extern "C" {
    void    *ft_memset(void *, int, size_t);
}

void test_memset()
{
    char    *systemCall;
    char    *betonicCall;
    size_t  size = 11;
    char    str_sys[] = "Hello World";
    char    str_bet[] = "Hello World";

    systemCall = (char*)memset(str_sys, 97, size);
    betonicCall = (char*)ft_memset(str_bet, 97, size);

    std::cout << systemCall << std::endl;
    std::cout << betonicCall << std::endl;

    assert(!memcmp(systemCall, betonicCall, size));
}
