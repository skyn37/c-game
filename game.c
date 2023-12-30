#include "raylib.h"

void GameInitializeGame(Vector2* ballPosition, Rectangle* rec) {
    Vector2 position = (Vector2){0.0f, (float)GetScreenHeight() / 2 + 55.0f};
    Vector2 size =  (Vector2){(float)GetScreenWidth(), 20.0f};

    ballPosition->x = (float)GetScreenWidth() / 2;
    ballPosition->y = (float)GetScreenHeight() / 2;
   
    rec->x = position.x;
    rec->y = position.y;
    rec->height = size.y;
    rec->width = size.x;
}
