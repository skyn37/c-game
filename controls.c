#include "raylib.h"
#include <stdio.h>
#include <game.h>
#include <math.h>


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

void ControlsInitControls(Vector2* Player, GridData* mapData)
{
    HandlePlayerControls(Player, mapData);
}




