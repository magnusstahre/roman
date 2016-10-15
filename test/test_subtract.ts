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
