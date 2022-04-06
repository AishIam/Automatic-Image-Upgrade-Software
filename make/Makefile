G++ = g++
CFLAGS= -g -c -Wall
SRC=./../src
INC=./../inc
BIN=./../bin
LIB=./../lib
OBJ=./../obj
IFLAGS=-I$(INC)

all: $(BIN)/aius_prg

$(BIN)/aius_prg : $(OBJ)/main.o $(OBJ)/device.o $(OBJ)/Header.o
	$(G++) -o aius_prg $(OBJ)/main.o $(OBJ)/device.o $(OBJ)/Header.o
	mv aius_prg $(BIN)/

$(OBJ)/main.o : $(SRC)/main.cpp $(INC)/utility.h
	$(G++) $(CFLAGS) $(SRC)/main.cpp $(IFLAGS)
	mv main.o $(OBJ)/

$(OBJ)/device.o : $(SRC)/device.cpp $(INC)/utility.h $(INC)/device.h
	$(G++) $(CFLAGS) $(SRC)/device.cpp $(IFLAGS)
	mv device.o $(OBJ)/
	
$(OBJ)/Header.o : $(SRC)/Header.cpp $(INC)/utility.h $(INC)/Header.h
	$(G++) $(CFLAGS) $(SRC)/Header.cpp $(IFLAGS)
	mv Header.o $(OBJ)/

clean:
	rm -f $(OBJ)/*.o $(BIN)/aius_prg
