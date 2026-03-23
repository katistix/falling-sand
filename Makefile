all:
	gcc -I. -o main main.c $(shell pkg-config --libs --cflags raylib) \
		engine/engine.c drawing/drawing.c gui/gui.c 

clean:
	rm -rf main