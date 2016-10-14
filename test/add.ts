#include <check.h>

#include "roman.h"

#test add_i_i_gives_ii

char *res;

res = roman_add("I", "I");

ck_assert_str_eq(res, "II");

#test add_ii_i_gives_iii

char *res;

res = roman_add("II", "I");

ck_assert_str_eq(res, "III");
