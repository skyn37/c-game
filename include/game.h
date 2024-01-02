// game.h
#ifndef GAME_H
#define GAME_H

#include "raylib.h"
#define MAX_MAP_SIZE_X 1000
#define MAX_MAP_SIZE_Y 1000


typedef struct {
    int grid[MAX_MAP_SIZE_X][MAX_MAP_SIZE_Y];
    int width;
    int height;
} GridData;

void GameInitializePlayer(Vector2* ballPosition, GridData* mapData);
GridData GameGenerateMap(void);
#endif // GAME_H
