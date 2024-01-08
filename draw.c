#include "raylib.h"
#include "game.h"
#include <stdio.h>
#include "raygui.h"

Camera2D InitCamera(Vector2* Player, float* zoom);
void DrawMap(Texture2D Ground, GridData mapData);
void EditCamera(Camera2D* camera);


// GLobal count there should be a better way TODO //
static int count = 0;

void DrawGame(Player Player, GridData mapData, Texture2D Ground, Enemy enemyCollection[], Camera2D camera)
{

    BeginDrawing();
    ClearBackground(GRAY);
    BeginMode2D(camera);
    DrawMap(Ground, mapData);

    DrawRectangleLinesEx(Player.collisionBox, 1.0, RED);

    DrawText("move the ball with arrow keys", 10, 10, 20, DARKGRAY);

    for (int i = 0; i < count; i++) {
        DrawRectangleRec(enemyCollection[i].collisionBox, GREEN);

    } 



    EndMode2D();
    EndDrawing();

    if(IsKeyPressed(KEY_W))
    {
        SpawnEntity(enemyCollection, &count, &camera);
    } 


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








