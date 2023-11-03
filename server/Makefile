CC = gcc
CFLAGS = -Wall -std=c11 $(shell pkg-config --cflags gstreamer-1.0)
LDFLAGS = -lm $(shell pkg-config --libs gstreamer-1.0) # Add any necessary libraries here

# Directory structure
BUILD_DIR = build

# List of source files
SRCS = $(wildcard ./*.c)

# List of object files
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

# Output executable name
EXECUTABLE = server

# Default target
all: $(BUILD_DIR) $(EXECUTABLE)

# Create the build directory if it doesn't exist
$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

# Linking
$(EXECUTABLE): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Compiling source files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Clean up
clean:
	@rm -rf $(BUILD_DIR) $(EXECUTABLE)

# Phony target for clean
.PHONY: clean

# Phony target for running the server
run: all
	./$(EXECUTABLE)
