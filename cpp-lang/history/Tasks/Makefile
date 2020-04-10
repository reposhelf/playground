CPPFLAGS = -Wall -std=c++11

%: %.cpp
	g++ $(CPPFLAGS) $^ -lpthread -o $@

clean:
	rm -f *~ *.o thread shrink_buf
