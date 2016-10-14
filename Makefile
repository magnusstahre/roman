default:
	test

test_runner.c:
	checkmk test/*.ts > test_runner.c

test:	test_runner.c
	gcc -o test_runner test_runner.c -lcheck -lrt -lpthread -lm
	./test_runner
