netstream.o: netstream.c
	gcc -c -g -Wall -fPIC netstream.c -Iinclude -o netstream.o

libnetstream.so: netstream.o
	gcc -shared netstream.o -o lib/libnetstream.so

clean:
	rm -f *~ *.o include/*~
