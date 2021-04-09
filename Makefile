dict: main.o read.o list.o
	gcc -o dict main.o read.o list.o
main.o: main.c
	gcc -c -Wall main.c
read.o: read.c read.h
	gcc -c -Wall read.c
list.o: list.c list.h
	gcc -c -Wall list.c
