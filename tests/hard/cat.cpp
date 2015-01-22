#include <cstring>
#include <cassert>
#include <iostream>

extern "C" {
    void    ft_cat(int);
}

void test_cat()
{
    ft_cat(0);
}
