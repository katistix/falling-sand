#include "gui.h"

#include "config/config.h"
#include <raylib.h>


void displayGUI(){
    const int outerMargin = 15;
    const int innerPadding = 5;
    const int boxHeight = 50;
    const int boxWidth = 150;

    int boxTop = SCREEN_HEIGHT - outerMargin - boxHeight;
    int boxLeft = outerMargin;

    DrawRectangle(boxLeft, boxTop, boxWidth, boxHeight, GetColor(0x111111DD));

    Vector2 mousePosition = GetMousePosition();

    DrawText(TextFormat("mouse_xy: [%d, %d]", (int)mousePosition.x, (int)mousePosition.y),
        boxLeft + innerPadding,
        boxTop + innerPadding,
        12,
        RAYWHITE
    );
}