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

static bool del_one()
{
    auto list = ft_lstnew("lol", 3);
    ft_lstdel(&list, free);
    return list == nullptr;
}

static bool del_lst(int size)
{
    t_list * list = nullptr;

    for (int i = 0; i < size; ++i)
        ft_lstadd(&list, ft_lstnew(&i, sizeof(int)));
    ft_lstdel(&list, free);
    return list == nullptr;
}

static bool del_null()
{
    t_list * list = nullptr;

    ft_lstdel(&list, free);
    return list == nullptr;
}

struct Lol
{
    char * lil;
    int loul;
    double lel;
};

void free_lol(void *lol)
{
    auto true_lol = static_cast<Lol *>(lol);
    free(true_lol->lil);
    free(true_lol);
}

static bool del_struct(int size)
{
    t_list * list = nullptr;

    for (int i = 0; i < size; ++i)
    {
        char *lil = (char *)malloc(sizeof(char) * i);
        Lol l { lil, i * 2, i * 13.37 };
        ft_lstadd(&list, ft_lstnew(&l, sizeof(Lol)));
    }
    ft_lstdel(&list, free_lol);
    return list == nullptr;
}

static bool del_struct_cpp(int size)
{
    t_list * list = nullptr;

    for (int i = 0; i < size; ++i)
    {
        char *lil = (char *)malloc(sizeof(char) * i);
        Lol l { lil, i * 2, i * 13.37 };
        ft_lstadd(&list, ft_lstnew(&l, sizeof(Lol)));
    }
    ft_lstdel(&list, [](void * data) {
        free(static_cast<Lol *>(data)->lil);
        free(data);
    });
    return list == nullptr;
}

void test_lstdel_t::run()
{
    assert(del_one(), "one element");
    assert(del_lst(42), "42 ints");
    assert(del_null(), "null list");
    assert(del_struct(1337), "1337 custom structs");
    assert(del_struct_cpp(1337), "1337 custom structs with lamda deleter #C++11");
}
