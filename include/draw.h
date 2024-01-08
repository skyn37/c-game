#ifndef DRAW_H
#define DRAW_H

#include "raylib.h"
#include <game.h>
void DrawGame(Player ballPosition, GridData mapData, Texture2D Ground, Enemy recArr[], Camera2D camera);
Camera2D InitCamera(Vector2* Player);
#endif // DRAW_H
