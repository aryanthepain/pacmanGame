# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Iinclude -Wall -Wextra -pedantic

# Source and object files
SRCDIR = src
OBJDIR = obj
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))
EXEC = pacman

# Default rule
all: $(EXEC)
	@echo "    "
	@echo "=============="
	@echo "Compilation completed successfully"
	
# Link the executable
$(EXEC): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@

# Compile source files to object files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create the object directory if it doesn't exist
$(OBJDIR):
	mkdir -p $(OBJDIR)
	
git:
	git add .
	git commit -m "$(m)"
	git push origin main

# Clean up generated files
clean:
	rm -rf $(OBJDIR) $(EXEC)

# Phony targets
.PHONY: all clean

