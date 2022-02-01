CC=g++
CFLAGS=-std=c++17 -Wall -g
BIN=hirsipuu

all: compile

compile: *.cpp
	$(CC) $(CFLAGS) $^ -o $(BIN)
