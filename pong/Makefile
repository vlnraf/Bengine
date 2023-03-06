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
LIBS = -L ../lib -L ..
INCLUDE := -I ../Bengine -I ../Bengine/core -I ../include/SDL2 -I .. -I ../include
endif

ifeq ($(detected_OS), Linux)
CXXFLAGS = -std=c++17 -Wall
ASAN_FLAGS = -fsanitize=address -DDEBUG -g
LDFLAGS = `sdl2-config --cflags --libs` -lSDL2 -lSDL2_image -ldl
INCLUDE := -I ../Bengine -I ../Bengine/core
endif

CORE := ../Bengine/core
BIN := bin
SRC := ./
#EXECUTABLE := main

all: $(BIN)/pong 

debug: CXXFLAGS += $(ASAN_FLAGS)
debug: $(BIN)/debug

ifeq ($(detected_OS), Windows)
$(BIN)/pong: $(SRC)/*.cpp $(CORE)/*.cpp
	if not exist $(BIN) (mkdir $(BIN))
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(LIBS) $^ -o $@ $(LDFLAGS)

$(BIN)/debug: $(SRC)/*.cpp $(CORE)/*.cpp
	if not exist $(BIN) (mkdir $(BIN))
	$(CXX) $(CXXFLAGS) $(ASAN_FLAGS) $(INCLUDE) $(LIBS) $^ -o $@ $(LDFLAGS)
endif

ifeq ($(detected_OS), Linux)
$(BIN)/pong: $(SRC)/*.cpp $(CORE)/*.cpp
	mkdir -p $(BIN)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $^ -o $@ $(LDFLAGS)

$(BIN)/debug: $(SRC)/*.cpp $(CORE)/*.cpp
	mkdir -p $(BIN)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $^ -o $@ $(LDFLAGS)
endif

ifeq ($(detected_OS), Linux)
clean:
	rm -f $(BIN)/*
	rm $(BIN)/*.exe
endif

ifeq ($(detected_OS), Windows)
clean:
	rm $(BIN)/*.exe
endif
