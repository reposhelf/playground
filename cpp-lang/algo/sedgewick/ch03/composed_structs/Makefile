main.o: main.cpp \
	    malloc2d.h \
	    string_sort.h \
	    adjacency_mtrx.h \
	    adjacency_list.h \
	    array2d_lists.h
	g++ -Wall -std=c++11 -g -c main.cpp

malloc2d.o: malloc2d.cpp malloc2d.h
	g++ -Wall -std=c++11 -g -c malloc2d.cpp

string_sort.o: string_sort.cpp string_sort.h
	g++ -Wall -std=c++11 -g -c string_sort.cpp

adjacency_mtrx.o: adjacency_mtrx.cpp adjacency_mtrx.h
	g++ -Wall -std=c++11 -g -c adjacency_mtrx.cpp

adjacency_list.o: adjacency_list.cpp adjacency_list.h
	g++ -Wall -std=c++11 -g -c adjacency_list.cpp

point.o: point.cpp point.h
	g++ -Wall -std=c++11 -g -c point.cpp

array2d_lists.o: array2d_lists.cpp array2d_lists.h point.h
	g++ -Wall -std=c++11 -g -c array2d_lists.cpp

run: main.o \
	    malloc2d.o \
	    string_sort.o \
	    adjacency_mtrx.o \
	    adjacency_list.o \
	    point.o \
	    array2d_lists.o
	g++ -Wall -std=c++11 -g main.o \
	    malloc2d.o \
	    string_sort.o \
	    adjacency_mtrx.o \
	    adjacency_list.o \
	    point.o \
	    array2d_lists.o \
	    -o run