CC=gcc
CFLAGS=-Wall
SRC=src/main.c src/books.c
OUT=library

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT)
