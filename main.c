#include <stdio.h>
#include "raylib.h"
#include "rlgl.h"

#include <stddef.h> // Required for: NULL
#include <math.h>   // Required for: sinf()

#include "game.h"
#include "controls.h"
#include "draw.h"
//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------

int main(void)
{   
    const int WIDTH = 1200;
    const int HEIGHT = 720;
    const char TITLE[] = "Test";
    InitWindow(WIDTH, HEIGHT, TITLE);
    const char* currentFileDirectory = GetDirectoryPath(__FILE__);
    const char* imagePath = TextFormat("%s/assets/brick_floor.png", currentFileDirectory);
    Image groundImage = LoadImage(imagePath);
    Texture2D groundTexture = LoadTextureFromImage(groundImage);
    UnloadImage(groundImage);
    Vector2 Player;
    GridData mapData =  GameGenerateMap();
    GameInitializePlayer(&Player, &mapData);
    SetTargetFPS(30);
    while (!WindowShouldClose())
    {
        DrawGame(Player, mapData, groundTexture);
        ControlsInitControls(&Player);
    }
    UnloadTexture(groundTexture);
    CloseWindow();
}
