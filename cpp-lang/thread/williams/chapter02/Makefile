CXX = g++
CXXFLAGS = -pipe -g -Wall -std=gnu++11
DEL_FILE = rm -f
LIBS = -pthread

TARGETS = listing_2_1 \
          listing_2_2 \
          listing_2_3 \
	  listing_2_4 \
	  listing_2_5 \
	  listing_2_6 \
	  listing_2_7 \
	  listing_2_8

%: %.cpp
	$(CXX) $(CXXFLAGS) $^ $(LIBS) -o $@

clean:
	$(DEL_FILE) $(TARGETS)
