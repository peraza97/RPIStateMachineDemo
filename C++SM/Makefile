CC = g++
CFLAGS = -std=c++11 
CPPFLAGS = -Iheaders 
SRC_DIR = src
OBJ_DIR = build
LDLIBS = -lwiringPi
PROJ_NAME = rasp
RM = rm 

SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

all: $(OBJ_DIR)/$(PROJ_NAME)

$(OBJ_DIR)/$(PROJ_NAME): $(OBJ_FILES)
	$(CC) $^ $(LDLIBS) -o $@  

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@ 

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR) 

clean: 
	$(RM) ./$(OBJ_DIR)/*

run: 
	./$(OBJ_DIR)/$(PROJ_NAME)