#ifndef ENGINE_H
#define ENGINE_H

#include "config/config.h"


typedef enum { AIR, SAND } Element;
typedef struct {
  Element data[GRID_HEIGHT][GRID_WIDTH];
} WorldGrid;

void updateWorldGrid(WorldGrid *WorldGrid);
void renderWorldGrid(WorldGrid *worldGrid);

#endif