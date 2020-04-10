main.o: main.c fruit_order.h
	gcc -c main.c

fruit_order.o: fruit_order.c fruit_order.h
	gcc -c fruit_order.c

enumtest: main.o fruit_order.o
	gcc main.o fruit_order.o -o enumtest