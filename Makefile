all: main.o my_tunez.o library.o
	gcc -o music main.o my_tunez.o library.o

main.o: main.c my_tunez.h library.h
	gcc -c main.c

linked_list.o: my_tunez.c
	gcc -c my_tunez.c

library.o: library.c
	gcc -c library.c

run:
	./my_tunez