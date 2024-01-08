#include "raylib.h"
#include "raymath.h"
#include <stdio.h>
#include <game.h>
#include <math.h>
#include <sys/_types/_size_t.h>
#include "raymath.h"

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

bool RectangleCollidesWithObstacle(GridData* mapData, Rectangle rect) {
    int topLeftX, topLeftY, topRightX, topRightY, bottomLeftX, bottomLeftY, bottomRightX, bottomRightY;

    WorldToGrid((Vector2){ rect.x, rect.y }, &topLeftX, &topLeftY);
    WorldToGrid((Vector2){ rect.x + rect.width, rect.y }, &topRightX, &topRightY);
    WorldToGrid((Vector2){ rect.x, rect.y + rect.height }, &bottomLeftX, &bottomLeftY);
    WorldToGrid((Vector2){ rect.x + rect.width, rect.y + rect.height }, &bottomRightX, &bottomRightY);

    return CellContainsObstacle(mapData, topLeftX, topLeftY) ||
           CellContainsObstacle(mapData, topRightX, topRightY) ||
           CellContainsObstacle(mapData, bottomLeftX, bottomLeftY) ||
           CellContainsObstacle(mapData, bottomRightX, bottomRightY);
}

void HandlePlayerControls(Player* Player, GridData* mapData) {
    Rectangle nextPosition = Player->collisionBox;
    static Vector2 velocity = {0.0, 0.0};


    if (IsKeyDown(KEY_RIGHT)) nextPosition.x += 50.0f * GetFrameTime() * Player->speed;
    if (IsKeyDown(KEY_LEFT)) nextPosition.x -= 50.0f * GetFrameTime() *  Player->speed;
    if (IsKeyDown(KEY_UP)) nextPosition.y -= 50.0f * GetFrameTime() * Player->speed;
    if (IsKeyDown(KEY_DOWN)) nextPosition.y += 50.0f * GetFrameTime() *  Player->speed;


    // Check if the next position collides with an obstacle
    if (!RectangleCollidesWithObstacle(mapData, nextPosition)) {
        // Update the player's position only if it doesn't collide with an obstacle
        Player->collisionBox = nextPosition;
        Player->position.x = nextPosition.x + nextPosition.width / 2;
        Player->position.y = nextPosition.y + nextPosition.height / 2;
    }
}


// TODO 
// 1st lets try random position with map collision
// 2nd will try to search for the player and engage 
void UpdateEnemyPosition(Enemy *enemy, Vector2 position, GridData* mapData) {   
    Vector2 pos = position;
    Rectangle nextPosition = (Rectangle){ position.x,  position.y,  enemy->collisionBox.width,  enemy-> collisionBox.height };

    if (!RectangleCollidesWithObstacle(mapData, nextPosition)) {
        enemy->position = pos;
        enemy->collisionBox = nextPosition;
    }
}

void ControlsUpdatePositions(Player* Player, GridData* mapData, Enemy enemyArr[], size_t len) {
    HandlePlayerControls(Player, mapData);

    for (size_t i = 0; i < len; ++i) {
        int xOffset = GetRandomValue(-10, 10);  // This is the position change the whole func should be smoother and no magic numbers so TODO
        int yOffset = GetRandomValue(-10, 10);  
        int x = enemyArr[i].position.x + xOffset * GetFrameTime() * enemyArr[i].speed;
        int y = enemyArr[i].position.y + yOffset * GetFrameTime() * enemyArr[i].speed;

        UpdateEnemyPosition(&enemyArr[i], (Vector2){x, y}, mapData);
    }
}

void EnemySearchTarget(Enemy enemy, Enemy enemy2) {

    GetCollisionRec(enemy.collisionBox, enemy.collisionBox);

}

