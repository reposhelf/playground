screen.o: screen.cpp screen.h
	g++ -c -g -Wall -std=c++11 screen.cpp -o screen.o
windowmanager.o: windowmanager.cpp windowmanager.h screen.h
	g++ -c -g -Wall -std=c++11 windowmanager.cpp -o windowmanager.o
usescreen.o: usescreen.cpp screen.h
	g++ -c -g -Wall -std=c++11 usescreen.cpp -o usescreen.o
usescreen: usescreen.o screen.o windowmanager.o
	g++ usescreen.o screen.o windowmanager.o -o usescreen

clean:
	rm -f *.o usescreen
