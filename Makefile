CXX = g++
CXXFLAGS = -std=c++17 -Wall
LDFLAGS = -lmingw32 -lSDL2main -lSDL2

BIN := bin
SRC := src
EXECUTABLE := main

all: $(BIN)/pong

$(BIN)/pong: $(SRC)/main.cpp $(SRC)/GameEngine.cpp
	$(CXX) $(CXXFLAGS) -I include -L lib $^ -o $@ $(LDFLAGS)

#all: 
#	g++ -I include -L lib -o main main.cpp -lmingw32 -lSDL2main -lSDL2