# Compiler, tools and options

CXX = g++
LINK = g++
CXXFLAGS = -pipe -g -std=gnu++11 -Wall -W -fPIC
DEL_FILE = rm -f
INCPATH = -I.
LIBS = 

# Files

OBJECTS = main.o \
	sol_5_1.o \
	sol_5_2.o \
	sol_5_3.o \
	sol_5_4.o \
	sol_5_5.o \
	sol_5_16.o \
	sol_5_17.o \
	sol_5_59.o \
	sol_5_60.o \
	sol_5_82.o \
	traverseorder.o \
	sol_5_83.o \
	sol_5_84.o
TARGET = main

# Build rules

$(TARGET): $(OBJECTS)
	$(LINK) -o $(TARGET) $(OBJECTS) $(LIBS)

# Compile

main.o: main.cpp chapter05.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

sol_5_1.o: sol_5_1.cpp chapter05.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sol_5_1.o sol_5_1.cpp

sol_5_2.o: sol_5_2.cpp chapter05.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sol_5_2.o sol_5_2.cpp

sol_5_3.o: sol_5_3.cpp chapter05.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sol_5_3.o sol_5_3.cpp

sol_5_4.o: sol_5_4.cpp chapter05.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sol_5_4.o sol_5_4.cpp

sol_5_5.o: sol_5_5.cpp chapter05.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sol_5_5.o sol_5_5.cpp

sol_5_16.o: sol_5_16.cpp chapter05.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sol_5_16.o sol_5_16.cpp

sol_5_17.o: sol_5_17.cpp chapter05.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sol_5_17.o sol_5_17.cpp

sol_5_59.o: sol_5_59.cpp chapter05.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sol_5_59.o sol_5_59.cpp

sol_5_60.o: sol_5_60.cpp chapter05.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sol_5_60.o sol_5_60.cpp

sol_5_82.o: sol_5_82.cpp chapter05.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sol_5_82.o sol_5_82.cpp

traverseorder.o: traverseorder.cpp traverseorder.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o traverseorder.o traverseorder.cpp

sol_5_83.o: sol_5_83.cpp chapter05.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sol_5_83.o sol_5_83.cpp

sol_5_84.o: sol_5_84.cpp chapter05.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sol_5_84.o sol_5_84.cpp

clean:
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) $(TARGET)
	-$(DEL_FILE) *~
