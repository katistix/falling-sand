# falling-sand

A tiny "falling sand" simulation **written in C** using [Raylib](https://www.raylib.com/). 

![katistix falling-sand screenshot](/assets/screenshot.png)

## how to run?
1. make sure you have [Raylib](https://www.raylib.com/) installed on your system
    - on macOS, you can install it using Homebrew: `brew install raylib`
2. clone this repository and navigate to the project directory
3. run `make` to compile the project
4. run `./main` to start the simulation

## goals of this project

- get familiar with Raylib and how to render a 2D game/application
- learn optimization algorithms and methods in order to make the simulation more permormant

## current features

- [x] hold `MOUSE_LEFT_BUTTON` to place `SAND`
- [x] hold `MOUSE_RIGHT_BUTTON` to replace particles with `AIR`