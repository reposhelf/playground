# Compiler, tools and options
CXX = g++
LINK = g++
CXXFLAGS = -pipe -g -std=gnu++11 -Wall -fPIC
DELFILE = rm -f
INCPATH = -I.

# Files
OBJECTS = main.o \
	  vec.o
TARGET = vec

# Build rules
$(TARGET): $(OBJECTS)
	$(LINK) -o $(TARGET) $(OBJECTS)

# Compile
main.o: main.cpp
	$(CXX) -c $(CXXFLAGS) -o main.o main.cpp

vec.o: vec.cpp
	$(CXX) -c $(CXXFLAGS) -o vec.o vec.cpp

clean:
	$(DELFILE) $(OBJECTS)
	$(DELFILE) $(TARGET)
