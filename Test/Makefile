G++ = g++
CFLAGS= -g -c -Wall
OFLAGS = -o

BIN = bin/
INC = ./../inc
SRC = ../src/
OBJ = obj/

IFLAGS=-I$(INC)
LDLIBS = -lcppunit

all: $(BIN)aiu_test

$(BIN)aiu_test: $(OBJ)Test_main.o $(OBJ)DeviceTestFunctions.o $(OBJ)HeaderTestFunctions.o $(OBJ)utility.o $(OBJ)Device.o $(OBJ)Header.o
	$(G++) $(OFLAGS)aiu_test $(OBJ)utility.o $(OBJ)Device.o $(OBJ)Header.o $(OBJ)Test_main.o $(OBJ)DeviceTestFunctions.o $(OBJ)HeaderTestFunctions.o $(LDLIBS)
	mv aiu_test $(BIN)

$(OBJ)Test_main.o: Test_main.cpp $(INC)/utility.h $(INC)/Device.h DeviceTestFunctions.h
	$(G++) $(CFLAGS) Test_main.cpp $(IFLAGS) 
	mv Test_main.o $(OBJ)

$(OBJ)DeviceTestFunctions.o: DeviceTestFunctions.cpp $(INC)/utility.h $(INC)/Device.h
	$(G++) $(CFLAGS) DeviceTestFunctions.cpp $(IFLAGS)
	mv DeviceTestFunctions.o $(OBJ)
	
$(OBJ)HeaderTestFunctions.o: HeaderTestFunctions.cpp $(INC)/utility.h $(INC)/Header.h
	$(G++) $(CFLAGS) HeaderTestFunctions.cpp $(IFLAGS)
	mv HeaderTestFunctions.o $(OBJ)

$(OBJ)utility.o: $(SRC)utility.cpp $(INC)/utility.h
	$(G++) $(CFLAGS) $(SRC)utility.cpp $(IFLAGS)
	mv utility.o $(OBJ)
	
$(OBJ)Device.o: $(SRC)Device.cpp $(INC)/utility.h $(INC)/Device.h
	$(G++) $(CFLAGS) $(SRC)Device.cpp $(IFLAGS)
	mv Device.o $(OBJ)
	
$(OBJ)Header.o: $(SRC)Header.cpp $(INC)/utility.h $(INC)/Header.h
	$(G++) $(CFLAGS) $(SRC)Header.cpp $(IFLAGS)
	mv Header.o $(OBJ)

clean:
	rm -f $(BIN)aiu_test
	rm -f $(OBJ)*.o
