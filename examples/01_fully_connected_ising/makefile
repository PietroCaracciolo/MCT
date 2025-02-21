# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -O3 -g -Wextra -Iinterface/include -Imodel/include -Iinterface/thirdparty

# Directories
BUILD_DIR = build

# Source files
SRCS = interface/src/main.cpp \
       interface/src/abstract_model.cpp \
       model/src/averages.cpp \
       model/src/interactions.cpp \
       model/src/parameters.cpp \
       model/src/state.cpp \
       model/src/update.cpp

# Object files
OBJS = $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# Output executable
TARGET = executable

# Default target
all: $(TARGET)

# Rule to build the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

# Rule to compile each source file into an object file
$(BUILD_DIR)/interface/src/%.o: interface/src/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/model/src/%.o: model/src/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean the build files
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET) test 0

