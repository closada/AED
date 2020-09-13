BIN = pun.exe
OBJ = Punto.o PuntoTest.o
CC = g++
RM = rm -f *.o

$(BIN): $(OBJ)
	$(CC) $(OBJ) -o $(BIN)

color.o: Punto.cpp Punto.h
	$(CC) -c Punto.cpp -o Punto.o

colorTest.o: PuntoTest.cpp Punto.h
	$(CC) -c PuntoTest.cpp -o PuntoTest.o

.PHONY: clean
clean:
	$(RM) $(OBJ) $(BIN)