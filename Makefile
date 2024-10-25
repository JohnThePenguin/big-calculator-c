# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Iinclude -Wall

# Directories containing source files
SRC_DIRS = src src/numbers src/vector src/error

# Find all .c files in SRC_DIRS
SRCS = $(shell find $(SRC_DIRS) -name "*.c")

# Create corresponding .o files in the same directory
OBJS = $(SRCS:.c=.o)

# Output binary
TARGET = main

# Build target
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

# Rule to compile each .c file to a .o file
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJS) $(TARGET)
