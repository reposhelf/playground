encrypt.o: encrypt.c
	gcc -c -g encrypt.c -I./includes -o encrypt.o
checksum.o: checksum.c
	gcc -c -g checksum.c -I./includes -o checksum.o
libsecurity.a: encrypt.o checksum.o
	ar -rcs ./libs/libsecurity.a encrypt.o checksum.o
main.o: main.c
	gcc -c -g main.c -I./includes -o main.o
test_code: main.o libsecurity.a
	gcc main.o -L./libs -lsecurity -o test_code
