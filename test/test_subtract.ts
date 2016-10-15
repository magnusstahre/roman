#test subtract_ii_i_gives_i

res = roman_subtract("II", "I");

ck_assert_str_eq(res, "I");

#test subtract_iii_i_gives_ii

res = roman_subtract("III", "I");

ck_assert_str_eq(res, "II");

#test subtract_i_ii_gives_null

res = roman_subtract("I", "II");

ck_assert_ptr_eq(res, NULL);

#test subtract_i_i_gives_null

res = roman_subtract("I", "I");

ck_assert_ptr_eq(res, NULL);

#test subtract_iv_i_gives_iii

res = roman_subtract("IV", "I");

ck_assert_str_eq(res, "III");

#test subtract_v_ii_gives_iii

res = roman_subtract("V", "II");

ck_assert_str_eq(res, "III");

#test subtract_v_i_gives_iv

res = roman_subtract("V", "I");

ck_assert_str_eq(res, "IV");

#test subtract_bad_stuff_gives_null

res = roman_subtract("bad", "stuff");

ck_assert_ptr_eq(res, NULL);
