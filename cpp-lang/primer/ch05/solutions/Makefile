main.o: main.cpp solutions.h
	g++ -Wall -std=c++11 -c main.cpp

solutions.o: solutions.cpp solutions.h
	g++ -Wall -std=c++11 -c solutions.cpp

solutions: main.o solutions.o
	g++ -Wall -std=c++11 main.o solutions.o -o solutions