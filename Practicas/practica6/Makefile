LIB := $(shell find ./lib -name '*.o')
all:
	 gcc -c hash.c
	 gcc -c main.c
	 gcc -o hash.exe hash.o main.o $(LIB)

hashtest: clean
	 gcc -c hash.c
	 gcc -c hashtest.c
	 gcc -o hashtest.exe hash.o hashtest.o
	 ./hashtest.exe

test:	 hashtest

clean:
	 rm *.out *.o *.exe || exit 0

hash: clean
	 gcc -c hash.c
	 gcc -c main.c
	 gcc -o hash.exe hash.o main.o $(LIB)

run: hash
	 ./hash.exe

runtest: hash
	 ./maintest.tcl ./hash.exe

