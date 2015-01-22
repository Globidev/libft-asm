#include <cstring>
#include <cassert>
#include <iostream>

extern "C" {
    void    *ft_memcpy(void *, const void *, size_t);
}

void test_memcpy()
{
    // char    *systemCall;
    char    *betonicCall;
    size_t  size = 11;
    char    str_sys[] = "Hello World";
    char    str_bet[] = "lolilolilol";

    // systemCall = (char*)memcpy(str_sys, str_bet, size);
    betonicCall = (char*)ft_memcpy(str_sys, str_bet, size);

    // std::cout << systemCall << std::endl;
    std::cout << betonicCall << std::endl;

    // assert(!memcmp(systemCall, betonicCall, size));
}
