BIN = polig.exe
OBJ = Poligono.o PoligonoTest.o
CC = g++
RM = rm -f *.o

$(BIN): $(OBJ)
	$(CC) $(OBJ) -o $(BIN)

Poligono.o: Poligono.cpp Poligono.h
	$(CC) -c Poligono.cpp -o Poligono.o

PoligonoTest.o: PoligonoTest.cpp Poligono.h
	$(CC) -c PoligonoTest.cpp -o PoligonoTest.o

.PHONY: clean
clean:
	$(RM) $(OBJ) $(BIN)
