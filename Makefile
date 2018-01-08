CPP := g++
SRC_DIR := src
BUILD_DIR := build

SOURCES := $(shell find $(SRC_DIR) -type f -name *.cpp)
CFLAGS := -g -std=c++17 -Wall 
INCL := -I include
# Substitute .o on source files to get objects
OBJECTS := $(patsubst $(SRC_DIR)/%,$(BUILD_DIR)/%,$(SOURCES:.cpp=.o))

# Remember to give this a better name!
TARGET := bin/runner

$(TARGET): $(OBJECTS) # Linking!
	@echo "Linking files..."
	$(CPP) $^ -o $(TARGET) 

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp # Compiling!
	@mkdir -p $(BUILD_DIR)
	@echo "Building $<"
	$(CPP) $(CFLAGS) $(INCL) -c -o $@ $<

clean:
	@echo "Cleaning..."
	$(RM) -r $(BUILD_DIR) $(TARGET)


.PHONY: clean