launch.o: launch.c launch.h thruster.h
	gcc -c launch.c

thruster.o: thruster.c thruster.h
	gcc -c thruster.c

main.o: main.c launch.h
	gcc -c main.c

launch: launch.o thruster.o main.o
	gcc launch.o thruster.o main.o -o launch