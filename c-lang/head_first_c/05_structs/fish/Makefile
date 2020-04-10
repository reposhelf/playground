fish.o: fish.c fish.h
	gcc -c fish.c

main.o: main.c fish.h
	gcc -c main.c

fish: main.o fish.o
	gcc main.o fish.o -o fish