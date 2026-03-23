#ifndef DRAWING_H
#define DRAWING_H


#include <raylib.h>


Vector2 getGridCellFromMousePosition(Vector2 mousePosition);

// check if the grid position is valid (not out of bounds)
int isInside(Vector2 gridPosition);

#endif