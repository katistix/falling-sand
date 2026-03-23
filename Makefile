all:
	gcc -I. -o main main.c $(shell pkg-config --libs --cflags raylib) gui/gui.c

clean:
	rm -rf main