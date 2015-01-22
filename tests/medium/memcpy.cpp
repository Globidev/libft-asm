#include <cstring>
#include <cassert>
#include <iostream>

extern "C" {
    void    *ft_memcpy(void *, const void *, size_t);
}

void test_memcpy()
{
    char    *systemCall;
    char    *betonicCall;
    size_t  size = 11;
    char    dst_sys[] = "Hello World";
    char    src_sys[] = "lolilolilol";
    char    dst_bet[] = "Hello World";
    char    src_bet[] = "lolilolilol";

    systemCall = (char*)memcpy(dst_sys, src_sys, size);
    betonicCall = (char*)ft_memcpy(dst_bet, src_bet, size);

    std::cout << systemCall << std::endl;
    std::cout << betonicCall << std::endl;

    assert(!memcmp(systemCall, betonicCall, size));
}
