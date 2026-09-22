CXX ?= g++
CXXFLAGS ?= -std=c++20 -Wall -Wextra -Wpedantic -Werror
CPPFLAGS ?= -Iinclude

BIN_DIR := bin
BUILD_DIR := build
APP := $(BIN_DIR)/packet_analysis
TEST_APP := $(BIN_DIR)/packet_analysis_tests

APP_OBJECTS := $(BUILD_DIR)/packet_analysis.o $(BUILD_DIR)/main.o
TEST_OBJECTS := $(BUILD_DIR)/packet_analysis.o $(BUILD_DIR)/test_main.o \
	$(BUILD_DIR)/supplied_tests.o $(BUILD_DIR)/student_tests.o

.PHONY: all test clean

all: $(APP)

$(APP): $(APP_OBJECTS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(APP_OBJECTS) -o $@

$(TEST_APP): $(TEST_OBJECTS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(TEST_OBJECTS) -o $@

$(BUILD_DIR)/%.o: src/%.cpp include/packet_analysis.hpp | $(BUILD_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: tests/%.cpp include/packet_analysis.hpp | $(BUILD_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

$(BIN_DIR) $(BUILD_DIR):
	mkdir -p $@

test: $(TEST_APP)
	./$(TEST_APP)

clean:
	rm -rf $(BIN_DIR) $(BUILD_DIR)
