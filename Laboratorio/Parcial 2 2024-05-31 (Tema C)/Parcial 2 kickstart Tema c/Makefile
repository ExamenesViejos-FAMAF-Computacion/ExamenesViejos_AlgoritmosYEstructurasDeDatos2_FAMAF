CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c99
SOURCES = testing.c pokerdeck.c pokerdeck_helpers.c
OBJECTS = $(SOURCES:.c=.o)
TARGET = testdeck

.PHONY: clean

all: $(TARGET)

test: $(TARGET)
	./$(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS) $(LFLAGS) $(LIBS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS) $(TARGET)
