# Compiler, tools and options
CXX = g++
LINK = g++
CXXFLAGS = -pipe -std=gnu++11 -Wall -W -fPIC
DELFILE = rm -f
INCPATH = -I.

# Files
OBJECTS = main.o \
	  Sales_data.o
TARGET = main

# Build rules
$(TARGET): $(OBJECTS)
	$(LINK) -o $(TARGET) $(OBJECTS)

# Compile
main.o: main.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

Sales_data.o: Sales_data.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Sales_data.o Sales_data.cpp

clean:
	$(DELFILE) $(OBJECTS)
	$(DELFILE) $(TARGET)
