CC = gcc

CFLAGS = -Iinclude -g -ansi -std=c89 -pedantic 
# -fsanitize=address

SRC = $(shell find src -name "*.c")
OBJ = $(SRC:.c=.o)

TARGET = build/main

$(TARGET): $(OBJ)
	$(CC) -o $@ $(OBJ)

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

echo:
	@echo "Source files: $(SRC)"

clear:
	find . -name \*.o -type f -delete
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)
