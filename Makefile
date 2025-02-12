# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror

# Source files
SRCS = $(wildcard *.c)

# Object files directory
OBJDIR = build

# Object files
OBJS = $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS))

# Executable name
TARGET = $(OBJDIR)/tensdb

# Default target
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile source files into object files
$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create the build directory
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Clean up build artifacts
clean:
	rm -rf $(OBJDIR)

# Phony targets
.PHONY: all clean
