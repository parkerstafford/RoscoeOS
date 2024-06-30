CC = gcc
CFLAGS = -Iinclude

all: my_c_project

my_c_project: src/main.o
	$(CC) -o my_c_project src/main.o

src/main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c -o src/main.o

clean:
	rm -f src/*.o my_c_project
