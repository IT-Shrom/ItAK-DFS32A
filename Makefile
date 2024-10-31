
CC = gcc
CFLAGS = -Wall -Wextra -std=c11
SRC_DIR = src
OUT_DIR = out
BIN_DIR = bin
MODEL_DIR = $(SRC_DIR)/models
VIEW_DIR = $(SRC_DIR)/views
CONTROLLER_DIR = $(SRC_DIR)/controllers

EXEC = $(BIN_DIR)/jeu
SRC_FILES = $(SRC_DIR)/main.c \
            $(MODEL_DIR)/model.c \
            $(VIEW_DIR)/view.c \
            $(CONTROLLER_DIR)/controller.c
OBJ_FILES = $(OUT_DIR)/main.o \
            $(OUT_DIR)/model.o \
            $(OUT_DIR)/view.o \
            $(OUT_DIR)/controller.o
all: $(EXEC)
$(EXEC): $(OBJ_FILES) | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $(OBJ_FILES)
$(OUT_DIR)/main.o: $(SRC_DIR)/main.c $(MODEL_DIR)/model.h $(CONTROLLER_DIR)/controller.h
	$(CC) $(CFLAGS) -c $< -o $@
$(OUT_DIR)/model.o: $(MODEL_DIR)/model.c $(MODEL_DIR)/model.h
	$(CC) $(CFLAGS) -c $< -o $@
$(OUT_DIR)/view.o: $(VIEW_DIR)/view.c $(VIEW_DIR)/view.h $(MODEL_DIR)/model.h
	$(CC) $(CFLAGS) -c $< -o $@
$(OUT_DIR)/controller.o: $(CONTROLLER_DIR)/controller.c $(CONTROLLER_DIR)/controller.h $(MODEL_DIR)/model.h $(VIEW_DIR)/view.h
	$(CC) $(CFLAGS) -c $< -o $@
$(BIN_DIR) $(OUT_DIR):
	mkdir -p $@
clean:
	rm -f $(OBJ_FILES) $(EXEC)
	rm -rf $(OUT_DIR)/* $(BIN_DIR)/*
.PHONY: all clean