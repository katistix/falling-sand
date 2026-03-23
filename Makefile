all:
	gcc -o main main.c $(shell pkg-config --libs --cflags raylib)

clean:
	rm -rf main