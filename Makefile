#!/bin/sh

BIN	        = alien-attack
BIN_DIR     = ./bin
TARGET 			= $(BIN_DIR)/$(BIN)
TESTTARGET  = $(BIN_DIR)/test-$(BIN)
DATA_PREFIX = ./assets/

CC = g++
LIB = -L/usr/local/lib -Wl,-rpath=/usr/local/lib -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -lz -ltinyxml
INCLUDE = -isystem -I/usr/local/include
CCFLAGS = -Wall -c -g -std=c++17 -DDATA_PREFIX=\"$(DATA_PREFIX)\" \
	-Wno-reorder -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function  $(INCLUDE) 

SRCS	= $(wildcard src/**/*.cpp)
SRCS	+= $(wildcard src/*.cpp)
SRCS	+= ./main.cpp
OBJS 	= $(SRCS:.cpp=.o)

all: clean  $(TARGET)

clean:
	rm -f $(BIN_DIR)/* && rm -f $(shell find . -name "*.o")

run:
	$(TARGET)
	
test: test-target

.cpp.o: 
	$(CC) $(CCFLAGS) $< -o $@

$(TARGET) : $(OBJS)
	mkdir -p $(BIN_DIR)
	$(CC) $^ $(LIB) -o $@
	
memcheck:
	valgrind --log-file=valgrind.output --leak-check=yes --tool=memcheck $(TARGET)

TESTRCS  = $(wildcard specs/*.cpp)
TESTRCS  += $(wildcard src/*.cpp)
TESTOBJS  = $(TESTRCS:.cpp=.o)
	
test: test-target

run-test:
	$(TESTTARGET)

test-target: $(TESTOBJS)
	mkdir -p $(BIN_DIR)
	$(CC) $^ $(LIB) -o $(TESTTARGET)
