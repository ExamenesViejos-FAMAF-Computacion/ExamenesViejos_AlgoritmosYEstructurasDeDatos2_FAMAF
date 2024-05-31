CC = gcc
CFLAGS = -std=c99 -Wall -Werror -Wextra -pedantic  -g
SOURCES = pqueue.c main.c $(wildcard character/*.c)
OBJECTS = $(SOURCES:.c=.o)
TARGET = show_initiative
TESTFILES = $(shell ls ./inputs)

.PHONY: clean

all: $(TARGET)

test: $(TARGET) $(TESTFILES)

%.in:
	./$(TARGET) ./inputs/$*.in


$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS) $(LFLAGS) $(LIBS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS) $(TARGET)