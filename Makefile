default:
	test

test_runner.c: test/*.ts
	checkmk test/*.ts > test_runner.c

test:	test_runner.o roman.o
	gcc -o test_runner test_runner.o roman.o -lcheck -lrt -lpthread -lm
	./test_runner
