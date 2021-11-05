# CC = gcc

# # FLAGS
# CFLAG = -Wall -std=c99
# BUILD_FLAG = -lm
# TARGET = Mobilita
# INC = -Isrc/lib

# # DIREKTORI
# OBJ_SRC_DIR = ./obj/src
# BIN_SRC_DIR = ./bin/src
# TARGET_DIR = ./bin/$(TARGET)

# SRCS := $(shell find -name "*.c")
# OBJS := $(patsubst %.c,obj/%.o,$(SRCS))
# DRIVER_SRC := $(shell find src -name "*.c"  ! -name "driver_*")
# # test:
# # 	@echo $(DRIVER_SRC)
# DRIVER_OBJ := $(patsubst %.c,obj/%.o,$(DRIVER_SRC))


# $(OBJ_SRC_DIR)%.o: ./src/%.c ./src/%.h
# 	@mkdir -p $(dir $@)
# 	@$(CC) -g $(CFLAG) -c $(INC) $< -o $@

# $(OBJ_SRC_DIR)%.o: ./src/%.c
# 	@mkdir -p $(dir $@)
# 	@$(CC) -g $(CFLAG) -c $(INC) $< -o $@

# all: clear build run

# clear:
# 	@rm -rf obj/* bin/*

# $(BIN_SRC_DIR): $(DRIVER_OBJ)
# 	@mkdir -p bin
# 	@$(CC) -g $^ -o $@ $(BUILD_FLAG) $(TEST_FLAG)

# $(TARGET_DIR): $(DRIVER_OBJ) $(OBJ_SRC_DIR)/main.o
# 	@mkdir -p bin
# 	@$(CC) $^ -o $@ $(BUILD_FLAG) -O3

# build: $(TARGET_DIR)

# run: build
# 	@$(TARGET_DIR)

# clean: clear

# .PHONY: clear all build run clean debug vscode
CC = gcc
PROJECT_MANAGER = project
PRJOCET_BIN = listpost

# FLAGS
BUILD_FLAG = -lm
CFLAG = -Wall -std=c99 -Isrc/lib
TEST_FLAG = -lcheck -lcheck -lm -lpthread -lrt -lsubunit -std=c99 -lsubunit -lgcov -coverage

BUILD_SRC = ./build/src
BUILD_TEST = ./build/test

BIN_SRC = $(shell find src -name "*.c")
BIN_OBJ = $(patsubst %.c,build/%.o,$(BIN_SRC))

NMAIN_SRC = $(shell find src -name "*.c"  ! -name "main_*" ! -name "main.c")
NMAIN_OBJ = $(patsubst %.c,build/%.o,$(NMAIN_SRC))

# TESTING CONFIGURATION
TESTING_FILE = $(shell find test -name "*.c")
TESTING_OBJ = $(patsubst %.c,build/%.o,$(TESTING_FILE))

# SOURCE CODE TO OBJECT FILE
./build/src/%.o: ./src/%.c ./src/%.h
	@mkdir -p $(dir $@)
	@$(CC) -g $(CFLAG) -c $< -o $@

./build/src/%.o: ./src/%.c
	@mkdir -p $(dir $@)
	@$(CC) -g $(CFLAG) -c $< -o $@

./build/test/%.o: ./test/%.c
	@mkdir -p $(dir $@)
	@$(CC) -g $(CFLAG) -fprofile-arcs -ftest-coverage -c $< -o $@

all: clear build

clear:
	@rm -rf build/* bin/*

./bin/test: ${TESTING_OBJ} $(NMAIN_OBJ)
	@mkdir -p bin
	@$(CC) -g $^ -o $@ $(BUILD_FLAG) $(TEST_FLAG)

./bin/mobilita: $(NMAIN_OBJ) $(BUILD_SRC)/main.o
	@mkdir -p bin
	@$(CC) $^ -o $@ $(BUILD_FLAG) -O3

build: ./bin/mobilita

build_debug: $(NMAIN_OBJ) $(BUILD_SRC)/main.o
	@mkdir -p bin
	@$(CC) -g $^ -o ./bin/mobilita $(BUILD_FLAG)

run: build_debug
	@./bin/mobilita

debug: build_debug

test_debug: clean ./bin/test
	@./bin/test -tno-fork

test: clean ./bin/test
	@./bin/test

main_builder/%: % $(NMAIN_OBJ)
	@$(CC) -g $^ -o ./bin/ADT_RUNNER $(BUILD_FLAG)

clean: clear

.PHONY: test clear all adt tc clean vscode build run
