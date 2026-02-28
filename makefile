CXX = g++
CXXFLAGS = -std=c++17 -Iinclude -Wall

SRC = $(wildcard src/*.cpp) $(wildcard src/task/*.cpp)
OBJ = $(SRC:.cpp=.o)

TARGET = main

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)