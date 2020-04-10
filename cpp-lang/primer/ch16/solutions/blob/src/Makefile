# Compiler, tools and options
CXX = g++
LINK = g++
CXXFLAGS = -pipe -std=gnu++11 -Wall -W -fPIC
DELFILE = rm -f
INCPATH = -I.

# Files
OBJECTS = main.o \
	  blob.o \
	  blobptr.o \
	  constblobptr.o
TARGET = blob

# Build rules
$(TARGET): $(OBJECTS)
	$(LINK) -o $(TARGET) $(OBJECTS)

# Compile
main.o: main.cpp
	$(CXX) -c $(CXXFLAGS) -o main.o main.cpp

blob.o: blob.cpp
	$(CXX) -c $(CXXFLAGS) -o blob.o blob.cpp

blobptr.o: blobptr.cpp
	$(CXX) -c $(CXXFLAGS) -o blobptr.o blobptr.cpp

constblobptr.o: constblobptr.cpp
	$(CXX) -c $(CXXFLAGS) -o constblobptr.o constblobptr.cpp

clean:
	$(DELFILE) $(OBJECTS)
	$(DELFILE) $(TARGET)
