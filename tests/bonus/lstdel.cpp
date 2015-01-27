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
    void      ft_lstadd(t_list **, t_list *);
    void      ft_lstdel(t_list **, void (*del)(void *));
}

// template <class T, size_t src_n>
// static bool test_one(const T (&src)[src_n])
// {
//     t_list  *betonic_lst;
//     // bool    result;

//     betonic_lst = ft_lstnew("Base Elem", 10);
//     ft_lstadd(&betonic_lst, ft_lstnew(src, src_n));
//     // result = !strcmp((char*)betonic_lst->content, src);
//     ft_lstdel(&betonic_lst, free);
//     // free(betonic_lst->content);
//     // free(betonic_lst);
//     return true;
// }

template <class T, size_t src_n>
static bool test_two(const T (&src)[src_n])
{
    t_list  *betonic_lst;
    bool    result;

    betonic_lst = ft_lstnew("Base Elem", 10);
    ft_lstadd(&betonic_lst, ft_lstnew(src, src_n));
    result = (betonic_lst->content_size == src_n);
    ft_lstdel(&betonic_lst, free);
    return result;
}

void test_lstdel_t::run()
{
    // assert(test_one("Content Test"), "Element: 'Content Test'");
    // assert(test_two("Size Testdddd"), "Element: 'Size Test'");
}
