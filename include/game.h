#ifndef GAME_H
#define GAME_H

#include "raylib.h"
#define MAX_MAP_SIZE_X 20
#define MAX_MAP_SIZE_Y 20
#define MAX_ENEMIES 50


typedef struct {
    Vector2 position;
    int textureInfo; // Additional field for texture information
} GridCell;

typedef struct {
    GridCell* grid;
    int width;
    int height;
} GridData;

typedef struct {
    Rectangle collisionBox;
    Vector2 position;
} Enemy;

typedef struct {
    Rectangle collisionBox;
    Vector2 position;
} Player;


void SpawnEntity(Enemy recArr[], int* count, Vector2* ballPosition);
void GameInitializePlayer(Vector2* ballPosition, GridData* mapData);
GridData GameGenerateMap(void);
#endif // GAME_H


