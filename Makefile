CC=gcc
TEST_LIBS=-lcheck -lrt -lpthread -lm

default: test roman_add roman_subtract

test_runner.c: test/*.ts
	checkmk test/*.ts > $@

test_runner: test_runner.o roman.o
	$(CC) -o $@ $+ $(TEST_LIBS)

test:	test_runner
	./test_runner

roman_add: roman_add.o roman.o
	$(CC) -o $@ $+

roman_subtract: roman_subtract.o roman.o
	$(CC) -o $@ $+
