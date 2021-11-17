CC = gcc

BUILD_DIR := ./build
BIN_DIR := ./bin
SRC_DIR := ./src
TARGET := $(BIN_DIR)/MobitaGame

CFLAG = -Wall -std=c99
BUILD_FLAG = -lm

SRCS := $(shell find src -name *.c ! -name "main.c")
OBJS := $(patsubst %.c,$(BUILD_DIR)/%.o,$(SRCS))


INC_DIR := $(wildcard src/*/**/**)
INC_FLAG := $(addprefix -I,$(INC_DIR)) -Isrc/lib


$(BUILD_DIR)/src/%.o $(BUILD_DIR)/%.o: ./src/%.c
	@mkdir -p $(dir $@)
	@$(CC) -g $(CFLAG) $(INC_FLAG) -c $< -o $@

$(TARGET): $(OBJS) $(BUILD_DIR)/main.o
	@mkdir -p bin
	@$(CC) $(INC_FLAG) $^ -o $@ -O3

build: $(OBJS) $(BUILD_DIR)/main.o
	@mkdir -p bin
	@$(CC) -g $(INC_FLAG) $^ -o $(TARGET)

run: build
	@$(TARGET)

clear:
	@rm -rf build/* bin/*

all : clear build

.PHONY : clear all build run


