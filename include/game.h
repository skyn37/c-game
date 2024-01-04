// game.h
#ifndef GAME_H
#define GAME_H

#include "raylib.h"
#define MAX_MAP_SIZE_X 300
#define MAX_MAP_SIZE_Y 300
 
typedef struct {
    Vector2 position;
    int textureInfo; // Additional field for texture information
} GridCell;

typedef struct {
    GridCell* grid;
    int width;
    int height;
} GridData;

void GameInitializePlayer(Vector2* ballPosition, GridData* mapData);
GridData GameGenerateMap(void);
#endif // GAME_H
