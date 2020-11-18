BIN = polig.exe
OBJ = polig.o poligTest.o
CC = g++
RM = rm -f *.o
CFLAGS = -E -wall -l./includes - Wconversion -std::c++17
$(BIN): $(OBJ)
	$(CC) $(OBJ) -o $(BIN)

poligsc.o: polig.cpp polig.h
	$(CC) -c polig.cpp -o polig.o $(CFLAGS)


poligscTest.o: poligTest.cpp polig.h
	$(CC) -c poligTest.cpp -o poligTest.o $(CFLAGS)


.PHONY: clean
clean:
	$(RM) $(OBJ) $(BIN)