#include "drawing.h"

#include "config/config.h"

Vector2 getGridCellFromMousePosition(Vector2 mousePosition) {
  int leftOffset = 0;
  int topOffset = 0;

  Vector2 cell = {0};
  cell.x = (int)((mousePosition.x - leftOffset) / CELL_SIZE);
  cell.y = (int)((mousePosition.y - topOffset) / CELL_SIZE);

  if (cell.x < 0 || cell.x >= GRID_WIDTH || cell.y < 0 ||
      cell.y >= GRID_HEIGHT) {
    cell.x = -1;
    cell.y = -1;
  }

  return cell;
}



// check if the grid position is valid (not out of bounds)
int isInside(Vector2 gridPosition) {
  if (gridPosition.x >= 0 && gridPosition.y >= 0)
    return 1;

  return 0;
}
