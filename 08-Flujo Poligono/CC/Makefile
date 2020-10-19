BIN = polig.exe
OBJ = poligcc.o poligccTest.o
CC = g++
RM = rm -f *.o

$(BIN): $(OBJ)
	$(CC) $(OBJ) -o $(BIN)

poligcc.o: poligcc.cpp poligcc.h
	$(CC) -c poligcc.cpp -o poligcc.o

poligccTest.o: poligccTest.cpp poligcc.h
	$(CC) -c poligccTest.cpp -o poligccTest.o

.PHONY: clean
clean:
	$(RM) $(OBJ) $(BIN)