# Roman Numerals in C

## Building

Run `make`. This run build `roman_add` and `roman_subtract` as well as running tests.

Example:

```
$ make

checkmk test/*.ts > test_runner.c
gcc    -c -o test_runner.o test_runner.c
gcc    -c -o roman.o roman.c
gcc -o test_runner test_runner.o roman.o -lcheck -lrt -lpthread -lm
./test_runner
Running suite(s): Core
100%: Checks: 36, Failures: 0, Errors: 0
gcc    -c -o roman_add.o roman_add.c
gcc -o roman_add roman_add.o roman.o
gcc    -c -o roman_subtract.o roman_subtract.c
gcc -o roman_subtract roman_subtract.o roman.o
```

## Running

Run `./roman_add number1 number1` or `./roman_subtract number1 number2`.

Examples:

```
$ ./roman_add XV VI
XXI
```

```
$ ./roman_subtract M I
CMXCIX
```
