BIN = polig.exe
OBJ = poligsc.o poligscTest.o
CC = g++
RM = rm -f *.o

$(BIN): $(OBJ)
	$(CC) $(OBJ) -o $(BIN)

poligsc.o: poligsc.cpp poligsc.h
	$(CC) -c poligsc.cpp -o poligsc.o

poligscTest.o: poligscTest.cpp poligsc.h
	$(CC) -c poligscTest.cpp -o poligscTest.o

.PHONY: clean
clean:
	$(RM) $(OBJ) $(BIN)