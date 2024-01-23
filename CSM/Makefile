CC = gcc
CFLAGS = -I ./headers
SRC_DIR = src
OBJ_DIR = build
LDLIBS = -lgpiod
PROJ_NAME = rasp
RM = rm

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

all: $(OBJ_DIR)/$(PROJ_NAME)

$(OBJ_DIR)/$(PROJ_NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ $(LDLIBS) -o $@  

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ 

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR) 

.PHONY: clean
clean: 
	$(RM) ./$(OBJ_DIR)/*

.PHONY: run
run: 
	./$(OBJ_DIR)/$(PROJ_NAME)

.PHONY: srun
srun: 
	sudo ./$(OBJ_DIR)/$(PROJ_NAME)
