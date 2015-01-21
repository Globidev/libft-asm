#include <cstdio>
#include <cassert>
#include <iostream>
#include <sstream>
#include <utility>
#include <algorithm>

#include <unistd.h>

static const auto BUFF_MAX_SIZE = 1024;

extern "C" {
    int ft_puts(const char *);
}

using puts_ret_t = std::pair<std::string, int>;

template <class F>
static puts_ret_t puts_call(const F & f, const char * str)
{
    char buff[BUFF_MAX_SIZE];
    int fds[2];
    int saved_stdout;

    assert(!pipe(fds));
    saved_stdout = dup(STDOUT_FILENO);
    dup2(fds[1], STDOUT_FILENO);
    close(fds[1]);
    int ret = f(str);
    fflush(stdout);
    read(fds[0], buff, BUFF_MAX_SIZE);
    dup2(saved_stdout, STDOUT_FILENO);

    return std::make_pair(std::string(buff), ret);
}

static void test_one(const char * str)
{
    auto puts_ret = puts_call(std::puts, str);
    auto ft_puts_ret = puts_call(std::puts, str);
    assert(puts_ret == ft_puts_ret);
}

void test_puts()
{
    test_one("Hello World");

    std::string wtf;
    wtf.resize(BUFF_MAX_SIZE);
    std::generate(wtf.begin(), wtf.end(), std::rand);
    test_one(wtf.c_str());
}
