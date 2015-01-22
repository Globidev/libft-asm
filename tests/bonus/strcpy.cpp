#include <cstring>
#include <cassert>
#include <iostream>

extern "C" {
    char    *ft_strcpy(char *, const char *);
}

void test_strcpy()
{
    char    *systemCall;
    char    *betonicCall;
    char    dst_sys[] = "Hello World";
    char    src_sys[] = "lolilolilol";
    char    dst_bet[] = "Hello World";
    char    src_bet[] = "lolilolilol";

    systemCall = strcpy(dst_sys, src_sys);
    betonicCall = ft_strcpy(dst_bet, src_bet);

    std::cout << systemCall << std::endl;
    std::cout << betonicCall << std::endl;

    // assert(!strcmp(systemCall, betonicCall));
}
