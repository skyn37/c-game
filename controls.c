#include "raylib.h"
#include "raymath.h"
#include <stdio.h>
#include <game.h>
#include <math.h>
#include "raymath.h"

// TODO This is the ground texture w and h should handle that better
#define GRID_CELL_SIZE 600

// Function to convert world coordinates to grid coordinates
void WorldToGrid(Vector2 worldPos, int* gridX, int* gridY) {
    *gridX = (int)(worldPos.x / GRID_CELL_SIZE);
    *gridY = (int)(worldPos.y / GRID_CELL_SIZE);
}
// Function to see if a player is colliding with an enemy
bool PlayerCollidesWithEnemy(Player* Player, Enemy* enemy){
    return CheckCollisionRecs(Player->collisionBox, enemy->collisionBox);
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

void HandlePlayerControls(Player* Player, GridData* mapData, Enemy enemyArr[], size_t len) {
    Rectangle nextPosition = Player->collisionBox;
    static Vector2 velocity = {0.0, 0.0};
    float moveSpeed = 50.0f * GetFrameTime() * Player->speed;

    // Determine movement direction based on key input
    if (IsKeyDown(KEY_RIGHT)) velocity.x = moveSpeed;
    else if (IsKeyDown(KEY_LEFT)) velocity.x = -moveSpeed;
    else velocity.x = 0.0f;

    if (IsKeyDown(KEY_UP)) velocity.y = -moveSpeed;
    else if (IsKeyDown(KEY_DOWN)) velocity.y = moveSpeed;
    else velocity.y = 0.0f;

    // Check for collisions with enemies
    for (size_t i = 0; i < len; ++i) {
        if (CheckCollisionRecs(nextPosition, enemyArr[i].collisionBox)) {
            // Calculate the direction to the enemy
            Vector2 direction = Vector2Normalize((Vector2){ enemyArr[i].position.x - Player->position.x, enemyArr[i].position.y - Player->position.y});

            // Calculate the dot product to determine if the movement is towards the enemy
            float dotProduct = Vector2DotProduct(direction, velocity);
            // If the movement is towards the enemy, adjust the movement direction
            if (dotProduct > 0) {
                Vector2 perpendicular = { -direction.y, direction.x };
                velocity.x = perpendicular.x * moveSpeed;
                velocity.y = perpendicular.y * moveSpeed;
            }
            break;
        }
    }

    // Check for collisions with obstacles
    nextPosition.x += velocity.x;
    nextPosition.y += velocity.y;

    if (RectangleCollidesWithObstacle(mapData, nextPosition)) {
        velocity.x = 0.0f;
        velocity.y = 0.0f;
    }

    // Update the player's position
    Player->collisionBox.x += velocity.x;
    Player->collisionBox.y += velocity.y;
    Player->position.x = Player->collisionBox.x + Player->collisionBox.width / 2;
    Player->position.y = Player->collisionBox.y + Player->collisionBox.height / 2;
}

void UpdateEnemyPosition(Enemy *enemy, Vector2 position, GridData* mapData) {   
    Vector2 pos = position;
    Rectangle nextPosition = (Rectangle){ position.x,  position.y,  enemy->collisionBox.width,  enemy-> collisionBox.height };

    if (!RectangleCollidesWithObstacle(mapData, nextPosition)) {
        enemy->position = pos;
        enemy->collisionBox = nextPosition;
    }
}

void ControlsUpdatePositions(Player* Player, GridData* mapData, Enemy enemyArr[], size_t len) {

    for (size_t i = 0; i < len; ++i) {
        int xOffset = GetRandomValue(-10, 10);  // This is the position change the whole func should be smoother and no magic numbers so TODO
        int yOffset = GetRandomValue(-10, 10);  
        int x = enemyArr[i].position.x + xOffset * GetFrameTime() * enemyArr[i].speed;
        int y = enemyArr[i].position.y + yOffset * GetFrameTime() * enemyArr[i].speed;

        if(!PlayerCollidesWithEnemy(Player, &enemyArr[i])){
            UpdateEnemyPosition(&enemyArr[i], (Vector2){x, y}, mapData);
        }

    }

    HandlePlayerControls(Player, mapData, enemyArr, len);
}

void EnemySearchTarget(Enemy enemy, Enemy enemy2) {
    GetCollisionRec(enemy.collisionBox, enemy.collisionBox);
}

