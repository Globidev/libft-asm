#include <unordered_map>
#include <vector>
#include <ctime>
#include <memory>

#include "tests.hpp"

using namespace std::string_literals;
static const auto ALL_STRING = "all"s;
static const auto VERBOSE_FLAG = "-v"s;

bool test_base_t::verbose = false;

using base_map_t = std::unordered_map<std::string, std::unique_ptr<test_base_t>>;
struct test_map_t: public base_map_t
{
    test_map_t(): base_map_t()
    {
        // Simple
        (*this)["bzero"].reset(new test_bzero_t);
        (*this)["strcat"].reset(new test_strcat_t);
        (*this)["isalpha"].reset(new test_isalpha_t);
        (*this)["isdigit"].reset(new test_isdigit_t);
        (*this)["isalnum"].reset(new test_isalnum_t);
        (*this)["isascii"].reset(new test_isascii_t);
        (*this)["isprint"].reset(new test_isprint_t);
        (*this)["toupper"].reset(new test_toupper_t);
        (*this)["tolower"].reset(new test_tolower_t);
        (*this)["puts"].reset(new test_puts_t);

        // Less simple
        (*this)["strlen"].reset(new test_strlen_t);
        (*this)["memset"].reset(new test_memset_t);
        (*this)["memcpy"].reset(new test_memcpy_t);
        (*this)["strdup"].reset(new test_strdup_t);

        // Cat
        (*this)["cat"].reset(new test_cat_t);

        // Bonus
        (*this)["memccpy"].reset(new test_memccpy_t);
        (*this)["memdel"].reset(new test_memdel_t);
        (*this)["memchr"].reset(new test_memchr_t);
        (*this)["memalloc"].reset(new test_memalloc_t);
        (*this)["memmove"].reset(new test_memmove_t);
        (*this)["strnew"].reset(new test_strnew_t);
        (*this)["strchr"].reset(new test_strchr_t);
        (*this)["memcmp"].reset(new test_memcmp_t);
        (*this)["strcmp"].reset(new test_strcmp_t);
        (*this)["strncmp"].reset(new test_strncmp_t);
        (*this)["strcpy"].reset(new test_strcpy_t);
        (*this)["strncpy"].reset(new test_strncpy_t);
        (*this)["strncat"].reset(new test_strncat_t);
        (*this)["lstnew"].reset(new test_lstnew_t);
        (*this)["strdel"].reset(new test_strdel_t);
        (*this)["strstr"].reset(new test_strstr_t);
        (*this)["lstadd"].reset(new test_lstadd_t);
        (*this)["atoi"].reset(new test_atoi_t);
        // (*this)["strclr"].reset(new test_strclr_t);
    }

    void show_usage(const std::string & prog_name) const
    {
        std::cerr << "Usage: " << prog_name << " [" << VERBOSE_FLAG << "] [all] [";
        if (!empty())
        {
            std::cerr << "\033[38;5;3m" << begin()->first << "\033[0m";
            for (auto it = next(begin()); it != end(); ++it)
                std::cerr << ", \033[38;5;3m" << it->first << "\033[0m";
        }
        std::cerr << "]" << std::endl;
    }

    void run(const std::string & test_name) const
    {
        if (test_name == ALL_STRING)
            for (auto it = begin(); it != end(); ++it)
                run_one(it);
        else
        {
            auto it = find(test_name);
            if (it != end())
                return run_one(it);
            std::cerr << "Unknown test: " << test_name << std::endl;
        }
    }

private:

    void run_one(const base_map_t::const_iterator it) const
    {
        std::cout << "\033[38;5;3m" << it->first << ": \033[0m";
        std::cout.flush();
        it->second->run();
        std::cout << std::endl;
    }

};

int main(int ac, char **av)
{
    std::srand(std::time(nullptr));
    std::vector<std::string> args { av + 1, av + ac };
    test_map_t tests;

    if (args.empty())
    {
        tests.show_usage(av[0]);
        return -1;
    }

    for (const std::string & arg: args)
    {
        if (arg == VERBOSE_FLAG)
            test_base_t::verbose = true;
        else
            tests.run(arg);
    }

    return 0;
}
