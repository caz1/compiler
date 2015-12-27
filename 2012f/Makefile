# I am a comment, and I want to say that the variable CC will be
# the compiler to use.
CC=g++
CFLAGS=-O2 -Wall -static -m32 #-Weffc++
SRC=./src
INC=./inc
BIN=./bin
INTERPRETER=interpreter
all:interpreter

interpreter:$(SRC)/interpreter.cpp $(INC)/defs.h
	$(CC) $(CFLAGS) $(SRC)/interpreter.cpp -I ./inc/ -o $(BIN)/$(INTERPRETER)

clean:
	rm -rf $(BIN)/$(INTERPRETER) 
