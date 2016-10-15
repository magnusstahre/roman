#test subtract_ii_i_gives_i

res = roman_subtract("II", "I");

ck_assert_str_eq(res, "I");

#test subtract_iii_i_gives_ii

res = roman_subtract("III", "I");

ck_assert_str_eq(res, "II");
