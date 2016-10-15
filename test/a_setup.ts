#include <check.h>

#include <stdlib.h>

#include "roman.h"

char *res;

void free_res_if_needed() {
  if (res != NULL) {
    free(res);
  }
}