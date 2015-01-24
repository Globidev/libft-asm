#pragma once

void test_memccpy();
void test_memdel();
void test_memchr();

#include "test_base.hpp"

# define ADD_TEST(name) struct name: test_base_t { virtual void run(); }

// Simple
ADD_TEST(test_bzero_t);
ADD_TEST(test_strcat_t);
ADD_TEST(test_isalpha_t);
ADD_TEST(test_isdigit_t);
ADD_TEST(test_isalnum_t);
ADD_TEST(test_isascii_t);
ADD_TEST(test_isprint_t);
ADD_TEST(test_toupper_t);
ADD_TEST(test_tolower_t);
ADD_TEST(test_puts_t);

// Less simple
ADD_TEST(test_strlen_t);
ADD_TEST(test_memset_t);
ADD_TEST(test_memcpy_t);
ADD_TEST(test_strdup_t);

// Cat
ADD_TEST(test_cat_t);

// Bonus
ADD_TEST(test_memccpy_t);
ADD_TEST(test_memdel_t);
ADD_TEST(test_memchr_t);
ADD_TEST(test_memcmp_t);
ADD_TEST(test_memalloc_t);
ADD_TEST(test_strnew_t);
ADD_TEST(test_strcmp_t);
ADD_TEST(test_strncmp_t);
ADD_TEST(test_strcpy_t);
ADD_TEST(test_strncpy_t);
ADD_TEST(test_lstnew_t);
ADD_TEST(test_lstadd_t);
ADD_TEST(test_strchr_t);
