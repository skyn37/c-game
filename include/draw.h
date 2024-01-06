#ifndef DRAW_H
#define DRAW_H

#include "raylib.h"
#include <game.h>
void DrawGame(Vector2 ballPosition, GridData mapData, Texture2D Ground, Enemy recArr[]);
Camera2D InitCamera(Vector2* Player);
#endif // DRAW_H
