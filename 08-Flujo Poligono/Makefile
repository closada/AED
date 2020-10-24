BIN = polig.exe
OBJ = polig.o poligTest.o
CC = g++
RM = rm -f *.o

$(BIN): $(OBJ)
	$(CC) $(OBJ) -o $(BIN)

poligsc.o: polig.cpp polig.h
	$(CC) -c polig.cpp -o polig.o

poligscTest.o: poligTest.cpp polig.h
	$(CC) -c poligTest.cpp -o poligTest.o

.PHONY: clean
clean:
	$(RM) $(OBJ) $(BIN)