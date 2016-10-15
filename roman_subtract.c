#include <stdlib.h>

#include "roman.h"

int main(int argc, char *argv[]) {
  if (argc == 3) {
    char *res = roman_subtract(argv[1], argv[2]);
    
    if (res != NULL) {
      puts(res);
      free(res);
    }
  }
}
