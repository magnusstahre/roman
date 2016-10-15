#test add_i_i_gives_ii

res = roman_add("I", "I");

ck_assert_str_eq(res, "II");

#test add_ii_i_gives_iii

res = roman_add("II", "I");

ck_assert_str_eq(res, "III");

#test add_i_v_gives_vi

res = roman_add("I", "V");

ck_assert_str_eq(res, "VI");

#test add_i_x_gives_xi

res = roman_add("I", "X");

ck_assert_str_eq(res, "XI");

#test add_null_gives_null

res = roman_add("I", NULL);

ck_assert_ptr_eq(res, NULL);

#test add_bad_stuff_gives_null

res = roman_add("bad", "stuff");

ck_assert_ptr_eq(res, NULL);

#test add_vi_lx_gives_lxvi

res = roman_add("VI", "LX");

ck_assert_str_eq(res, "LXVI");

#test add_ii_ii_gives_iv

res = roman_add("II", "II");

ck_assert_str_eq(res, "IV");

#test add_ii_iii_gives_v

res = roman_add("II", "III");

ck_assert_str_eq(res, "V");

#test add_v_v_gives_x

res = roman_add("V", "V");

ck_assert_str_eq(res, "X");

#test add_iv_iv_gives_viii

res = roman_add("IV", "IV");

ck_assert_str_eq(res, "VIII");

#test add_v_iv_gives_ix

res = roman_add("IV", "V");

ck_assert_str_eq(res, "IX");

#test add_i_ix_gives_x

res = roman_add("I", "IX");

ck_assert_str_eq(res, "X");

#test add_xx_xxx_gives_l

res = roman_add("XX", "XXX");

ck_assert_str_eq(res, "L");

#test add_xx_xx_gives_xl

res = roman_add("XX", "XX");

ck_assert_str_eq(res, "XL");

#test add_xix_xxi_gives_xl

res = roman_add("XIX", "XXI");

ck_assert_str_eq(res, "XL");

#test add_i_xl_gives_xli

res = roman_add("I", "XL");

ck_assert_str_eq(res, "XLI");

#test add_l_l_gives_c

res = roman_add("L", "L");

ck_assert_str_eq(res, "C");

#test add_l_xl_gives_xc

res = roman_add("L", "XL");

ck_assert_str_eq(res, "XC");

#test add_i_xc_gives_xci

res = roman_add("I", "XC");

ck_assert_str_eq(res, "XCI");

#test add_cc_ccc_gives_d

res = roman_add("CC", "CCC");

ck_assert_str_eq(res, "D");

#test add_cc_cc_gives_cd

res = roman_add("CC", "CC");

ck_assert_str_eq(res, "CD");

#test add_i_cd_gives_cdi

res = roman_add("I", "CD");

ck_assert_str_eq(res, "CDI");

#test add_d_d_gives_m

res = roman_add("D", "D");

ck_assert_str_eq(res, "M");

#test add_d_cd_gives_cm

res = roman_add("D", "CD");

ck_assert_str_eq(res, "CM");

#test add_i_cm_gives_cdi

res = roman_add("I", "CM");

ck_assert_str_eq(res, "CMI");

#test add_mm_mm_gives_null_for_overflow

res = roman_add("MM", "MM");

ck_assert_ptr_eq(res, NULL);

#test add_empty_string_gives_null

res = roman_add("", "");

ck_assert_ptr_eq(res, NULL);
