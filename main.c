#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

#include "config/config.h"
#include "gui/gui.h"
#include "engine/engine.h"
#include "drawing/drawing.h"

int main() {
  WorldGrid grid = {0};

  float updateTimer = 0.0f;
  int isGUIOn = 0;

  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Falling Sand");
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);



    handleDrawingWithMouse(&grid);
    
    // Handle the update timer
    float deltaTime = GetFrameTime();
    updateTimer += deltaTime; // increase the elapsed time
    if (updateTimer >= UPDATE_RATE) {
      updateWorldGrid(&grid);
      updateTimer = 0.0f; // reset the timer
    }
    

    // Render the world
    renderWorldGrid(&grid);

    // render the GUI if it's on
    if (isGUIOn)
      displayGUI();
    if (IsKeyPressed(KEY_TAB)) {
      isGUIOn = !isGUIOn;
    }



    
    EndDrawing();
  }

  CloseWindow();
}
