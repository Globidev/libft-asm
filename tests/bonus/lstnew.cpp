#include <cstring>

#include "../tests.hpp"

struct t_list
{
    void     *content;
    size_t   content_size;
    t_list   *next;
};

extern "C" {
    t_list    *ft_lstnew(const void *, size_t);
}

template <class T, size_t src_n>
static bool test_one(const T (&src)[src_n])
{
    t_list  *betonic_lst;
    bool    result;

    result = true;
    betonic_lst = ft_lstnew(src, src_n);
    result &= !strcmp((char*)betonic_lst->content, src);
    result &= (betonic_lst->content_size == src_n);
    result &= (betonic_lst->next == 0);
    free(betonic_lst->content);
    free(betonic_lst);
    return result;
}

static bool test_null()
{
    t_list  *betonic_lst;
    bool result;

    result = true;
    betonic_lst = ft_lstnew(0, 0);
    result &= !betonic_lst->content;
    result &= !betonic_lst->content_size;
    result &= !betonic_lst->next;
    free(betonic_lst->content);
    free(betonic_lst);
    return result;
}

void test_lstnew_t::run()
{
    assert(test_one("Hello world!\n"), "Create an element with a string");
    assert(test_null(), "Create an element with null content");
}
