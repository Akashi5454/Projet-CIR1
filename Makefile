EXEC = tambouille

SRC_DIR = .
BUILD_DIR = ./build

CFLAGS = -Wall
LDFLAGS = -lm
CC = gcc

SRC = $(shell find $(SRC_DIR) -name '*.c')
OBJ = $(SRC:%=$(BUILD_DIR)/%.o)

MKDIR_P ?= @mkdir -p

all: web

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.c.o: %.c
	$(MKDIR_P) $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

web: tambouille ressources/02fotw.data
	@mkdir -p ./export
	@find ./export -name '*.html' -delete
	@echo "Les fichiers html ont été supprimé"

clean:
	rm -rf $(BUILD_DIR)
	rm -f $(EXEC)

rebuild: clean all

.PHONY: all clean rebuild web
