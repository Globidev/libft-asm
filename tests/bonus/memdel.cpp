#include <cstring>
#include <cassert>
#include <iostream>

extern "C" {
    void    ft_memdel(void **);
}

void test_memdel()
{
    char    *str_bet = (char*)malloc(4);

    strcpy(str_bet, "lol");

    ft_memdel((void**)&str_bet);

    std::cout << (void*)str_bet << std::endl;

    assert(!str_bet);
}
