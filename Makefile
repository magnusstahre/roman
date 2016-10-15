default: test roman_add roman_subtract

test_runner.c: test/*.ts
	checkmk test/*.ts > test_runner.c

test:	test_runner.o roman.o
	gcc -o test_runner test_runner.o roman.o -lcheck -lrt -lpthread -lm
	./test_runner

roman_add: roman_add.o roman.o
	gcc -o roman_add roman_add.o roman.o

roman_subtract: roman_subtract.o roman.o
	gcc -o roman_subtract roman_subtract.o roman.o
