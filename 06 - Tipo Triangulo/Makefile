BIN = triang.exe
OBJ = Triangulo.o TrianguloTest.o
CC = g++
RM = rm -f *.o

$(BIN): $(OBJ)
	$(CC) $(OBJ) -o $(BIN)

color.o: Triangulo.cpp Triangulo.h
	$(CC) -c Triangulo.cpp -o Triangulo.o

colorTest.o: TrianguloTest.cpp Triangulo.h
	$(CC) -c TrianguloTest.cpp -o TrianguloTest.o

.PHONY: clean
clean:
	$(RM) $(OBJ) $(BIN)