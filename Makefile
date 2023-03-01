ifeq ($(OS), Windows_NT)
	detected_OS := Windows
else
	detected_OS := $(shell uname)
endif

CXX = g++
ifeq ($(detected_OS), Windows)
ASAN_FLAGS = -fsanitize=address
CXXFLAGS = -std=c++17 -Wall
LDFLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
endif

ifeq ($(detected_OS), Linux)
CXXFLAGS = -std=c++17 -Wall
#LDFLAGS = -lSDL2main -lSDL2 -ldl -lSDL2_image
ASAN_FLAGS = -fsanitize=address
LDFLAGS = `sdl2-config --cflags --libs` -lSDL2 -lSDL2_image -ldl
endif

BIN := bin
SRC := src
EXECUTABLE := main

all: $(BIN)/pong

ifeq ($(detected_OS), Windows)
$(BIN)/pong: $(SRC)/*.cpp
	mkdir -p $(BIN)
	$(CXX) $(CXXFLAGS) $(ASAN_FLAGS) -I include -L lib $^ -o $@ $(LDFLAGS)
endif

ifeq ($(detected_OS), Linux)
$(BIN)/pong: $(SRC)/*.cpp
	mkdir -p $(BIN)
	$(CXX) $(CXXFLAGS) $(ASAN_FLAGS) -I include $^ -o $@ $(LDFLAGS)
endif

ifeq ($(detected_OS), Linux)
clean:
	rm -f $(BIN)/*
endif

ifeq ($(detected_OS), Windows)
clean:
	rm $(BIN)/*.exe
endif
