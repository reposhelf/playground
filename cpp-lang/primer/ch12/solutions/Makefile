# Compiler, tools and options

CXX = g++
LINK = g++
CXXFLAGS = -pipe -g -std=gnu++11 -Wall -fPIC
DEL_FILE = rm -f
INCPATH = -I.

# Files

OBJECTS = main.o \
          strblob.o \
          sol_12_6.o \
          sol_12_7.o \
          sol_12_14.o \
          strblobptr.o \
          conststrblobptr.o \
          sol_12_23.o \
          sol_12_24.o \
          sol_12_26.o \
          textquery.o \
          queryresult.o \
          sol_12_28.o
TARGET = main

# Build rules

$(TARGET): $(OBJECTS)
	$(LINK) -o $(TARGET) $(OBJECTS)

# Compile

main.o: main.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

strblob.o: strblob.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o strblob.o strblob.cpp

sol_12_6.o: sol_12_6.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sol_12_6.o sol_12_6.cpp

sol_12_7.o: sol_12_7.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sol_12_7.o sol_12_7.cpp

sol_12_14.o: sol_12_14.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sol_12_14.o sol_12_14.cpp

strblobptr.o: strblobptr.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o strblobptr.o strblobptr.cpp

conststrblobptr.o: conststrblobptr.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o conststrblobptr.o conststrblobptr.cpp

sol_12_23.o: sol_12_23.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sol_12_23.o sol_12_23.cpp

sol_12_24.o: sol_12_24.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sol_12_24.o sol_12_24.cpp

sol_12_26.o: sol_12_26.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sol_12_26.o sol_12_26.cpp
	
textquery.o: textquery.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o textquery.o textquery.cpp

queryresult.o: queryresult.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o queryresult.o queryresult.cpp

sol_12_28.o: sol_12_28.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sol_12_28.o sol_12_28.cpp

clean:
	$(DEL_FILE) $(OBJECTS)
	$(DEL_FILE) $(TARGET)
