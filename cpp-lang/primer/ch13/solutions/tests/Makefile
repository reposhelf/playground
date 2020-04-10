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
          strblobptr.o \
          test_strblob.o \
          sharedhasptr.o \
          test_sharedhasptr.o \
          treenode.o \
          binstrtree.o \
          test_binstrtree.o \
          hasptr.o \
          test_hasptr.o
TARGET = test

# Build rules

$(TARGET): $(OBJECTS)
	$(LINK) -o $(TARGET) $(OBJECTS) $(LIBS)

# Compile

test.o: test.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o test.o test.cpp

strblob.o: ../strblob.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o strblob.o ../strblob.cpp

strblobptr.o: ../strblobptr.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o strblobptr.o ../strblobptr.cpp

test_strblob.o: test_strblob.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o test_strblob.o test_strblob.cpp

sharedhasptr.o: ../sharedhasptr.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sharedhasptr.o ../sharedhasptr.cpp

test_sharedhasptr.o: test_sharedhasptr.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o test_sharedhasptr.o test_sharedhasptr.cpp

treenode.o: ../treenode.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o treenode.o ../treenode.cpp

binstrtree.o: ../binstrtree.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o binstrtree.o ../binstrtree.cpp

test_binstrtree.o: test_binstrtree.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o test_binstrtree.o test_binstrtree.cpp

hasptr.o: ../hasptr.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o hasptr.o ../hasptr.cpp

test_hasptr.o: test_hasptr.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o test_hasptr.o test_hasptr.cpp

clean:
	$(DEL_FILE) $(OBJECTS)
	$(DEL_FILE) $(TARGET)
