CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -O2 -g
SRC := main.cpp func.cpp
OBJ := $(SRC:.cpp=.o)
TARGET := structs

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJ) $(DEPS) $(TARGET)