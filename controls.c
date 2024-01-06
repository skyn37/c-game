#include "raylib.h"
#include <stdio.h>
#include <game.h>
#include <math.h>
#include <sys/_types/_size_t.h>


// TODO sexy globals
int SPEEDx = 10;
int SPEEDy = 10;



// TODO This is the ground texture w and h should handle that better
#define GRID_CELL_SIZE 600
// Grid based collision detection .. its ok  TODO:  needs improvement 
// Function to convert world coordinates to grid coordinates
void WorldToGrid(Vector2 worldPos, int* gridX, int* gridY) {
    *gridX = (int)(worldPos.x / GRID_CELL_SIZE);
    *gridY = (int)(worldPos.y / GRID_CELL_SIZE);
}

// Function to check if a cell in the grid contains an obstacle
bool CellContainsObstacle(GridData* mapData, int gridX, int gridY) {
    if (gridX >= 0 && gridX < mapData->width && gridY >= 0 && gridY < mapData->height) {
        return mapData->grid[gridX + gridY * mapData->width].textureInfo == 0;
    }
    return false;
}

void HandlePlayerControls(Vector2* Player, GridData* mapData) {
    Vector2 nextPosition = *Player;
    if (IsKeyDown(KEY_RIGHT)) nextPosition.x += 100.0f * GetFrameTime() * SPEEDx;
    if (IsKeyDown(KEY_LEFT)) nextPosition.x -= 100.0f * GetFrameTime() * SPEEDx;
    if (IsKeyDown(KEY_UP)) nextPosition.y -= 100.0f * GetFrameTime() * SPEEDy;
    if (IsKeyDown(KEY_DOWN)) nextPosition.y += 100.0f * GetFrameTime() * SPEEDy;

    // Convert next position to grid coordinates
    int gridX, gridY;
    WorldToGrid(nextPosition, &gridX, &gridY);

    // Check if the grid cell contains an obstacle
    if (!CellContainsObstacle(mapData, gridX, gridY)) {
        // Update the player's position only if the cell doesn't contain an obstacle
        *Player = nextPosition;
    }
}


// TODO 
// 1st lets try random position with map collision
// 2nd will try to search for the player and engage 
void UpdateEnemyPosition(Enemy *enemy, Vector2 position, GridData* mapData)
{   
    Vector2 nextPosition = position;
    int gridX, gridY;
    WorldToGrid(nextPosition, &gridX, &gridY);

    if (!CellContainsObstacle(mapData, gridX, gridY)) {
        enemy->position = nextPosition;
        enemy->collisionBox.y = nextPosition.y;
        enemy->collisionBox.x = nextPosition.x;
    }
}

void ControlsUpdatePositions(Vector2* Player, GridData* mapData, Enemy enemyArr[], size_t len)
{
    HandlePlayerControls(Player, mapData);

    for (size_t i = 0; i < len; ++i) {
        int xOffset = GetRandomValue(-10, 10);  // This is the position change the whole func should be smoother and no magic numbers so TODO
        int yOffset = GetRandomValue(-10, 10);  
        int x = enemyArr[i].position.x + xOffset;
        int y = enemyArr[i].position.y + yOffset;

        printf("New position for enemy %zu: (%d, %d)\n", i, x, y);
        UpdateEnemyPosition(&enemyArr[i], (Vector2){x, y}, mapData);
    }
}

void EnemySearchTarget(Enemy enemy, Enemy enemy2)
{

    GetCollisionRec(enemy.collisionBox, enemy.collisionBox);

}









