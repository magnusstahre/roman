#include <stdlib.h>
#include <string.h>

#include "roman.h"

char roman_numeral[] = "MDCLXVI";

int roman_compare(const void *a, const void *b) {
  return index(roman_numeral, *(char *)a) - index(roman_numeral, *(char *)b);
}; 

int roman_valid(const char *str) {
  int l = strlen(str), x;
  
  for (x = 0; x < l; x++) {
    if (index(roman_numeral, str[x]) == NULL) {
      return 0;
    }
  }
  
  return 1;
}

char *roman_simplifications[] = {
  "IIIII", "V",
  "IIII", "IV",
  NULL, NULL
};

void roman_simplify(char *str) {
  int x;
  char *i, *find, *replace, *rest;
 
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

char *roman_add(char *first, char *second) {
  if (first == NULL || second == NULL) {
    return NULL;
  }

  if (!(roman_valid(first) && roman_valid(second))) {
    return NULL;
  }

  size_t lens = strlen(first) + strlen(second) + 1;
  
  char *buf = malloc(lens);
  
  strcpy(buf, first);
  strcat(buf, second);

  qsort(buf, strlen(buf), sizeof(char), roman_compare);
  
  roman_simplify(buf);

  return buf;
}
