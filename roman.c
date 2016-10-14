#include <stdlib.h>
#include <string.h>

#include "roman.h"

char roman_numeral[] = "VI";

int roman_compare(const void *a, const void *b) {
  return index(roman_numeral, *(char *)a) - index(roman_numeral, *(char *)b);
}; 

char *roman_add(char *first, char *second) {
  if (first == NULL || second == NULL) {
    return NULL;
  }

  size_t lens = strlen(first) + strlen(second) + 1;
  
  char *buf = malloc(lens);
  
  strcpy(buf, first);
  strcat(buf, second);

  qsort(buf, strlen(buf), sizeof(char), roman_compare);
  return buf;
}
