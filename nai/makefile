CXX := g++
CXXFLAGS := -std=c++98 
TARGET := ./lpc.exe

SRC := ejercicio1/main.cpp
OBJ := $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $^ -o $@

%.o: %.cpp
	$(CXX) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean