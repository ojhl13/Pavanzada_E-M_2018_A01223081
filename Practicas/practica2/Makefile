
all:
	gcc main.c operations.c -o operations.exe
	./operations.exe
main.o: main.c
	gcc -c main.c
operations: operations.o 
	gcc -c operations.c

test: main.o operations.o 
	gcc main.o operations.o -o operations.exe
	./maintest.tcl ./operations.exe


