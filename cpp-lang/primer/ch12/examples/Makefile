# Compiler, tools and options
CXX = g++
LINK = g++
CXXFLAGS = -pipe -g -std=gnu++11 -Wall -W -fPIC
DEL_FILE = rm -f
INCPATH = -I.

# Files
OBJECTS = main.o \
          strblob.o \
          strblobptr.o \
          textquery.o \
          queryresult.o
TARGET = main

# Build rules
$(TARGET): $(OBJECTS)
	$(LINK) -o $(TARGET) $(OBJECTS)

# Compile
main.o: main.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

strblob.o: strblob.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o strblob.o strblob.cpp

strblobptr.o: strblobptr.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o strblobptr.o strblobptr.cpp

textquery.o: textquery.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o textquery.o textquery.cpp

queryresult.o: queryresult.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o queryresult.o queryresult.cpp

clean:
	$(DEL_FILE) $(OBJECTS)
	$(DEL_FILE) $(TARGET)
