#include "raylib.h"
#include <stdio.h>
void ControlsHandlePlayerControls(Vector2* ballPosition,int* SPEEDx, int* SPEEDy, Rectangle* rec)
{
    if (IsKeyDown(KEY_RIGHT)) ballPosition->x += 100.0f * GetFrameTime() * (*SPEEDx);
    if (IsKeyDown(KEY_LEFT)) ballPosition->x -= 100.0f * GetFrameTime() * (*SPEEDx);
    if (IsKeyDown(KEY_UP)) ballPosition->y -= 100.0f * GetFrameTime() ;
    if (IsKeyDown(KEY_DOWN)) ballPosition->y += 100.0f * GetFrameTime() * (*SPEEDy);


    if(ballPosition->x > GetScreenWidth() + 25) {
        ballPosition->x = GetScreenWidth() + 25;
    }
    if(ballPosition->x < 0  ) {
        ballPosition->x = 0 ;
    }

    // printf("%f\n", ballPosition.y);
    // printf("%f\n" ,recPosition.y);
    if(ballPosition->y > rec->y) {
        *SPEEDy = 0;
        *SPEEDx = 5;
    }
    else
    {
        *SPEEDx = 1;
        *SPEEDy = 1;
    }

    if (CheckCollisionCircleRec(*ballPosition, 50, *rec))
    {
    }
    else
    {
    }
}
