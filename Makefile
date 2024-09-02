# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Iinclude -Wall -Wextra -pedantic

# Source and object files
SOURCES = $(wildcard *.cpp)
OBJECTS = $(patsubst %.cpp, %.o, $(SOURCES))
OBJ_NAME = stack

# Default rule
all: $(OBJ_NAME)
	@echo "Build complete. Executable: $(OBJ_NAME)"

# Link the executable
$(OBJ_NAME): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@
	@echo "Linking complete. Created executable: $@"

# Compile source files to object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "Compiled: $< -> $@"

# Run the program
run: all
	./$(OBJ_NAME)

# Clean up generated files
clean:
	rm -f $(OBJECTS) $(OBJ_NAME)
	@echo "Cleaned up generated files."

# Git related commands
# make git m="message" b="your-branch(main by default)"
b?=main
m?=$(shell date '+%Y-%m-%d %H:%M:%S')
git:
	git add .
	git commit -m "$(m)"
	git push origin $(b)

push:
	git push origin $(b)

# Phony targets
.PHONY: all clean run git push

