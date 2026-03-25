CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -Iinclude -Iincludes/core -Iincludes/gui -Iincludes/entities -Iincludes/scenes -Iincludes/world

ifeq ($(OS),Windows_NT)
	TARGET = game.exe
	LDFLAGS = -lraylib -lopengl32 -lgdi32 -lwinmm
	CLEAN_CMD = rm -f src/**/*.o *.o $(TARGET)
else
	TARGET = game
	LDFLAGS = -lraylib -lm -lpthread -ldl -lrt -lX11
	CLEAN_CMD = rm -f src/**/*.o *.o $(TARGET)
endif

SRC = $(wildcard src/*.c) \
      $(wildcard src/core/*.c) \
      $(wildcard src/entities/*.c) \
	  	$(wildcard src/world/*.c) \
	  	$(wildcard src/scenes/*.c) \
	  	$(wildcard src/gui/*.c) \
	  	$(wildcard ./*.c)

OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

run: all
	./$(TARGET)

clean:
	rm -f src/*.o $(TARGET)