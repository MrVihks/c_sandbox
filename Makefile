CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -Iinclude -Isrc/core -Isrc/entities -Isrc/world
LDFLAGS = -lraylib -lm -lpthread -ldl -lrt -lX11

SRC = $(wildcard src/*.c) \
      $(wildcard src/core/*.c) \
      $(wildcard src/entities/*.c) \
	  $(wildcard src/world/*.c)
OBJ = $(SRC:.c=.o)

TARGET = game

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

run: all
	./$(TARGET)

clean:
	rm -f src/*.o $(TARGET)