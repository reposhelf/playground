salesdata.o: salesdata.cpp salesdata.h
	g++ -c -g -Wall -std=c++11 salesdata.cpp -o salesdata.o

usetransactions.o: usetransactions.cpp salesdata.h
	g++ -c -g -Wall -std=c++11 usetransactions.cpp -o usetransactions.o

usetransactions: salesdata.o usetransactions.o
	g++ salesdata.o usetransactions.o -o usetransactions

fal: fstream_auto_life.cpp
	g++ -g -Wall -std=c++11 fstream_auto_life.cpp -o fal

pi: personinfo.cpp
	g++ -g -Wall -std=c++11 personinfo.cpp -o pi

clean:
	rm -f *~ *.o usetransactions fal pi
