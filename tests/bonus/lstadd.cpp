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
}

template <class T, size_t src_n>
static bool test_one(const T (&src)[src_n])
{
    t_list  *betonic_lst = nullptr, *new_elem, *new_elem2;
    bool    result;

    result = false;
    new_elem = ft_lstnew("Base Elem", 10);
    new_elem2 = ft_lstnew(src, src_n);
    ft_lstadd(&betonic_lst, new_elem);
    ft_lstadd(&betonic_lst, new_elem2);
    result |= (new_elem == betonic_lst);
    result |= (betonic_lst->next != 0);
    result |= !strcmp(static_cast<char *>(betonic_lst->next->content), "Base Elem");
    free(new_elem->content);
    free(new_elem);
    free(new_elem2->content);
    free(new_elem2);
    return result;
}

void test_lstadd_t::run()
{
    assert(test_one("Content Test"), "Create two elements");
}
