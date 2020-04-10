# Compiler, tools and options

CXX = g++
LINK = g++
CXXFLAGS = -pipe -g -std=gnu++11 -Wall -fPIC
DEL_FILE = rm -f
INCPATH = -I.

# Files

OBJECTS = main.o \
          textquery.o \
          queryresult.o \
	  debugdelete.o
TARGET = main

# Build rules

$(TARGET): $(OBJECTS)
	$(LINK) -o $(TARGET) $(OBJECTS)

# Compile

main.o: main.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

textquery.o: textquery.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o textquery.o textquery.cpp

queryresult.o: queryresult.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o queryresult.o queryresult.cpp

debugdelete.o: debugdelete.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o debugdelete.o debugdelete.cpp

clean:
	$(DEL_FILE) $(OBJECTS)
	$(DEL_FILE) $(TARGET)
