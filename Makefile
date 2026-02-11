CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -I./src

SRC := $(shell find src -name '*.cpp')
OBJ := $(SRC:.cpp=.o)
TARGET = ditto

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
