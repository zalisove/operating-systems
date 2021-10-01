all: compile run

compile: main.c protected-input.c user-interface-text.c
	gcc main.c protected-input.c user-interface-text.c -o ./main.out

run: main.out
	./main.out