BIN = col.exe
OBJ = color.o colorTest.o
CC = g++
RM = rm -f *.o

$(BIN): $(OBJ)
	$(CC) $(OBJ) -o $(BIN)

color.o: color.cpp color.h
	$(CC) -c color.cpp -o color.o

colorTest.o: colorTest.cpp color.h
	$(CC) -c colorTest.cpp -o colorTest.o

.PHONY: clean
clean:
	$(RM) $(OBJ) $(BIN)