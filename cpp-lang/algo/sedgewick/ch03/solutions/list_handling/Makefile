main.o: main.cpp list.h solutions.h
	g++ -Wall -std=c++11 -c main.cpp

list.o: list.cpp list.h
	g++ -Wall -std=c++11 -c list.cpp

solutions.o: solutions.cpp solutions.h list.h
	g++ -Wall -std=c++11 -c solutions.cpp

solutions: main.o list.o solutions.o
	g++ -Wall -std=c++11 main.o list.o solutions.o -o solutions