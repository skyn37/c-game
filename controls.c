#include "raylib.h"
#include <stdio.h>


int SPEEDx = 100;
int SPEEDy = 100;


void HandlePlayerControls(Vector2* Player)
{
    if (IsKeyDown(KEY_RIGHT)) Player->x += 100.0f * GetFrameTime() * SPEEDx;
    if (IsKeyDown(KEY_LEFT)) Player->x -= 100.0f * GetFrameTime() * SPEEDx;
    if (IsKeyDown(KEY_UP)) Player->y -= 100.0f * GetFrameTime() * SPEEDy;
    if (IsKeyDown(KEY_DOWN)) Player->y += 100.0f * GetFrameTime() * SPEEDy;
}

void ControlsInitControls(Vector2* Player)
{
    HandlePlayerControls(Player);
}
