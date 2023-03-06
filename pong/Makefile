ifeq ($(OS), Windows_NT)
	detected_OS := Windows
else
	detected_OS := $(shell uname)
endif

CXX = g++
ifeq ($(detected_OS), Windows)
CXXFLAGS = -std=c++17 -Wall
ASAN_FLAGS = -fsanitize=address -DDEBUG -g
LDFLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
endif

ifeq ($(detected_OS), Linux)
CXXFLAGS = -std=c++17 -Wall
ASAN_FLAGS = -fsanitize=address -DDEBUG -g
LDFLAGS = `sdl2-config --cflags --libs` -lSDL2 -lSDL2_image -ldl
endif

CORE := ../Bengine/core
BIN := bin
SRC := ./
INCLUDE := -I ../Bengine -I ../Bengine/core
#EXECUTABLE := main

all: $(BIN)/pong 

debug: CXXFLAGS += $(ASAN_FLAGS)
debug: $(BIN)/debug

ifeq ($(detected_OS), Windows)
$(BIN)/pong: $(SRC)/*.cpp
	mkdir -p $(BIN)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -L lib $^ -o $@ $(LDFLAGS)

$(BIN)/debug: $(SRC)/*.cpp
	mkdir -p $(BIN)
	$(CXX) $(CXXFLAGS) $(ASAN_FLAGS) $(INCLUDE) -L lib $^ -o $@ $(LDFLAGS)
endif

ifeq ($(detected_OS), Linux)
$(BIN)/pong: $(SRC)/*.cpp $(CORE)/*.cpp
	mkdir -p $(BIN)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $^ -o $@ $(LDFLAGS)

$(BIN)/debug: $(SRC)/*.cpp
	mkdir -p $(BIN)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $^ -o $@ $(LDFLAGS)
endif

ifeq ($(detected_OS), Linux)
clean:
	rm -f $(BIN)/*
endif

ifeq ($(detected_OS), Windows)
clean:
	rm $(BIN)/*.exe
endif
