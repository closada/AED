BIN = polig.exe
OBJ = polig.o poligTest.o
CC = g++
RM = rm -f *.o
CFLAGS = -Wall -std=c++17 -pedantic -Wconversion

$(BIN): $(OBJ)
	$(CC) $(OBJ) -o $(BIN) $(CFLAGS) 

polig.o: polig.cpp polig.h
	$(CC) -c polig.cpp -o polig.o  $(CFLAGS)


poligTest.o: poligTest.cpp polig.h
	$(CC) -c poligTest.cpp -o poligTest.o $(CFLAGS)


.PHONY: clean
clean:
	$(RM) $(OBJ) $(BIN)
