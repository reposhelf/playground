# Compiler, tools and options

CC       = gcc
CFLAGS   = -Wall -Wextra -O2 -g
DEL_FILE = rm -f

# Compile command

%: %.c
	$(CC) $(CFLAGS) -o $@ $^

# Files

TARGETS = main

# Clean

clean:
	-$(DEL_FILE) $(TARGETS)
	-$(DEL_FILE) *~
