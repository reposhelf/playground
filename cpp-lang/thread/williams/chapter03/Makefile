CXX = g++
LINK = g++
CXXFLAGS = -pipe -g -Wall -std=gnu++11
DELFILE = rm -f
LIBS = -pthread -lboost_system

HIERARCHICAL_MUTEX_OBJ = hierarchical_mutex.o \
			 listing_3_8.o

TARGETS = listing_3_1 \
	  listing_3_2 \
	  listing_3_5 \
	  listing_3_6 \
	  listing_3_8 \
	  listing_3_9 \
	  listing_3_12 \
	  listing_3_13

hierarchical_mutex.o: hierarchical_mutex.cpp
	$(CXX) -c $^ $(CXXFLAGS) $(LIBS) -o $@

listing_3_8.o: listing_3_8.cpp
	$(CXX) -c $^ $(CXXFLAGS) $(LIBS) -o $@

listing_3_8: listing_3_8.o hierarchical_mutex.o
	$(LINK) $(HIERARCHICAL_MUTEX_OBJ) -o $@

%: %.cpp
	$(CXX) $(CXXFLAGS) $^ $(LIBS) -o $@

clean:
	$(DELFILE) $(TARGETS)
	$(DELFILE) $(HIERARCHICAL_MUTEX_OBJ)
