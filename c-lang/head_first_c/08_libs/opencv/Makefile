main.o: main.cpp
	g++ -c -g -std=c++11 -Wall main.cpp -o main.o

webcamdetect: main.o
	g++ main.o -lopencv_core -lopencv_highgui -lopencv_imgproc -o webcamdetect
