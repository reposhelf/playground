main.o: main.cpp solutions.h
	g++ -Wall -g -c -std=c++11 main.cpp

solutions.o: solutions.cpp solutions.h
	g++ -Wall -g -c -std=c++11 solutions.cpp

run: main.o solutions.o
	g++ -Wall -g -std=c++11 main.o solutions.o -o run