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

#test add_i_v_gives_vi

char *res;

res = roman_add("I", "V");

ck_assert_str_eq(res, "VI");

#test add_i_x_gives_xi

char *res;

res = roman_add("I", "X");

ck_assert_str_eq(res, "XI");

#test add_null_gives_null

char *res;

res = roman_add("I", NULL);

ck_assert_ptr_eq(res, NULL);
