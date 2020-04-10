node.o: node.cpp node.h
	g++ -Wall -std=c++11 -c node.cpp

main.o: main.cpp node.h
	g++ -Wall -std=c++11 -c main.cpp

sortnds: main.o node.o
	g++ main.o node.o -o sortnds