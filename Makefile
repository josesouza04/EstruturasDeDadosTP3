CC = g++
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/matrix.o $(OBJ)/segtree.o
HDRS = $(INC)/matrix.hpp $(INC)/segtree.hpp
CFLAGS = -Wall -g -c -I $(INC) -std=c++11

EXE = $(BIN)/tp3.out

.PHONY: all clean

run: all
	$(EXE)

all: $(EXE)

$(BIN)/tp3.out: $(OBJS)
	$(CC) -std=c++11 -g -o $(BIN)/tp3.out $(OBJS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/matrix.o: $(HDRS) $(SRC)/matrix.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/matrix.o $(SRC)/matrix.cpp

$(OBJ)/segtree.o: $(HDRS) $(SRC)/segtree.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/segtree.o $(SRC)/segtree.cpp

clean:
	rm -f $(EXE) $(OBJS) gmon.out