#include <stdio.h>
#include "raylib.h"
#include "rlgl.h"
#include <stdlib.h>
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
    const char* shaderPath = TextFormat("%s/shaders/test_shader.fs", currentFileDirectory);
    Shader customShader = LoadShader(0, shaderPath);

    Vector2 Player;
    Image groundImage = LoadImage(imagePath);
    Texture2D groundTexture = LoadTextureFromImage(groundImage);
    printf("%d %d  \n", groundTexture.height, groundTexture.width);
    SetShaderValueTexture(customShader, GetShaderLocation(customShader, "texture0"), groundTexture);
    UnloadImage(groundImage);
    GridData mapData =  GameGenerateMap();
    GameInitializePlayer(&Player, &mapData);
    printf("%f %f", Player.x, Player.y);
    SetTargetFPS(30);
    while (!WindowShouldClose())
    {
       // BeginShaderMode(customShader);

        DrawGame(Player, mapData, groundTexture);
       // EndShaderMode();
        ControlsInitControls(&Player, &mapData);

    }
    free(mapData.grid);
    UnloadTexture(groundTexture);
    UnloadShader(customShader);
    CloseWindow();
}
