#Makefile del programa practica 7 ejercicio1
COM = gcc -g -Wall -Wextra -c
OBJ = gcc -g -Wall -Wextra -o

estructura: estructura.o fecha.o fecha.h
	$(OBJ) estructura estructura.o fecha.o

estructura.o: estructura.o fecha.o fecha.h
	$(COM) estructura.c 

fecha.o: fecha.c fecha.h
	$(COM) fecha.c

delete: *.o
	rm -r *.o estructura *.c~
