main.o: main.cpp node.h
	g++ -Wall -std=c++11 -c main.cpp

node.o: node.cpp node.h
	g++ -Wall -std=c++11 -c node.cpp

nodes: main.o node.o
	g++ -Wall -std=c++11 *.o -o nodes