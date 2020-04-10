CC = g++
CFLAGS = -c -g -Wall -std=c++14
DELFILE = rm -f
LDFLAGS =

SOURCES = main.cpp \
	shape.cpp \
	text_view.cpp \
	text_shape_class_adapter.cpp \
	text_shape_object_adapter.cpp

OBJECTS = $(SOURCES:.cpp=.o)

TARGET = drawing_editor

all: $(SOURCES) $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	$(DELFILE) $(OBJECTS)
	$(DELFILE) $(TARGET)
