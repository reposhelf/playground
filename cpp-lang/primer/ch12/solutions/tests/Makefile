# Compiler, tools and options

CXX = g++
LINK = g++
CXXFLAGS = -pipe -g -std=gnu++11 -Wall -fPIC
DEL_FILE = rm -f
CPPUTEST = /home/vova/bin/cpputest-3.7dev
INCPATH = -I.. -I$(CPPUTEST)/include
LIBS = -L$(CPPUTEST)/lib -lCppUTest

# Files

OBJECTS = test.o \
          strblob.o \
          test_strblob.o \
          sol_12_6.o \
          test_sol_12_6.o \
          sol_12_7.o \
          test_sol_12_7.o \
          sol_12_14.o \
          test_sol_12_14.o \
          test_sol_12_15.o \
          strblobptr.o \
          test_sol_12_20.o \
          conststrblobptr.o \
          test_sol_12_22.o
TARGET = test

# Build rules

$(TARGET): $(OBJECTS)
	$(LINK) -o $(TARGET) $(OBJECTS) $(LIBS)

# Compile

test.o: test.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o test.o test.cpp

strblob.o: ../strblob.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o strblob.o ../strblob.cpp

test_strblob.o: test_strblob.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o test_strblob.o test_strblob.cpp

sol_12_6.o: ../sol_12_6.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sol_12_6.o ../sol_12_6.cpp

test_sol_12_6.o: test_sol_12_6.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o test_sol_12_6.o test_sol_12_6.cpp

sol_12_7.o: ../sol_12_7.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sol_12_7.o ../sol_12_7.cpp

test_sol_12_7.o: test_sol_12_7.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o test_sol_12_7.o test_sol_12_7.cpp

sol_12_14.o: ../sol_12_14.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sol_12_14.o ../sol_12_14.cpp

test_sol_12_14.o: test_sol_12_14.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o test_sol_12_14.o test_sol_12_14.cpp

test_sol_12_15.o: test_sol_12_15.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o test_sol_12_15.o test_sol_12_15.cpp

strblobptr.o: ../strblobptr.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o strblobptr.o ../strblobptr.cpp

test_sol_12_20.o: test_sol_12_20.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o test_sol_12_20.o test_sol_12_20.cpp

conststrblobptr.o: ../conststrblobptr.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o conststrblobptr.o ../conststrblobptr.cpp

test_sol_12_22.o: test_sol_12_22.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o test_sol_12_22.o test_sol_12_22.cpp

clean:
	$(DEL_FILE) $(OBJECTS)
	$(DEL_FILE) $(TARGET)
