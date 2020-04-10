# Compiler, tools and options

CXX = g++
LINK = g++
CXXFLAGS = -pipe -g -std=gnu++11 -Wall -W -fPIC
DEL_FILE = rm -f
CPPUTEST = /home/vova/bin/cpputest-3.7dev
INCPATH = -I.. -I$(CPPUTEST)/include
LIBS = -L$(CPPUTEST)/lib -lCppUTest

# Files

OBJECTS = test.o \
	test_sol_5_1.o \
	sol_5_1.o \
	test_sol_5_5.o \
	sol_5_5.o \
	test_sol_5_16.o \
	sol_5_16.o \
	test_sol_5_17.o \
	sol_5_17.o \
	test_sol_5_59.o \
	sol_5_59.o \
	test_sol_5_60.o \
	sol_5_60.o \
	test_sol_5_82.o \
	sol_5_82.o \
	traverseorder.o \
	test_sol_5_83.o \
	sol_5_83.o \
	test_sol_5_84.o \
	sol_5_84.o
TARGET = test

# Build rules

$(TARGET): $(OBJECTS)
	$(LINK) -o $(TARGET) $(OBJECTS) $(LIBS)

# Compile

test.o: all_tests.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o test.o all_tests.cpp

test_sol_5_1.o: test_sol_5_1.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o test_sol_5_1.o test_sol_5_1.cpp

sol_5_1.o: ../sol_5_1.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sol_5_1.o ../sol_5_1.cpp

test_sol_5_5.o: test_sol_5_5.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o test_sol_5_5.o test_sol_5_5.cpp

sol_5_5.o: ../sol_5_5.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sol_5_5.o ../sol_5_5.cpp

test_sol_5_16.o: test_sol_5_16.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o test_sol_5_16.o test_sol_5_16.cpp

sol_5_16.o: ../sol_5_16.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sol_5_16.o ../sol_5_16.cpp

test_sol_5_17.o: test_sol_5_17.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o test_sol_5_17.o test_sol_5_17.cpp

sol_5_17.o: ../sol_5_17.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sol_5_17.o ../sol_5_17.cpp

test_sol_5_59.o: test_sol_5_59.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o test_sol_5_59.o test_sol_5_59.cpp

sol_5_59.o: ../sol_5_59.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sol_5_59.o ../sol_5_59.cpp

test_sol_5_60.o: test_sol_5_60.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o test_sol_5_60.o test_sol_5_60.cpp

sol_5_60.o: ../sol_5_60.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sol_5_60.o ../sol_5_60.cpp

test_sol_5_82.o: test_sol_5_82.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o test_sol_5_82.o test_sol_5_82.cpp

sol_5_82.o: ../sol_5_82.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sol_5_82.o ../sol_5_82.cpp

traverseorder.o: ../traverseorder.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o traverseorder.o ../traverseorder.cpp

test_sol_5_83.o: test_sol_5_83.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o test_sol_5_83.o test_sol_5_83.cpp

sol_5_83.o: ../sol_5_83.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sol_5_83.o ../sol_5_83.cpp

test_sol_5_84.o: test_sol_5_84.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o test_sol_5_84.o test_sol_5_84.cpp

sol_5_84.o: ../sol_5_84.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sol_5_84.o ../sol_5_84.cpp

clean:
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) $(TARGET)
	-$(DEL_FILE) *~
