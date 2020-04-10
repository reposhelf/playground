sol_8_1: sol_8_1.cpp
	g++ -g -Wall -std=c++11 sol_8_1.cpp -o sol_8_1

sol_8_4: sol_8_4.cpp
	g++ -g -Wall -std=c++11 sol_8_4.cpp -o sol_8_4

sol_8_5: sol_8_5.cpp
	g++ -g -Wall -std=c++11 sol_8_5.cpp -o sol_8_5

salesdata.o: salesdata.cpp salesdata.h
	g++ -c -g -Wall -std=c++11 salesdata.cpp -o salesdata.o

sol_8_6.o: sol_8_6.cpp salesdata.h
	g++ -c -g -Wall -std=c++11 sol_8_6.cpp -o sol_8_6.o

sol_8_6: salesdata.o sol_8_6.o
	g++ salesdata.o sol_8_6.o -o sol_8_6

sol_8_8: salesdata.o sol_8_8.o
	g++ salesdata.o sol_8_8.o -o sol_8_8

sol_8_9: salesdata.o sol_8_9.o
	g++ salesdata.o sol_8_9.o -o sol_8_9

sol_8_10: sol_8_10.cpp
	g++ -g -Wall -std=c++11 sol_8_10.cpp -o sol_8_10

sol_8_11: sol_8_11.cpp
	g++ -g -Wall -std=c++11 sol_8_11.cpp -o sol_8_11

clean:
	rm -f *~ *.o sol_8_1 \
		sol_8_4 \
		sol_8_5 \
		sol_8_6 \
		sol_8_8 \
		sol_8_9 \
		sol_8_10 \
		sol_8_11
