#include <cstring>
#include <cassert>
#include <iostream>

extern "C" {
    size_t ft_strlen(const char *);
}

void test_strlen()
{
    size_t  systemCall;
    size_t  betonicCall;
    char    str[] = "Hello World";

    systemCall = strlen(str);
    betonicCall = ft_strlen(str);

    std::cout << systemCall << std::endl;
    std::cout << betonicCall << std::endl;

    assert(systemCall == betonicCall);
}
