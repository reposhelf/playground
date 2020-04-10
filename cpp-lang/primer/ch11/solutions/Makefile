# Compiler, tools and options

CXX = g++
LINK = g++
CXXFLAGS = -pipe -g -std=gnu++11 -Wall -W -fPIC
DEL_FILE = rm -f
INCPATH = -I.
LIBS = 

# Files

OBJECTS = main.o \
          sol_11_3_4.o \
          sol_11_7.o \
          sol_11_8.o \
          sol_11_9.o \
          sol_11_12.o \
          sol_11_14.o \
          sol_11_18.o \
          sol_11_20.o \
          sol_11_22.o \
          sol_11_28.o \
          sol_11_32.o \
          sol_11_38_1.o \
          sol_11_38_2.o
TARGET = main

# Build rules

$(TARGET): $(OBJECTS)
	$(LINK) -o $(TARGET) $(OBJECTS) $(LIBS)

# Compile

main.o: main.cpp chapter11.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

sol_11_3_4.o: sol_11_3_4.cpp chapter11.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sol_11_3_4.o sol_11_3_4.cpp

sol_11_7.o: sol_11_7.cpp chapter11.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sol_11_7.o sol_11_7.cpp

sol_11_8.o: sol_11_8.cpp chapter11.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sol_11_8.o sol_11_8.cpp

sol_11_9.o: sol_11_9.cpp chapter11.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sol_11_9.o sol_11_9.cpp

sol_11_12.o: sol_11_12.cpp chapter11.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sol_11_12.o sol_11_12.cpp

sol_11_14.o: sol_11_14.cpp chapter11.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sol_11_14.o sol_11_14.cpp

sol_11_18.o: sol_11_18.cpp chapter11.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sol_11_18.o sol_11_18.cpp

sol_11_20.o: sol_11_20.cpp chapter11.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sol_11_20.o sol_11_20.cpp

sol_11_22.o: sol_11_22.cpp chapter11.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sol_11_22.o sol_11_22.cpp

sol_11_28.o: sol_11_28.cpp chapter11.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sol_11_28.o sol_11_28.cpp

sol_11_32.o: sol_11_32.cpp chapter11.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sol_11_32.o sol_11_32.cpp

sol_11_38_1.o: sol_11_38_1.cpp chapter11.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sol_11_38_1.o sol_11_38_1.cpp

sol_11_38_2.o: sol_11_38_2.cpp chapter11.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sol_11_38_2.o sol_11_38_2.cpp

clean:
	$(DEL_FILE) $(OBJECTS)
	$(DEL_FILE) $(TARGET)
	$(DEL_FILE) *~
