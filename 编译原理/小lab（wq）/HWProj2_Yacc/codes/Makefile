.PHONY: all int clean
all:	int real_like_C real

run_int: int
	@./calculator_int

int:
	@flex cal1.l
	@yacc -d cal1.y
	@gcc -o calculator_int y.tab.c lex.yy.c -ll -lm

run_real_like_C: real_like_C
	@./calculator_real_like_C

real_like_C:
	@flex cal2.l
	@yacc -d cal2.y
	@gcc -o calculator_real_like_C y.tab.c lex.yy.c -ll -lm

run_real: real
	@./calculator_real

real:
	@flex cal3.l
	@yacc -d cal3.y
	@gcc -o calculator_real y.tab.c lex.yy.c -ll -lm

clean:
	@rm calculator_int calculator_real_like_C calculator_real *.c *.h
