#include "engine.h"

#include <raylib.h>



void updateWorldGrid(WorldGrid *WorldGrid) {

  // update sand particles
  // go from bottom to top, left to right
  for (int i = GRID_HEIGHT - 1; i >= 0; i--) {
    for (int j = 0; j < GRID_WIDTH; j++) {
      if (WorldGrid->data[i][j] == SAND) {
        // try to move down
        if (i < GRID_HEIGHT - 1 && WorldGrid->data[i + 1][j] == AIR) {
          WorldGrid->data[i][j] = AIR;
          WorldGrid->data[i + 1][j] = SAND;
        }
        // try to move down-left
        else if (i < GRID_HEIGHT - 1 && j > 0 &&
                 WorldGrid->data[i + 1][j - 1] == AIR) {
          WorldGrid->data[i][j] = AIR;
          WorldGrid->data[i + 1][j - 1] = SAND;
        }
        // try to move down-right
        else if (i < GRID_HEIGHT - 1 && j < GRID_WIDTH - 1 &&
                 WorldGrid->data[i + 1][j + 1] == AIR) {
          WorldGrid->data[i][j] = AIR;
          WorldGrid->data[i + 1][j + 1] = SAND;
        }
      }
    }
  }
}

void renderWorldGrid(WorldGrid *worldGrid) {
  int leftOffset = 0;
  int topOffset = 0;

  for (int i = 0; i < GRID_HEIGHT; i++) {
    for (int j = 0; j < GRID_WIDTH; j++) {
      if (worldGrid->data[i][j] == SAND) {
        DrawRectangle(leftOffset + j * CELL_SIZE, topOffset + i * CELL_SIZE,
                      CELL_SIZE, CELL_SIZE, GetColor(0xE2CA76FF));
      } else {
        DrawRectangle(leftOffset + j * CELL_SIZE, topOffset + i * CELL_SIZE,
                      CELL_SIZE, CELL_SIZE, GetColor(0x6495EDFF));
      }
    }
  }
}