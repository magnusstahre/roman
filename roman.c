#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "roman.h"

static const char roman_numeral[] = "MDCLXVI";

static int roman_compare(const void *left, const void *right) {
  return strchr(roman_numeral, *(char *)left) - strchr(roman_numeral, *(char *)right);
}; 

static bool roman_valid(const char *str) {
  size_t len, x;
  if (str == NULL || strlen(str) == 0) {
    return 0;
  }

  len = strlen(str);
  
  for (x = 0; x < len; x++) {
    if (strchr(roman_numeral, str[x]) == NULL) {
      return 0;
    }
  }
  
  return 1;
}

static const char *roman_simplifications[] = {
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

static void roman_simplify(char *str) {
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
      memmove(i + strlen(replace), rest, sizeof(char)*(strlen(rest)+1));
    }
  }
}

static const char *roman_expansions[] = {
  "CM", "DCD",
  "CD", "CCCC",
  "XC", "LXL",
  "XL", "XXXX",
  "IX", "VIV",
  "IV", "IIII",
  NULL, NULL
};

static void roman_expand(char *str) {
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
  size_t len;
  char *buf;

  if (!(roman_valid(first) && roman_valid(second))) {
    return NULL;
  }

  len = strlen(first) + strlen(second);
  
  buf = malloc(len * 3);
  
  strcpy(buf, first);
  roman_expand(buf);
  len = strlen(buf);
  strcpy(buf+len, second);
  roman_expand(buf+len);

  qsort(buf, strlen(buf), sizeof(char), roman_compare);
  
  roman_simplify(buf);
  
  if (strncmp(buf, "MMMM", 4) == 0) {
    free(buf);
    return NULL;
  }

  return buf;
}

static void roman_delete_char(char *str) {
  size_t len = strlen(str);
  memmove(str, str+1, sizeof(char)*len);
}

static const char *roman_borrows[] = {
  "DD", // M
  "CCCCC", // D
  "LL", // C
  "XXXXX", // L
  "VV", // X
  "IIIII", // V
  NULL // I
};

static bool roman_borrow(char *str, char c) {
  char *borrower;
  for (borrower = strchr(roman_numeral, c) - 1; borrower >= roman_numeral; borrower--) {
    int i = borrower - roman_numeral;
    char *found_in_str = strrchr(str, *borrower);
    if (found_in_str != NULL) {
      memmove(found_in_str + strlen(roman_borrows[i]), found_in_str + 1, sizeof(char)*strlen(found_in_str));
      strncpy(found_in_str, roman_borrows[i], strlen(roman_borrows[i]));
      return 1;
    }
  }
  return 0;
}

char *roman_subtract(const char *first, const char *second) {
  char *ret = NULL, *first_buf, *second_buf;
  if (!(roman_valid(first) && roman_valid(second))) {
    return NULL;
  }

  first_buf = malloc(strlen(first) * 20);
  
  if (first_buf == NULL) {
    return NULL;
  }

  strcpy(first_buf, first);
  roman_expand(first_buf);

  second_buf = malloc(strlen(second) * 3);
  
  if (second_buf == NULL) {
    free(first_buf);
    return NULL;
  }

  strcpy(second_buf, second);
  roman_expand(second_buf);
  
  while (*second_buf != '\0') {
    char *found_in_first_buf = strrchr(first_buf, *second_buf);
    
    if (found_in_first_buf == NULL) {
      if (!roman_borrow(first_buf, *second_buf)) {
	break;
      }
    } else {
      roman_delete_char(found_in_first_buf);
      roman_delete_char(second_buf);
    }
  }
  
  if (strlen(first_buf) > 0 && strlen(second_buf) == 0) {
    roman_simplify(first_buf);
    ret = strdup(first_buf);
  }
  free(first_buf);
  free(second_buf);
  return ret;
}
