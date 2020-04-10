josephush_election.o: josephush_election.cpp list.h
	g++ -Wall -std=c++11 -c josephush_election.cpp

list.o: list.cpp list.h
	g++ -Wall -std=c++11 -c list.cpp

je: josephush_election.o list.o
	g++ -Wall -std=c++11 josephush_election.o list.o -o je