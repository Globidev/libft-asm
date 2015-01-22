#include <cstring>
#include <cassert>
#include <iostream>

extern "C" {
    void    *ft_memccpy(void *, const void *, int, size_t);
}

void test_memccpy()
{
    char    *systemCall;
    char    *betonicCall;
    size_t  size = 6;
    char    str_sys[] = "Hello World";
    char    str_bet[] = "lolilolilol";
    char    str_sys2[] = "Hello World";
    char    str_bet2[] = "lolilolilol";

    systemCall = (char*)memccpy(str_sys, str_bet, 'a', size);
    betonicCall = (char*)ft_memccpy(str_sys2, str_bet2, 'a', size);

    std::cout << systemCall << std::endl;
    std::cout << betonicCall << std::endl;

    assert(!memcmp(systemCall, betonicCall, size));
}