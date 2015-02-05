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
    void      ft_lstadd(t_list **, t_list *);
    void      ft_lstdel(t_list **, void (*del)(void *));
}

template <class T, size_t src_n>
static bool test_one(const T (&src)[src_n])
{
    (void)src;
    t_list  *betonic_lst = nullptr, *new_elem, *new_elem2;
    bool    result;

    result = true;
    new_elem = ft_lstnew("Base Elem", 10);
    new_elem2 = ft_lstnew(src, src_n);
    ft_lstadd(&betonic_lst, new_elem);
    ft_lstadd(&betonic_lst, new_elem2);
    result &= (new_elem2 == betonic_lst);
    result &= (new_elem->next == 0);
    result &= !strcmp(static_cast<char *>(betonic_lst->next->content), "Base Elem");
    result &= (!betonic_lst->next->next);
    free(new_elem->content);
    free(new_elem);
    free(new_elem2->content);
    free(new_elem2);
    return result;
}

static bool test_custom(int size)
{
    t_list *betonic_lst = nullptr;
    t_list * it;

    bool ok = true;

    for (int i = 0; i < size; ++i)
        ft_lstadd(&betonic_lst, ft_lstnew(&i, sizeof(int)));

    it = betonic_lst;
    while (it)
    {
        ok &= (it->content_size == sizeof(int));
        ok &= (*(int *)it->content == --size);
        if (size == 0)
            ok &= (!it->next);
        else
            ok &= (it->next != 0);
        it = it->next;
    }
    ft_lstdel(&betonic_lst, free);
    return ok;
}

void test_lstadd_t::run()
{
    assert(test_one("Content Test"), "Create two elements");
    assert(test_custom(1337), "1337 ints");
}
