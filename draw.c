#include "raylib.h"
#include "game.h"
#include <stdio.h>

Camera2D InitCamera(Vector2* Player);
void DrawMap(Texture2D Ground, GridData mapData);




void DrawGame(Vector2 ballPosition, GridData mapData, Texture2D Ground)
{
    BeginDrawing();

    ClearBackground(GRAY);

    BeginMode2D(InitCamera(&ballPosition));
    DrawMap(Ground, mapData);
    DrawCircleV(ballPosition, 50, BLACK);
    DrawText("move the ball with arrow keys", 10, 10, 20, DARKGRAY);
    EndMode2D();
    EndDrawing();
}

void DrawMap(Texture2D Ground, GridData mapData)
{
    for (int i = 0; i < mapData.width; i++) {
        for (int j = 0; j < mapData.height; j++) {
            Vector2 position = {i * Ground.width, j * Ground.height}; 
            if (mapData.grid[i + j * mapData.width].textureInfo == 1) {
                DrawTextureEx(Ground, position, 0.0f, 1.0f, WHITE);
                DrawLine(position.x + Ground.width, position.y, position.x + Ground.width, position.y + Ground.height, GREEN);
                DrawLine(position.x, position.y + Ground.height, position.x + Ground.width, position.y + Ground.height, GREEN);

            } else {
                DrawRectangleLinesEx((Rectangle){ position.x, position.y, Ground.width, Ground.height }, 1, RED);
            }
        }
    }
}

Camera2D InitCamera(Vector2* Player)
{
    Camera2D camera = {0};
    camera.target = (Vector2){Player->x, Player->y};
    camera.offset = (Vector2){ GetScreenWidth()/2.0f, GetScreenHeight()/2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 0.1f;


    return camera;
}




