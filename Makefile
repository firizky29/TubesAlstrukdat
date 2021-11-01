CC = gcc

# FLAGS
CFLAG = -Wall -std=c99
BUILD_FLAG = -lm
TARGET = Mobilita
INC = -Isrc/lib -Itest

# DIREKTORI
OBJ_SRC_DIR = ./obj/src
BIN_SRC_DIR = ./bin/src
TARGET_DIR = ./bin/$(TARGET)

SRCS := $(shell find -name "*.c")
OBJS := $(patsubst %.c,obj/%.o,$(SRCS))
DRIVER_SRC := $(shell find src -name "*.c"  ! -name "driver_*" ! -name "main.c")
DRIVER_OBJ := $(patsubst %.c,obj/%.o,$(DRIVER_SRC))


$(OBJ_SRC_DIR)%.o: ./src/%.c ./src/%.h
	@mkdir -p $(dir $@)
	@$(CC) -g $(CFLAG) -c $(INC) $< -o $@

$(OBJ_SRC_DIR)%.o: ./src/%.c
	@mkdir -p $(dir $@)
	@$(CC) -g $(CFLAG) -c $(INC) $< -o $@

all: clear build run

clear:
	@rm -rf obj/* bin/*

$(BIN_SRC_DIR): $(DRIVER_OBJ)
	@mkdir -p bin
	@$(CC) -g $^ -o $@ $(BUILD_FLAG) $(TEST_FLAG)

$(TARGET_DIR): $(DRIVER_OBJ) $(OBJ_SRC_DIR)/main.o
	@mkdir -p bin
	@$(CC) $^ -o $@ $(BUILD_FLAG) -O3

build: $(TARGET_DIR)

run: build
	@$(TARGET_DIR)

clean: clear

.PHONY: clear all build run clean debug
