all:
	gcc -I. -o main main.c $(shell pkg-config --libs --cflags raylib) \
		drawing/drawing.c gui/gui.c engine/engine.c

clean:
	rm -rf main