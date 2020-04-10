node.o: node.cpp node.h
	g++ -c -Wall -std=c++11 node.cpp

main.o: main.cpp node.h
	g++ -c -Wall -std=c++11 main.cpp

nodes: main.o node.o
	g++ -Wall -std=c++11 main.o node.o -o nodes