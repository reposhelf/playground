main.o: main.c spies.h
	gcc -g -c main.c

spies.o: spies.c spies.h
	gcc -g -c spies.c

spies: main.o spies.o
	gcc -g main.o spies.o -o spies