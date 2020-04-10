# Compiler, tools and options

CXX = g++
LINK = g++
CXXFLAGS = -pipe -g -std=gnu++11 -Wall -fPIC
DEL_FILE = rm -f
INCPATH = -I.

# Files

OBJECTS = main.o \
          hasptr.o \
          structx.o \
          numbered.o \
          employee.o \
          strblob.o \
          strblobptr.o \
          sharedhasptr.o \
          treenode.o \
          binstrtree.o
TARGET = main

# Build rules

$(TARGET): $(OBJECTS)
	$(LINK) -o $(TARGET) $(OBJECTS)

# Compile

main.o: main.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

hasptr.o: hasptr.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o hasptr.o hasptr.cpp

structx.o: structx.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o structx.o structx.cpp

numbered.o: numbered.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o numbered.o numbered.cpp

employee.o: employee.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o employee.o employee.cpp

strblob.o: strblob.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o strblob.o strblob.cpp

strblobptr.o: strblobptr.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o strblobptr.o strblobptr.cpp

sharedhasptr.o: sharedhasptr.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sharedhasptr.o sharedhasptr.cpp

treenode.o: treenode.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o treenode.o treenode.cpp

binstrtree.o: binstrtree.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o binstrtree.o binstrtree.cpp

clean:
	$(DEL_FILE) $(OBJECTS)
	$(DEL_FILE) $(TARGET)
