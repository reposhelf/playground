array.o: array.cpp array.h
	g++ -c -g -Wall -std=c++11 array.cpp -o array.o

matrix.o: matrix.cpp matrix.h array.h
	g++ -c -g -Wall -std=c++11 matrix.cpp -o matrix.o

main.o: main.cpp matrix.h
	g++ -c -g -Wall -std=c++11 main.cpp -o main.o

lab3: array.o matrix.o main.o
	g++ array.o matrix.o main.o -o lab3

clean:
	rm -f *~ *.o lab3
