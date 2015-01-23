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

    betonic_lst = ft_lstnew(src, src_n);
    return (!strcmp((char*)betonic_lst->content, src));
}

template <class T, size_t src_n>
static bool test_two(const T (&src)[src_n])
{
    t_list  *betonic_lst;

    betonic_lst = ft_lstnew(src, src_n);
    return (betonic_lst->content_size == src_n);
}

template <class T, size_t src_n>
static bool test_three(const T (&src)[src_n])
{
    t_list  *betonic_lst;

    betonic_lst = ft_lstnew(src, src_n);
    return (betonic_lst->next == 0);
}

void test_lstnew_t::run()
{
    assert(test_one("content test"), "Element: 'content test'");
    assert(test_two("size test"), "Element: 'size test'");
    assert(test_three("next test"), "Element: 'next test'");
}
