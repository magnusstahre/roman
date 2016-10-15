#include <stdlib.h>
#include <string.h>

#include "roman.h"

const char roman_numeral[] = "MDCLXVI";

int roman_compare(const void *left, const void *right) {
  return index(roman_numeral, *(char *)left) - index(roman_numeral, *(char *)right);
}; 

int roman_valid(const char *str) {
  if (str == NULL) {
    return 0;
  }

  int l = strlen(str), x;
  
  for (x = 0; x < l; x++) {
    if (index(roman_numeral, str[x]) == NULL) {
      return 0;
    }
  }
  
  return 1;
}

const char *roman_simplifications[] = {
  "IIIII", "V",
  "IIII", "IV",
  "VV", "X",
  "VIV", "IX",
  "XXXXX", "L",
  "XXXX", "XL",
  "LL", "C",
  "LXL", "XC",
  "CCCCC", "D",
  "CCCC", "CD",
  "DD", "M",
  "DCD", "CM",
  NULL, NULL
};

void roman_simplify(char *str) {
  int x;
  const char *find, *replace;
  char *i, *rest;
 
  for (x = 0; roman_simplifications[x] != NULL; x += 2) {
    find = roman_simplifications[x];
    replace = roman_simplifications[x+1];

    i = strstr(str, find);
  
    if (i != NULL) {
      rest = i + strlen(find);
      strcpy(i, replace);
      strcpy(i + strlen(replace), rest);
    }
  }
}

const char *roman_expansions[] = {
  "CM", "DCD",
  "CD", "CCCC",
  "XC", "LXL",
  "XL", "XXXX",
  "IX", "VIV",
  "IV", "IIII",
  NULL, NULL
};

void roman_expand(char *str) {
  int x;
  const char *find, *replace;
  char *i, *rest;
 
  for (x = 0; roman_expansions[x] != NULL; x += 2) {
    find = roman_expansions[x];
    replace = roman_expansions[x+1];

    i = strstr(str, find);
  
    if (i != NULL) {
      rest = i + strlen(find);
      strcpy(i + strlen(replace), rest);
      strncpy(i, replace, strlen(replace));
    }
  }
}

char *roman_add(const char *first, const char *second) {
  if (!(roman_valid(first) && roman_valid(second))) {
    return NULL;
  }

  size_t lens = strlen(first) + strlen(second);
  
  char *buf = malloc(lens * 3);
  
  strcpy(buf, first);
  roman_expand(buf);
  size_t len2 = strlen(buf);
  strcpy(buf+len2, second);
  roman_expand(buf+len2);

  qsort(buf, strlen(buf), sizeof(char), roman_compare);
  
  roman_simplify(buf);
  
  if (strncmp(buf, "MMMM", 4) == 0) {
    free(buf);
    return NULL;
  }

  return buf;
}

void roman_delete_char(char *str) {
  strcpy(str, str+1);
}

const char *roman_borrows[] = {
  "DD", // M
  "CCCCC", // D
  "LL", // C
  "XXXXX", // L
  "VV", // X
  "IIIII", // V
  NULL // I
};

int roman_borrow(char *str, char c) {
  char *borrower;
  for (borrower = index(roman_numeral, c) - 1; borrower >= roman_numeral; borrower--) {
    int i = borrower - roman_numeral;
    char *found_in_str = rindex(str, *borrower);
    if (found_in_str != NULL) {
      strcpy(found_in_str + strlen(roman_borrows[i]), found_in_str + 1);
      strncpy(found_in_str, roman_borrows[i], strlen(roman_borrows[i]));
      return 1;
    }
  }
  return 0;
}

char *roman_subtract(const char *first, const char *second) {
  if (!(roman_valid(first) && roman_valid(second))) {
    return NULL;
  }

  char *ret = NULL;
  char *diff = malloc(strlen(first) * 3);
  
  if (diff == NULL) {
    return NULL;
  }

  strcpy(diff, first);
  roman_expand(diff);

  char *to_remove = malloc(strlen(second) * 3);
  
  if (to_remove == NULL) {
    free(diff);
    return NULL;
  }

  strcpy(to_remove, second);
  roman_expand(to_remove);
  
  char *ptr = to_remove;
  
  while (*ptr) {
    char *found_in_diff = rindex(diff, *ptr);
    
    if (found_in_diff == NULL) {
      if (!roman_borrow(diff, *ptr)) {
	break;
      }
    } else {
      roman_delete_char(found_in_diff);
      roman_delete_char(ptr);
    }
  }
  
  if (strlen(diff) > 0 && strlen(to_remove) == 0) {
    roman_simplify(diff);
    ret = strdup(diff);
  }
  free(diff);
  free(to_remove);
  return ret;
}
