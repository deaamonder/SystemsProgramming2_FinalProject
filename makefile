# # Variables
# CXX = g++
# CXXFLAGS = -std=c++11 -Wall
# TARGET = monopoly_game
# TEST_TARGET = test
# SRC = main.cpp Player.cpp Property.cpp GameBoard.cpp GameLogic.cpp Card.cpp Deck.cpp
# TEST_SRC = test.cpp

# # Default target
# all: $(TARGET) $(TEST_TARGET)

# # Compile the target
# $(TARGET): $(SRC)
# 	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# #compile the test target
# $(TEST_TARGET) : $(TEST_SRC)
# 	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(TEST_SRC)	

# # Clean the build
# clean:
# 	rm -f $(TARGET) $(TEST_TARGET)

# # Run the game
# run: $(TARGET)
# 	./$(TARGET)

# run: $(TEST_TARGET)

# .PHONY: all clean run


# Variables
CXX = g++
CXXFLAGS = -std=c++11 -Wall
TARGET = monopoly_game
TEST_TARGET = test
SRC = main.cpp Player.cpp Property.cpp GameBoard.cpp GameLogic.cpp Card.cpp Deck.cpp
TEST_SRC = test.cpp

# Default target
all: $(TARGET) $(TEST_TARGET)

# Compile the target
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Compile the test target (do not include main.cpp)
$(TEST_TARGET): $(TEST_SRC) $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(TEST_SRC) $(filter-out main.cpp, $(SRC))

# Clean the build
clean:
	rm -f $(TARGET) $(TEST_TARGET)

# Run the game
run_game: $(TARGET)
	./$(TARGET)

# Run the tests
run_test: $(TEST_TARGET)
	./$(TEST_TARGET)

.PHONY: all clean run_game run_test
