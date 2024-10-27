CC = gcc

CFLAGS = -Iinclude -g

SRC = $(shell find src -name "*.c")
OBJ = $(SRC:.c=.o)

TARGET = main

$(TARGET): $(OBJ)
	$(CC) -o $@ $(OBJ)

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

echo:
	@echo "Source files: $(SRC)"

clean:
	find . -name \*.o -type f -delete
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)
