# Compiler
CC = g++

# Compiler flags
CXXFLAGS = -Iinclude -Wall -Wextra -pedantic

# Linker flags
LINKER_FLAGS = -lncurses

# Source and object files
SRCDIR = src
OBJDIR = obj
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))
OBJ_NAME = pacman


# Default rule
all: $(OBJ_NAME)
	@echo "Build complete. Executable: $(OBJ_NAME)"

run: all
	./${OBJ_NAME}

# Link the executable
$(OBJ_NAME): $(OBJECTS)
	$(CC) $(OBJECTS) $(LINKER_FLAGS) -o $@
	@echo "Linking complete. Created executable: $@"

# Compile source files to object files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CC) $(CXXFLAGS) -c $< -o $@
	@echo "Compiled: $< -> $@"

# Create the object directory if it doesn't exist
$(OBJDIR):
	mkdir -p $(OBJDIR)
	@echo "Created directory: $(OBJDIR)"

#to add to github repo
#make git m="message" b="your-branch(main by defualt)"
b?=main
m?=$(shell date '+%Y-%m-%d %H:%M:%S')
git: 
	git add .
	git commit -m "$(m)"
	git push origin $(b)

push:
	git push origin $(b)

# Clean up generated files
clean:
	rm -rf $(OBJDIR) $(OBJ_NAME)
	@echo "Cleaned up generated files."

# Phony targets
.PHONY: all clean

