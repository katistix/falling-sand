#include <stdio.h>
#include <raylib.h>
#include <stdlib.h>


#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define CELL_SIZE 4
#define STATUSBAR_HEIGHT 25
#define GRID_WIDTH SCREEN_WIDTH/CELL_SIZE
#define GRID_HEIGHT (SCREEN_HEIGHT-STATUSBAR_HEIGHT)/CELL_SIZE

#define UPDATE_RATE 0.02f

typedef enum {
    AIR,
    SAND
} Element;

typedef struct
{
    Element data[GRID_HEIGHT][GRID_WIDTH];
} WorldGrid;


void renderWorldGrid(WorldGrid *worldGrid){
    int leftOffset = 0;
    int topOffset = 0;


    for (int i = 0; i < GRID_HEIGHT; i++)
    {
        for (int j = 0; j < GRID_WIDTH; j++)
        {
            if (worldGrid->data[i][j] == SAND)
            {
                DrawRectangle(leftOffset+j*CELL_SIZE, topOffset+i*CELL_SIZE, CELL_SIZE, CELL_SIZE, GetColor(0xE2CA76FF));
            }
            else {
                DrawRectangle(leftOffset+j*CELL_SIZE, topOffset+i*CELL_SIZE, CELL_SIZE, CELL_SIZE, GetColor(0x6495EDFF));
            }
        }
    }
}


void updateWorldGrid(WorldGrid *WorldGrid){

    // update sand particles
    // go from bottom to top, left to right
    for (int i = GRID_HEIGHT-1; i >= 0; i--){
        for (int j = 0; j < GRID_WIDTH; j++){
            if (WorldGrid->data[i][j] == SAND)
            {
                // try to move down
                if (i < GRID_HEIGHT-1 && WorldGrid->data[i+1][j] == AIR)
                {
                    WorldGrid->data[i][j] = AIR;
                    WorldGrid->data[i+1][j] = SAND;
                }
                // try to move down-left
                else if (i < GRID_HEIGHT-1 && j > 0 && WorldGrid->data[i+1][j-1] == AIR)
                {
                    WorldGrid->data[i][j] = AIR;
                    WorldGrid->data[i+1][j-1] = SAND;
                }
                // try to move down-right
                else if (i < GRID_HEIGHT-1 && j < GRID_WIDTH-1 && WorldGrid->data[i+1][j+1] == AIR)
                {
                    WorldGrid->data[i][j] = AIR;
                    WorldGrid->data[i+1][j+1] = SAND;
                }
            }
        }
    }

}

Vector2 getGridCellFromMousePosition(Vector2 mousePosition){
    int leftOffset = 0;
    int topOffset = 0;

    Vector2 cell = {0};
    cell.x = (int)((mousePosition.x - leftOffset) / CELL_SIZE);
    cell.y = (int)((mousePosition.y - topOffset) / CELL_SIZE);

    if (cell.x < 0 || cell.x >= GRID_WIDTH || cell.y < 0 || cell.y >= GRID_HEIGHT)
    {
        cell.x = -1;
        cell.y = -1;
    }

    return cell;
}

// check if the grid position is valid (not out of bounds)
int isInside(Vector2 gridPosition){
    if (gridPosition.x >= 0 && gridPosition.y >= 0) return 1;

    return 0;
}




int main(){
    WorldGrid grid = {0};

    float updateTimer = 0.0f;


    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Falling Sand");
    while (!WindowShouldClose())
    {
        Vector2 mousePosition = GetMousePosition();
        float deltaTime = GetFrameTime();
        updateTimer += deltaTime; // increase the elapsed time

        BeginDrawing();

        ClearBackground(BLACK);


        Vector2 gridCell = getGridCellFromMousePosition(mousePosition);

        if(IsMouseButtonDown(MOUSE_LEFT_BUTTON) && isInside(gridCell)) {
            grid.data[(int)gridCell.y][(int)gridCell.x] = SAND;
        }
        if(IsMouseButtonDown(MOUSE_RIGHT_BUTTON) && isInside(gridCell)) {
            grid.data[(int)gridCell.y][(int)gridCell.x] = AIR;
        }

        if (updateTimer >= UPDATE_RATE){
            updateWorldGrid(&grid);
            updateTimer=0.0f; // reset the timer
        }
        
        
        
        renderWorldGrid(&grid);


        // draw GUI
        const char* statusText = TextFormat("particles: %d, grid_xy: [%d, %d], mouse_xy: [%d, %d]",
            0, 
            (int)gridCell.x, (int)gridCell.y,
            (int)mousePosition.x, (int)mousePosition.y
        );
        DrawText(statusText, 8, SCREEN_HEIGHT - 14 - 8, 14, RAYWHITE);


        EndDrawing();
    }
    

    CloseWindow();
}