# compilateur + options
CC = g++ -Wall -std=c++11
CCO = $(CC) -c $<

# dossier des sources
SRC_DIR = src

# dossier des objets intermédiaires
OBJ_DIR = $(SRC_DIR)/obj

# liste des fichiers sources
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)

# liste des objets intermédiaires
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))

# exécutable
EXECUTABLE = sfml-app

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXECUTABLE) -lsfml-graphics -lsfml-window -lsfml-system

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CCO) -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

run: $(EXECUTABLE)
	./$(EXECUTABLE)

clean:
	rm -rf $(OBJ_DIR)/*.o $(EXECUTABLE)
	rm -rf $(OBJ_DIR)

.PHONY: all run clean