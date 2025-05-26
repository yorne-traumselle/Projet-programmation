#Compilateur
CXX = g++
CXXFLAGS = -Wall -Wextra
DEBUGFLAGS = -g -O0

#Repertoires
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
ASSESTS_DIR = assets

#Fichiers sources
SRC_FILES = $(shell find $(SRC_DIR) -name '*.cpp')
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

#Executable
TARGET = $(BIN_DIR)/game

#Options liaison- SDL
SDL2_CFLAGS = $(shell sdl2-config --cflags)
SDL2_LDFLAGS = $(shell sdl2-config --libs) -lSDL2_image -lSDL2_ttf -lSDL2_gfx

#Règles 
all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(SDL2_LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(SDL2_CFLAGS) -c -o $@ $<

debug: CXXFLAGS += $(DEBUGFLAGS)
debug: all

clean: 
	rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: all debug clean

