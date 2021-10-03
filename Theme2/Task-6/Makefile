all: compile run

compile: main.c lib/source/matrix.c
	gcc main.c lib/source/matrix.c -o ./main.out

run: main.out
	./main.out