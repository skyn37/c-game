#include "raylib.h"


void DrawGame(Vector2 ballPosition,Rectangle rec)
{
    BeginDrawing();

    ClearBackground(GRAY);

    DrawText("move the ball with arrow keys", 10, 10, 20, DARKGRAY);
    DrawRectangle(rec.x, rec.y, rec.width, rec.height, BLACK);
    DrawCircleV(ballPosition, 50, MAROON);

    EndDrawing();
}
