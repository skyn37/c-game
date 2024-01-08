#ifndef GAME_H
#define GAME_H

#include "raylib.h"
#define MAX_MAP_SIZE_X 20
#define MAX_MAP_SIZE_Y 20
#define MAX_ENEMIES 50
#define GAME_CAMERA_ZOOM 0.5

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
    float speed;
} Enemy;

typedef struct {
    Rectangle collisionBox;
    Vector2 position;
    float speed;
} Player;


void SpawnEntity(Enemy recArr[], int* count, Camera2D* camera);
void GameInitializePlayer(Player* Player, GridData* mapData);
void GameUpdateCamera(Camera2D* camera, Player* Player);
GridData GameGenerateMap(void);
#endif // GAME_H


