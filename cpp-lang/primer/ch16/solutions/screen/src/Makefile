# Compilers, tools and options
CXX = g++
LINK = g++
CXXFLAGS = -pipe -g -std=gnu++11 -Wall -fPIC
DELFILE = rm -f
INCPATH = -I.

# Files
OBJECTS = main.o \
	  screen.o
TARGET = screen

# Build rules
$(TARGET): $(OBJECTS)
	$(LINK) -o $(TARGET) $(OBJECTS)

# Compile
main.o: main.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

screen.o: screen.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o screen.o screen.cpp

clean:
	$(DELFILE) $(OBJECTS)
	$(DELFILE) $(TARGET)
