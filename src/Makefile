CC = gcc
FLAGS = -Wall -Werror -Wextra -std=c11

OS :=$(shell uname -s)
ifeq ($(OS), Darwin)
CFLAGS_TEST =-lcheck -lpthread
GCOV_FLAGS =-fprofile-arcs -ftest-coverage
LEAKS =leaks -atExit --
else
CFLAGS_TEST =-pthread -lcheck -lrt -lm -lsubunit
GCOV_FLAGS =-L. -lsubunit --coverage
LEAKS =valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose -q
endif


all: clean check

quadratic_equation.o: sources/quadratic_equation.c
	gcc -c -g sources/quadratic_equation.c
	
quadratic_equation.a: quadratic_equation.o
	ar rc quadratic_equation.a quadratic_equation.o
	ranlib quadratic_equation.a

check: clean quadratic_equation.a
		${CC} tests/check_quadratic_equation.c quadratic_equation.a ${FLAGS} ${CFLAGS_TEST} -o check
		./check

style:
	clang-format --style=Google -n headers/*.h sources/*.c tests/check_quadratic_equation.c

gcov_report: clean check
	rm -rf *.g*
	${CC} tests/check_quadratic_equation.c sources/quadratic_equation.c ${FLAGS} ${CFLAGS_TEST} ${GCOV_FLAGS} -o gcov_report
	./gcov_report
	lcov -t check -o test.info -c -d .
	genhtml -o report test.info
ifeq ($(OS), Darwin)
	open ./report/index.html
endif
ifeq ($(OS), Linux)
	xdg-open ./report/index.html
endif
	rm -rf *.gcda *.gcno *.info

leaks: clean check
	$(LEAKS) ./check

clean:
	rm -rf *.o *.a
	rm -rf *.out
	rm -rf test main report gcov_report check google*
	rm -rf *.gcda *.gcno *.info
