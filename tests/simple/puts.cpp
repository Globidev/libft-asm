#include <algorithm>
#include <unistd.h>

#include "../tests.hpp"

extern "C" {
    int ft_puts(const char *);
}

static const auto BUFF_MAX_SIZE = 1024;

template <class F>
static auto puts_call(const F & f, const char * str)
{
    char buff[BUFF_MAX_SIZE];
    int fds[2];
    int saved_stdout;

    pipe(fds);
    saved_stdout = dup(STDOUT_FILENO);
    dup2(fds[1], STDOUT_FILENO);
    close(fds[1]);
    int ret = f(str);
    fflush(stdout);
    read(fds[0], buff, BUFF_MAX_SIZE);
    dup2(saved_stdout, STDOUT_FILENO);

    return std::make_pair(std::string(buff), ret);
}

static bool test_one(const char * str)
{
    auto puts_ret = puts_call(std::puts, str);
    auto ft_puts_ret = puts_call(::ft_puts, str);
    return puts_ret == ft_puts_ret;
}

void test_puts_t::run()
{
    assert(test_one("Hello World"), "\"Hello World\"");

    std::string wtf;
    wtf.resize(BUFF_MAX_SIZE);
    std::generate(wtf.begin(), wtf.end(), std::rand);
    assert(test_one(wtf.c_str()), "random string of " + std::to_string(BUFF_MAX_SIZE) + " numbers");
}
