salesdata.o: salesdata.cpp salesdata.h
	g++ -c -g -std=c++11 -Wall salesdata.cpp -o salesdata.o
handletransactions.o: handletransactions.cpp chapter07.h salesdata.h
	g++ -c -g -std=c++11 -Wall handletransactions.cpp -o handletransactions.o
handletransactions: handletransactions.o salesdata.o
	g++ handletransactions.o salesdata.o -o handletransactions

person.o: person.cpp person.h
	g++ -c -g -std=c++11 -Wall person.cpp -o person.o
handlepersons.o: handlepersons.cpp chapter07.h person.h
	g++ -c -g -std=c++11 -Wall handlepersons.cpp -o handlepersons.o
handlepersons: handlepersons.o person.o
	g++ handlepersons.o person.o -o handlepersons

screen.o: screen.cpp screen.h
	g++ -c -g -Wall -std=c++11 screen.cpp -o screen.o
windowmanager.o: windowmanager.cpp windowmanager.h screen.h
	g++ -c -g -Wall -std=c++11 windowmanager.cpp -o windowmanager.o
usescreen.o: usescreen.cpp screen.h
	g++ -c -g -Wall -std=c++11 usescreen.cpp -o usescreen.o
usescreen: usescreen.o screen.o windowmanager.o
	g++ usescreen.o screen.o windowmanager.o -o usescreen

usedefconstr.o: usedefconstr.cpp chapter07.h
	g++ -c -g -Wall -std=c++11 usedefconstr.cpp -o usedefconstr.o
usedefconstr: usedefconstr.o
	g++ usedefconstr.o -o usedefconstr

clean:
	rm -f *.o *.h~ *.cpp~ \
	handletransactions \
	handlepersons \
	usescreen \
	usedefconstr

