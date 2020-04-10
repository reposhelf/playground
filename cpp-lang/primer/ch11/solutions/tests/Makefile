# Compiler, tools, and options

CXX = g++
LINK = g++
CXXFLAGS = -pipe -g -std=gnu++11 -Wall -W -fPIC
DEL_FILE = rm -f
CPPUTEST = /home/vova/bin/cpputest-3.7dev
INCPATH = -I.. -I$(CPPUTEST)/include
LIBS = -L$(CPPUTEST)/lib -lCppUTest

# Files

OBJECTS = test.o \
          test_sol_11_3_4.o \
          sol_11_3_4.o \
          test_sol_11_7.o \
          sol_11_7.o \
          test_sol_11_8.o \
          sol_11_8.o \
          test_sol_11_9.o \
          sol_11_9.o \
          test_sol_11_12.o \
          sol_11_12.o \
          test_sol_11_14.o \
          sol_11_14.o \
          test_sol_11_16.o \
          test_sol_11_31.o
TARGET = test

# Build rules

$(TARGET): $(OBJECTS)
	$(LINK) -o $(TARGET) $(OBJECTS) $(LIBS)

# Compile

test.o: test.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o test.o test.cpp

test_sol_11_3_4.o: test_sol_11_3_4.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o test_sol_11_3_4.o test_sol_11_3_4.cpp

sol_11_3_4.o: ../sol_11_3_4.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sol_11_3_4.o ../sol_11_3_4.cpp

test_sol_11_7.o: test_sol_11_7.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o test_sol_11_7.o test_sol_11_7.cpp

sol_11_7.o: ../sol_11_7.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sol_11_7.o ../sol_11_7.cpp

test_sol_11_8.o: test_sol_11_8.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o test_sol_11_8.o test_sol_11_8.cpp

sol_11_8.o: ../sol_11_8.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sol_11_8.o ../sol_11_8.cpp

test_sol_11_9.o: test_sol_11_9.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o test_sol_11_9.o test_sol_11_9.cpp

sol_11_9.o: ../sol_11_9.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sol_11_9.o ../sol_11_9.cpp

test_sol_11_12.o: test_sol_11_12.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o test_sol_11_12.o test_sol_11_12.cpp

sol_11_12.o: ../sol_11_12.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sol_11_12.o ../sol_11_12.cpp

test_sol_11_14.o: test_sol_11_14.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o test_sol_11_14.o test_sol_11_14.cpp

sol_11_14.o: ../sol_11_14.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sol_11_14.o ../sol_11_14.cpp

test_sol_11_16.o: test_sol_11_16.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o test_sol_11_16.o test_sol_11_16.cpp

test_sol_11_31.o: test_sol_11_31.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o test_sol_11_31.o test_sol_11_31.cpp

clean:
	$(DEL_FILE) $(OBJECTS)
	$(DEL_FILE) $(TARGET)
	$(DEL_FILE) *~
