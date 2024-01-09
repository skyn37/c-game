#include "raylib.h"
#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "raymath.h"
#include <string.h>
#include "draw.h"




void GameInitializePlayer(Player* Player, GridData* mapData) {
    Vector2 position = {0.0f, 0.0f};

    for (int i = 0; i < mapData->width; i++) {
        for (int j = 0; j < mapData->height; j++) {
            if (mapData->grid[i + j * mapData->width].textureInfo == 1) {
                // Found a valid position in the map
                position = mapData->grid[i + j * mapData->width].position;
                break;
            }
        }

        if (position.x != 0.0f || position.y != 0.0f) {
            // A valid position has been found, exit the outer loop
            break;
        }
    }

    // TODO this is the ground texture h and w should handle that better
    Player->position.x= position.x * 600.0 + 600.0 / 2.0f;
    Player->position.y= position.y * 600.0 + 600.0 / 2.0f;
    Player->collisionBox.x = Player->position.x;

    Player->collisionBox.y = Player->position.y;
    Player->collisionBox.width = 50 ;
    Player->collisionBox.height = 50 ;
    Player->speed = 10.0;
    Player->direction = (Vector2){0.0f, 0.0f};
}

GridData GameGenerateMap() {
    Vector2 mapSize = (Vector2){MAX_MAP_SIZE_X, MAX_MAP_SIZE_Y};
    int numberOfSteps = 10; // TODO this is the numbers of steps the drun algo takes should handle that better

    Vector2 allowedMovements[] = {
        {-1, 0},  // left
        {0, -1},  // up
        {1, 0},   // right
        {0, 1}    // down
    };

    GridData result;
    result.width = mapSize.x;
    result.height = mapSize.y;

    result.grid = (GridCell*)malloc(result.width * result.height * sizeof(GridCell));

    // Initialize positions and textureInfo
    for (int i = 0; i < result.width; i++) {
        for (int j = 0; j < result.height; j++) {
            result.grid[i + j * result.width].position.x = i;
            result.grid[i + j * result.width].position.y = j;
            result.grid[i + j * result.width].textureInfo = 0; // TODO valid texture is 1 no texture is 0 .. should handle this better
        }
    }

    // Set the initial position
    Vector2 initialPosition = (Vector2){GetRandomValue(0, result.width - 1), GetRandomValue(0, result.height - 1)};
    result.grid[(int)initialPosition.x + (int)initialPosition.y * result.width].textureInfo = 1;

    Vector2 currentPosition = initialPosition;

    for (int i = 0; i < numberOfSteps; i++) {
        Vector2 newPosition = Vector2Add(currentPosition, allowedMovements[GetRandomValue(0, 3)]);

        if (newPosition.x >= 0 && newPosition.x < mapSize.x && newPosition.y >= 0 && newPosition.y < mapSize.y) {
            result.grid[(int)newPosition.x + (int)newPosition.y * result.width].textureInfo = 1;
            currentPosition = newPosition;
        }
    }

    return result;
}


void SpawnEntity(Enemy recArr[], int* count, Camera2D* camera) 
{
    Vector2 mouse = GetMousePosition();
    Vector2 normal = GetScreenToWorld2D(mouse, *camera);
    Enemy enemy = 
    {
        .position = normal,
        .collisionBox = (Rectangle){ normal.x, normal.y, 50.0, 50.0},
        .speed = 5.0,
        .direction = (Vector2){0.0f, 0.0f},
        .spawnPoint = normal
    };
    if(*count < MAX_ENEMIES) 
    {
        recArr[*count] = enemy;
        (*count)++;
    }
}

void GameUpdateCamera(Camera2D* camera, Player* Player)
{
    camera->target = (Vector2){Player->position.x, Player->position.y};
    camera->offset = (Vector2){ GetScreenWidth()/2.0f, GetScreenHeight()/2.0f };
    camera->rotation = 0.0f;
    camera->zoom = GAME_CAMERA_ZOOM;
}







