# Define the compiler
CXX = g++

# Define compiler flags
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror

# Define build types
DEBUG_FLAGS = -g
RELEASE_FLAGS = -O2

# Define the build type (default to debug)
BUILD_TYPE = debug

# Define the source files and the output executable
SRC_DIR = src
BIN_DIR = bin
TARGET = $(BIN_DIR)/HelloWorld
SRC = $(SRC_DIR)/main.cpp

# Define the default make target (build the project)
all: $(TARGET)

# Define how to build the target
$(TARGET): $(SRC)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Define a custom run target to execute the program
run: $(TARGET)
	@$(TARGET)

# Clean up build files
clean:
	rm -rf $(BIN_DIR)/*
	rm -rf $(TARGET)
