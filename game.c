#include "raylib.h"
#include "game.h"
#include <stdlib.h>
#include <time.h>
#include "raymath.h"
#include <string.h>

void GameInitializePlayer(Vector2* ballPosition, GridData* mapData) {
    Vector2 position = {0};
    for (int i = 0; i < mapData->width; i++) {
        for (int j = 0; j < mapData->height; j++) {
            if (mapData->grid[i][j] == 1) {
                position = (Vector2){i * 600, j * 600}; 
                break;
            }
            
        }
    }
    ballPosition->x = position.x;
    ballPosition->y = position.y;
}


GridData GameGenerateMap() {
    Vector2 mapSize = (Vector2){MAX_MAP_SIZE_X, MAX_MAP_SIZE_Y};
    int numberOfSteps = 200000;

    Vector2 allowedMovements[] = {
        {-1, 0},  // left
        {0, -1},  // up
        {1, 0},   // right
        {0, 1}    // down
    };

    GridData result;
    result.width = mapSize.x;
    result.height = mapSize.y;
    memset(result.grid, 0, sizeof(result.grid));
 
    Vector2 initialPosition = (Vector2){GetRandomValue(0, (int)mapSize.x - 1), GetRandomValue(0, (int)mapSize.y - 1)};
    result.grid[(int)initialPosition.x][(int)initialPosition.y] = 1;

    Vector2 currentPosition = initialPosition;

    for (int i = 0; i < numberOfSteps; i++) {
        while (1) {
            Vector2 newPosition = Vector2Add(currentPosition, allowedMovements[GetRandomValue(0, 3)]);

            if (newPosition.x >= 0 && newPosition.x < mapSize.x && newPosition.y >= 0 && newPosition.y < mapSize.y) {
                result.grid[(int)newPosition.x][(int)newPosition.y] = 1;
                currentPosition = newPosition;
                break;
            }
        }
    }
    return result;
}


