# ELLIPTICAL
cal.o: cal.c
	gcc -c cal.c -fPIC -I./includes -o cal.o

elliptical.o: elliptical.c
	gcc -c elliptical.c -I./includes -o elliptical.o

libcal.so: cal.o
	gcc -shared cal.o -o ./libs/libcal.so

elliptical: elliptical.o libcal.so
	gcc elliptical.o -L./libs -lcal -o elliptical

# TREADMILL
cal_UK.o: cal_UK.c
	gcc -c cal_UK.c -fPIC -I./includes -o cal_UK.o

treadmill.o: treadmill.c
	gcc -c treadmill.c -I./includes -o treadmill.o

libcal_UK.so: cal_UK.o
	gcc -shared cal_UK.o -o ./libs/libcal_UK.so

treadmill: treadmill.o libcal_UK.so
	gcc treadmill.o -L./libs -lcal_UK -o treadmill
