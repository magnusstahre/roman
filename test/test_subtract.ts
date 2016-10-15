#test subtract_ii_i_gives_i

res = roman_subtract("II", "I");

ck_assert_str_eq(res, "I");
