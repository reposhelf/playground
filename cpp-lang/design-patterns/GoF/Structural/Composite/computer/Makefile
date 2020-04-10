CC = g++
CFLAGS = -c -g -Wall -std=c++11
DELFILE = rm -f
LDFLAGS = 

SOURCES = main.cpp \
	equipment.cpp \
	composite_equipment.cpp \
	chassis.cpp \
	cabinet.cpp \
	floppy_disk.cpp \
	bus.cpp \
	card.cpp

OBJECTS = $(SOURCES:.cpp=.o)

TARGET = computer

all: $(SOURCES) $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	$(DELFILE) $(OBJECTS)
	$(DELFILE) $(TARGET)
