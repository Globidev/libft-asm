#include <cstring>

#include "../tests.hpp"

typedef struct      s_list
{
    void            *content;
    size_t          content_size;
    struct s_list   *next;
}                   t_list;

extern "C" {
    t_list    *ft_lstnew(const void *, size_t);
}

template <class T, size_t src_n>
static bool test_one(const T (&src)[src_n])
{
    t_list  *betonic_lst;
    bool    result;

    betonic_lst = ft_lstnew(src, src_n);
    result = !strcmp((char*)betonic_lst->content, src);
    free(betonic_lst);
    return result;
}

template <class T, size_t src_n>
static bool test_two(const T (&src)[src_n])
{
    t_list  *betonic_lst;
    bool    result;

    betonic_lst = ft_lstnew(src, src_n);
    result = (betonic_lst->content_size == src_n);
    free(betonic_lst);
    return result;
}

template <class T, size_t src_n>
static bool test_three(const T (&src)[src_n])
{
    t_list  *betonic_lst;
    bool    result;

    betonic_lst = ft_lstnew(src, src_n);
    result = (betonic_lst->next == 0);
    free(betonic_lst);
    return result;
}

void test_lstnew_t::run()
{
    assert(test_one("Content Test"), "Element: 'Content Test'");
    assert(test_two("Size Test"), "Element: 'Size Test'");
    assert(test_three("Next Test"), "Element: 'Next Test'");
}
