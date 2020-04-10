CPPFLAGS = -g -Wall -std=c++11

date.o: date.cpp date.h
	g++ -c $(CPPFLAGS) date.cpp -o date.o

sol_9_51: sol_9_51.cpp date.o
	g++ $(CPPFLAGS) sol_9_51.cpp date.o -o sol_9_51

%: %.cpp
	g++ $(CPPFLAGS) $^ -o $@
clean:
	rm -f *~ *.o sol_9_2 \
		sol_9_4 \
		sol_9_5 \
		sol_9_13 \
		sol_9_14 \
		sol_9_15 \
		sol_9_16 \
		sol_9_18 \
		sol_9_19 \
		sol_9_20 \
		sol_9_24 \
		sol_9_26 \
		sol_9_27 \
		sol_9_28 \
		sol_9_31 \
		sol_9_38 \
		sol_9_41 \
		sol_9_42 \
		sol_9_43 \
		sol_9_44 \
		sol_9_45 \
		sol_9_46 \
		sol_9_47 \
		sol_9_49 \
		sol_9_50 \
		sol_9_51 \
		sol_9_52
