CPPFLAGS = -g -Wall -std=c++11

hello: hello.cpp
	g++ $(CPPFLAGS) $^ -o $@

%: %.cpp
	g++ $(CPPFLAGS) $^ -pthread -o $@

clean:
	rm -f *~ *.o hello hello_threads