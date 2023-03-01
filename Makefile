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

BIN := bin
SRC := src
#EXECUTABLE := main

all: $(BIN)/pong 

debug: CXXFLAGS += $(ASAN_FLAGS)
debug: $(BIN)/debug

ifeq ($(detected_OS), Windows)
$(BIN)/pong: $(SRC)/*.cpp
	$(CXX) $(CXXFLAGS) $(ASAN_FLAGS) -I include -L lib $^ -o $@ $(LDFLAGS)

$(BIN)/debug: $(SRC)/*.cpp
	$(CXX) $(CXXFLAGS) $(ASAN_FLAGS) -I include -L lilb $^ -o $@ $(LDFLAGS)
endif

ifeq ($(detected_OS), Linux)
$(BIN)/pong: $(SRC)/*.cpp
	mkdir -p $(BIN)
	$(CXX) $(CXXFLAGS) -I include $^ -o $@ $(LDFLAGS)

$(BIN)/debug: $(SRC)/*.cpp
	mkdir -p $(BIN)
	$(CXX) $(CXXFLAGS) -I include $^ -o $@ $(LDFLAGS)
endif

ifeq ($(detected_OS), Linux)
clean:
	rm -f $(BIN)/*
endif

ifeq ($(detected_OS), Windows)
clean:
	rm $(BIN)/*.exe
endif
