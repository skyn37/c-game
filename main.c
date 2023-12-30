#include <stdio.h>
#include "raylib.h"
#include "rlgl.h"

#include <stddef.h> // Required for: NULL
#include <math.h>   // Required for: sinf()

#include "game.h"
#include "controls.h"
#include "draw.h"
/// #include "assets/char/walk"
//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------

int main(void)
{
    const int WIDTH = 640;
    const int HEIGHT = 480;
    const char TITLE[] = "Test";
    int SPEEDx = 1;
    int SPEEDy = 1;
    InitWindow(WIDTH, HEIGHT, TITLE);

    Vector2 ballPosition;
    Rectangle rec;
    GameInitializeGame(&ballPosition, &rec);

    SetTargetFPS(30);
    while (!WindowShouldClose())
    {
        ControlsHandlePlayerControls(&ballPosition, &SPEEDx, &SPEEDy, &rec);
        DrawGame(ballPosition, rec);
    }

    CloseWindow();
}
