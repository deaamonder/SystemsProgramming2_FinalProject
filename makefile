# Variables
CXX = g++
CXXFLAGS = -std=c++11 -Wall
TARGET = monopoly_game
SRC = main.cpp Player.cpp Property.cpp GameBoard.cpp GameLogic.cpp

# Default target
all: $(TARGET)

# Compile the target
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Clean the build
clean:
	rm -f $(TARGET)

# Run the game
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
