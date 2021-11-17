CC = gcc

BUILD_DIR := ./build
BIN_DIR := ./bin
SRC_DIR := ./src
TEST_DIR := ./test
TARGET := $(BIN_DIR)/MobitaGame

CFLAG = -Wall -std=c99
BUILD_FLAG = -lm

SRCS := $(shell find src -name *.c ! -name "main.c" ! -name "driver_*.c")
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
	@rm -rf build/* bin/* test/*

all : clear build

.PHONY : clear all build run

# ADT RUNNER
machine: $(SRCS) ./src/lib/tools/mesin-kata/driver_machine.c
	@mkdir -p test
	@$(CC) -g $(CFLAG) $(INC_FLAG) $^ -o $(TEST_DIR)/machine

pcolor: $(SRCS) ./src/lib/tools/pcolor/driver_pcolor.c
	@mkdir -p test
	@$(CC) -g $(CFLAG) $(INC_FLAG) $^ -o $(TEST_DIR)/pcolor

stack: $(SRCS) ./src/lib/data-structure/stack/driver_stack.c
	@mkdir -p test
	@$(CC) -g $(CFLAG) $(INC_FLAG) $^ -o $(TEST_DIR)/stack

queue: $(SRCS) ./src/lib/data-structure/queue/driver_queue.c
	@mkdir -p test
	@$(CC) -g $(CFLAG) $(INC_FLAG) $^ -o $(TEST_DIR)/queue

point: $(SRCS) ./src/lib/data-structure/point/driver_point.c
	@mkdir -p test
	@$(CC) -g $(CFLAG) $(INC_FLAG) $^ -o $(TEST_DIR)/point

pesanan: $(SRCS) ./src/lib/data-structure/pesanan/driver_pesanan.c
	@mkdir -p test
	@$(CC) -g $(CFLAG) $(INC_FLAG) $^ -o $(TEST_DIR)/pesanan

matrix: $(SRCS) ./src/lib/data-structure/matriks/driver_matrix.c
	@mkdir -p test
	@$(CC) -g $(CFLAG) $(INC_FLAG) $^ -o $(TEST_DIR)/matriks

liststat: $(SRCS) ./src/lib/data-structure/list-statis/driver_liststat.c
	@mkdir -p test
	@$(CC) -g $(CFLAG) $(INC_FLAG) $^ -o $(TEST_DIR)/liststat

listlinked: $(SRCS) ./src/lib/data-structure/list-linked/driver_list_linked.c
	@mkdir -p test
	@$(CC) -g $(CFLAG) $(INC_FLAG) $^ -o $(TEST_DIR)/listlinked

listdin: $(SRCS) ./src/lib/data-structure/list-dinamis/driver_listdin.c
	@mkdir -p test
	@$(CC) -g $(CFLAG) $(INC_FLAG) $^ -o $(TEST_DIR)/listdin

peta: $(SRCS) ./src/lib/scene/peta/driver_peta.c
	@mkdir -p test
	@$(CC) -g $(CFLAG) $(INC_FLAG) $^ -o $(TEST_DIR)/peta

ADT_BUILDER: machine listlinked listdin liststat pesanan peta matrix point pcolor queue stack
