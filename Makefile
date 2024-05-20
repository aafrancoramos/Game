# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17

# Detect the OS
ifeq ($(OS),Windows_NT)
    SDL2_CFLAGS = `sdl2-config --cflags`
    SDL2_LIBS = `sdl2-config --libs`
    TARGET = sdl2-program.exe
    RM = del
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Darwin)
        SDL2_CFLAGS = `sdl2-config --cflags`
        SDL2_LIBS = `sdl2-config --libs`
        TARGET = sdl2-program
        RM = rm -f
    else
        $(error Unsupported OS: $(UNAME_S))
    endif
endif

# Source files
SRCS = main.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default rule to build the target
all: $(TARGET)

# Rule to link the object files into the target executable
$(TARGET): $(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(SDL2_LIBS)

# Rule to compile the source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(SDL2_CFLAGS) -c $< -o $@

# Rule to clean up the build artifacts
clean:
	$(RM) $(TARGET) $(OBJS)

# Rule to run the program
run: $(TARGET)
	./$(TARGET)
