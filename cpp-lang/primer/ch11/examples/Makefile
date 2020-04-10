CXX = g++
CXXFLAGS = -pipe -g -std=gnu++11 -Wall -W -fPIC
DEL_FILE = rm -f

%: %.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	$(DEL_FILE) *~
	$(DEL_FILE) *.o
	$(DEL_FILE) word_count
	$(DEL_FILE) restricted_count
	$(DEL_FILE) set_ops
	$(DEL_FILE) multimap
	$(DEL_FILE) word_transform
