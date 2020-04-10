# Compiler, tools and options
CXX = g++
LINK = g++
CXXFLAGS = -pipe -std=gnu++11 -Wall -W -fPIC
DEL_FILE = rm -f
INCPATH = -I.

# Files
OBJECTS = main.o \
	  TextQuery.o \
	  QueryResult.o \
	  Query.o \
	  QueryBase.o \
	  BinaryQuery.o \
	  AndQuery.o \
	  OrQuery.o \
	  NotQuery.o \
	  WordQuery.o \
	  PerOnceQuery.o \
	  OutputQuery.o
TARGET = textquery

# Build rules
$(TARGET): $(OBJECTS)
	$(LINK) -o $(TARGET) $(OBJECTS)

# Compile
main.o: main.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

TextQuery.o: TextQuery.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o TextQuery.o TextQuery.cpp

QueryResult.o: QueryResult.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o QueryResult.o QueryResult.cpp

Query.o: Query.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Query.o Query.cpp

QueryBase.o: QueryBase.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o QueryBase.o QueryBase.cpp

BinaryQuery.o: BinaryQuery.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o BinaryQuery.o BinaryQuery.cpp

AndQuery.o: AndQuery.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o AndQuery.o AndQuery.cpp

OrQuery.o: OrQuery.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o OrQuery.o OrQuery.cpp

NotQuery.o: NotQuery.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o NotQuery.o NotQuery.cpp

WordQuery.o: WordQuery.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o WordQuery.o WordQuery.cpp

PerOnceQuery.o: PerOnceQuery.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o PerOnceQuery.o PerOnceQuery.cpp

OutputQuery.o: OutputQuery.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o OutputQuery.o OutputQuery.cpp

clean:
	$(DEL_FILE) $(OBJECTS)
	$(DEL_FILE) $(TARGET)
