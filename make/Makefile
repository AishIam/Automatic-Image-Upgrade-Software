G++ = g++
CFLAGS= -g -c -Wall
SRC=./../src
INC=./../inc
BIN=./../bin
LIB=./../lib
OBJ=./../obj
LOGS = ../logs
IFLAGS=-I$(INC)

LOGFILE = $(LOGS)/aiu_execution.log

all: $(BIN)/aius_prg

$(BIN)/aius_prg : $(OBJ)/main.o $(OBJ)/Device.o $(OBJ)/Header.o $(OBJ)/Updater.o $(OBJ)/utility.o
	$(G++) -o aius_prg $(OBJ)/main.o $(OBJ)/Device.o $(OBJ)/Header.o $(OBJ)/Updater.o
	mv aius_prg $(BIN)/

$(OBJ)/main.o : $(SRC)/main.cpp $(INC)/utility.h
	$(G++) $(CFLAGS) $(SRC)/main.cpp $(IFLAGS)
	mv main.o $(OBJ)/
	
$(OBJ)/Updater.o : $(SRC)/Updater.cpp $(INC)/utility.h $(INC)/Updater.h $(OBJ)/Device.o $(OBJ)/Header.o
	$(G++) $(CFLAGS) $(SRC)/Updater.cpp $(IFLAGS)
	mv Updater.o $(OBJ)/

$(OBJ)/Device.o : $(SRC)/Device.cpp $(INC)/utility.h $(INC)/Device.h
	$(G++) $(CFLAGS) $(SRC)/Device.cpp $(IFLAGS)
	mv Device.o $(OBJ)/
	
$(OBJ)/Header.o : $(SRC)/Header.cpp $(INC)/utility.h $(INC)/Header.h
	$(G++) $(CFLAGS) $(SRC)/Header.cpp $(IFLAGS)
	mv Header.o $(OBJ)/


$(OBJ)/utility.o : $(SRC)/utility.cpp $(INC)/utility.h
	$(G++) $(CFLAGS) $(SRC)/utility.cpp $(IFLAGS)
	mv utility.o $(OBJ)/

clean:
	rm -f $(OBJ)/*.o $(BIN)/aius_prg
