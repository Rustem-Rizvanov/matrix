EFLAGS = -Wall -Wextra -Werror -std=c11 -g
CFLAGS = $(EFLAGS) -c
OFLAGS = $(EFLAGS) -o
S21_MATRIX_C = functions/*.c
S21_MATRIX_O = s21_*.o

all: clean test

s21_matrix.a:
	gcc $(CFLAGS) $(S21_MATRIX_C)
	ar r s21_matrix.a $(S21_MATRIX_O)
	rm -rf *.o
	ranlib s21_matrix.a

test: s21_matrix.a
	gcc $(CFLAGS) tests/main.c
	gcc $(OFLAGS) test tests/main.o s21_matrix.a -lcheck
	./test

gcov_report:
	gcc --coverage $(CFLAGS) $(S21_MATRIX_C)
	ar r s21_matrix.a $(S21_MATRIX_O)
	ranlib s21_matrix.a
	gcc $(CFLAGS) main.c
	gcc --coverage $(OFLAGS) test main.o s21_matrix.a -lcheck -lm
	rm -rf *.o *.a
	./test
	# gcov s21*.gcda
	gcovr -r . --html --html-details -o report.html
	open report.html

valgrind: s21_matrix.a
	gcc $(CFLAGS) main.c
	gcc $(OFLAGS) test main.o s21_matrix.a -lcheck -lm -lsubunit
	rm -rf *.o *.a
	# ./test
	valgrind --leak-check=full -s ./test

style:
	cp ../materials/linters/.clang-format .clang-format
	clang-format -i *.c *.h functions/*.c
	rm .clang-format

# debug: s21_matrix.a
# 	gcc $(CFLAGS) main.c
# 	gcc $(OFLAGS) a.out main.o s21_matrix.a
# 	rm -rf *.o *.a
# 	./a.out

check:
	cppcheck --enable=all --inconclusive --std=c11 --suppress=missingIncludeSystem ./

clean:
	rm -rf *.o *.a *.so *.gcda *.gcno *.gch rep.info *.html *.css test report *.txt test.info test.dSYM proj