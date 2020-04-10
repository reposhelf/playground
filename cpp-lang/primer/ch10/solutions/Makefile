CPPFLAGS = -g -Wall -std=c++11

Sales_data.o: Sales_data.cpp
	g++ -c $(CPPFLAGS) $^ -o $@

sol_10_12.o: sol_10_12.cpp
	g++ -c $(CPPFLAGS) $^ -o $@

sol_10_12: sol_10_12.o Sales_data.o
	g++ sol_10_12.o Sales_data.o -o sol_10_12

sol_10_17.o: sol_10_17.cpp
	g++ -c $(CPPFLAGS) $^ -o $@

sol_10_17: sol_10_17.o Sales_data.o
	g++ sol_10_17.o Sales_data.o -o sol_10_17

sol_10_32.o: sol_10_32.cpp
	g++ -c $(CPPFLAGS) $^ -o $@

sol_10_32: sol_10_32.o Sales_data.o
	g++ sol_10_32.o Sales_data.o -o sol_10_32

%: %.cpp
	g++ $(CPPFLAGS) $^ -o $@

clean:
	rm -f *~ *.o \
		sol_10_1 \
		sol_10_2 \
		sol_10_3 \
		sol_10_6 \
		sol_10_7 \
		sol_10_9 \
		sol_10_11 \
		sol_10_12 \
		sol_10_13 \
		sol_10_14 \
		sol_10_15 \
		sol_10_16 \
		sol_10_17 \
		sol_10_18 \
		sol_10_19 \
		sol_10_20 \
		sol_10_21 \
		sol_10_22 \
		sol_10_24 \
		sol_10_25 \
		sol_10_27 \
		sol_10_28 \
		sol_10_29 \
		sol_10_30 \
		sol_10_31 \
		sol_10_32 \
		sol_10_33 \
		sol_10_34 \
		sol_10_35 \
		sol_10_36 \
		sol_10_37 \
		sol_10_42
