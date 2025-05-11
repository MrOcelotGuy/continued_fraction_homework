# Compiler and flags
CXX = clang++
CXXFLAGS = -std=c++17 -IHeader_Files

# Source files
SOURCES = Driver_Files/main.cpp Source_Files/ContinuedFraction.cpp

# Output file
OUTPUT = main

# Build rule
all: $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(OUTPUT)

# Clean rule
clean:
	rm -f $(OUTPUT)
