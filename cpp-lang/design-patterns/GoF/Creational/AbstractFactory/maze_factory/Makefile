CC = g++
CFLAGS = -c -g -Wall -std=gnu++11
DELFILE = rm -f
LDFLAGS = 
SOURCES = main.cpp \
    maze_factory.cpp \
    bombed_maze_factory.cpp \
    enchanted_maze_factory.cpp \
    map_site.cpp \
    wall.cpp \
    bombed_wall.cpp \
    room.cpp \
    room_with_a_bomb.cpp \
    enchanted_room.cpp \
    door.cpp \
    door_needing_spell.cpp \
    maze.cpp \
    maze_game.cpp

OBJECTS = $(SOURCES:.cpp=.o)

TARGET = maze_factory

all: $(SOURCES) $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	$(DELFILE) $(OBJECTS)
	$(DELFILE) $(TARGET)
