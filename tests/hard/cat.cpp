#include <algorithm>
#include <fstream>
#include <cstring>
#include <unistd.h>
#include <fcntl.h>

#include "../tests.hpp"

extern "C" {
    void    ft_cat(int);
}

static const auto BUFF_MAX_SIZE = 1024;
static const auto TEST_FILE = "/tmp/test_ft_cat";

static bool test_some_file()
{
    int fd;
    std::string ref;
    char buff[BUFF_MAX_SIZE];
    int fds[2];
    int saved_stdout;

    ref.resize(BUFF_MAX_SIZE);
    std::generate(ref.begin(), ref.end(), std::rand);
    std::ofstream ofs(TEST_FILE);
    ofs << ref;
    ofs.close();

    // /!\ the pipe blocks if the buff size is too large
    fd = open(TEST_FILE, O_RDONLY);
    fflush(stdout);
    pipe(fds);
    saved_stdout = dup(STDOUT_FILENO);
    dup2(fds[1], STDOUT_FILENO);
    close(fds[1]);
    ft_cat(fd);
    close(fd);
    fflush(stdout);
    read(fds[0], buff, BUFF_MAX_SIZE);
    dup2(saved_stdout, STDOUT_FILENO);

    return !std::memcmp(ref.c_str(), buff, BUFF_MAX_SIZE);
}

static bool test_invalid()
{
    ft_cat(1337);
    // Nothing should be printed to the terminal and it should not hang
    return true;
}


void test_cat_t::run()
{
    assert(test_some_file(), "valid fd");
    assert(test_invalid(), "invalid fd");
}
