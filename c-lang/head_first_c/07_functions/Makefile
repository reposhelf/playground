main.o: main.c find.h libc_sort.h dear_johns.h print_ints.h price_drinks.h
	gcc -Wall -c -g main.c

find.o: find.c find.h
	gcc -Wall -c -g find.c

libc_sort.o: libc_sort.c libc_sort.h
	gcc -Wall -c -g libc_sort.c

dear_johns.o: dear_johns.c dear_johns.h
	gcc -Wall -c -g dear_johns.c

print_ints.o: print_ints.c print_ints.h
	gcc -Wall -c -g print_ints.c

price_drinks.o: price_drinks.c price_drinks.h
	gcc -Wall -c -g price_drinks.c

run: main.o find.o libc_sort.o dear_johns.o print_ints.o price_drinks.o
	gcc -Wall -g main.o find.o libc_sort.o dear_johns.o print_ints.o price_drinks.o -o run
