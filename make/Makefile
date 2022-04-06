G++ = g++
CFLAGS= -g -c -Wall
SRC=./../src
INC=./../inc
BIN=./../bin
LIB=./../lib
OBJ=./../obj
IFLAGS=-I$(INC)

all: $(BIN)/aius_prg

$(BIN)/aius_prg : $(OBJ)/main.o $(OBJ)/utility.o $(OBJ)/device.o
	$(G++) -o aius_prg $(OBJ)/main.o $(OBJ)/utility.o $(OBJ)/device.o
	mv aius_prg $(BIN)/

$(OBJ)/main.o : $(SRC)/main.cpp $(INC)/utility.h
	$(G++) $(CFLAGS) $(SRC)/main.cpp $(IFLAGS)
	mv main.o $(OBJ)/

$(OBJ)/utility.o : $(SRC)/utility.cpp $(INC)/utility.h
	$(G++) $(CFLAGS) $(SRC)/utility.cpp $(IFLAGS)
	mv utility.o $(OBJ)/

$(OBJ)/device.o : $(SRC)/device.cpp $(INC)/utility.h $(INC)/device.h
	$(G++) $(CFLAGS) $(SRC)/device.cpp $(IFLAGS)
	mv device.o $(OBJ)/

clean:
	rm -f $(OBJ)/*.o $(BIN)/aius_prg
