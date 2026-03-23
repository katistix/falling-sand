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
    Vector2 mousePosition = GetMousePosition();
    float deltaTime = GetFrameTime();
    updateTimer += deltaTime; // increase the elapsed time

    BeginDrawing();

    ClearBackground(BLACK);

    Vector2 gridCell = getGridCellFromMousePosition(mousePosition);

    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON) && isInside(gridCell)) {
      grid.data[(int)gridCell.y][(int)gridCell.x] = SAND;
    }
    if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON) && isInside(gridCell)) {
      grid.data[(int)gridCell.y][(int)gridCell.x] = AIR;
    }

    if (updateTimer >= UPDATE_RATE) {
      updateWorldGrid(&grid);
      updateTimer = 0.0f; // reset the timer
    }

    renderWorldGrid(&grid);

    if (isGUIOn)
      displayGUI();
    if (IsKeyPressed(KEY_TAB)) {
      isGUIOn = !isGUIOn;
    }

    
    EndDrawing();
  }

  CloseWindow();
}
