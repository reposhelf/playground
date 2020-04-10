# Compiler, tools and options
CXX = g++
LINK = g++
CXXFLAGS = -pipe -std=gnu++11 -Wall -W -fPIC
DELFILE = rm -f
INCPATH = -I.

# Files
OBJECTS = main.o #\
	blob.o \
	blobptr.o \
	constblobptr.o \
	shared_pointer.o
TARGET = blob

# Build rules
$(TARGET): $(OBJECTS)
	$(LINK) -o $(TARGET) $(OBJECTS)

# Compile
main.o: main.cpp
	$(CXX) -c $(CXXFLAGS) -o main.o main.cpp

clean:
	$(DELFILE) $(OBJECTS)
	$(DELFILE) $(TARGET)
