#include <stdlib.h>
#include <string.h>

#include "roman.h"

char *roman_add(char *first, char *second) {
  size_t lens = strlen(first) + strlen(second) + 1;
  
  char *buf = malloc(lens);
  
  strcpy(buf, first);
  strcat(buf, second);

  return buf;
}
