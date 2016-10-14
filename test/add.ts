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

#test add_bad_stuff_gives_null

char *res;

res = roman_add("bad", "stuff");

ck_assert_ptr_eq(res, NULL);

#test add_vi_lx_gives_lxvi

char *res;

res = roman_add("VI", "LX");

ck_assert_str_eq(res, "LXVI");

#test add_ii_ii_gives_iv

char *res;

res = roman_add("II", "II");

ck_assert_str_eq(res, "IV");

#test add_ii_iii_gives_v

char *res;

res = roman_add("II", "III");

ck_assert_str_eq(res, "V");

#test add_v_v_gives_x

char *res;

res = roman_add("V", "V");

ck_assert_str_eq(res, "X");

#test add_iv_iv_gives_viii

char *res;

res = roman_add("IV", "IV");

ck_assert_str_eq(res, "VIII");

#test add_v_iv_gives_ix

char *res;

res = roman_add("IV", "V");

ck_assert_str_eq(res, "IX");

#test add_i_ix_gives_x

char *res;

res = roman_add("I", "IX");

ck_assert_str_eq(res, "X");

#test add_xx_xxx_gives_l

char *res;

res = roman_add("XX", "XXX");

ck_assert_str_eq(res, "L");

#test add_xx_xx_gives_xl

char *res;

res = roman_add("XX", "XX");

ck_assert_str_eq(res, "XL");

#test add_xix_xxi_gives_xl

char *res;

res = roman_add("XIX", "XXI");

ck_assert_str_eq(res, "XL");

#test add_i_xl_gives_xli

char *res;

res = roman_add("I", "XL");

ck_assert_str_eq(res, "XLI");

#test add_l_l_gives_c

char *res;

res = roman_add("L", "L");

ck_assert_str_eq(res, "C");
