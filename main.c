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

    // TODO We should prolly add some sort of loading logic this will get out of hand at some point 
    const int WIDTH = 1200;
    const int HEIGHT = 720;
    const char TITLE[] = "Test";
    InitWindow(WIDTH, HEIGHT, TITLE);
    const char* currentFileDirectory = GetDirectoryPath(__FILE__);
    const char* imagePath = TextFormat("%s/assets/brick_floor.png", currentFileDirectory);
    const char* shaderPath = TextFormat("%s/shaders/test_shader.fs", currentFileDirectory);
    Shader customShader = LoadShader(0, shaderPath);

    // We should handle those initializations better probably
    Vector2 Player;
    Enemy recArr[50];
    size_t enemy_arr_len = sizeof(recArr) / sizeof(recArr[0]);
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

        DrawGame(Player, mapData, groundTexture, recArr);

        // EndShaderMode();
        ControlsUpdatePositions(&Player, &mapData, recArr, enemy_arr_len);

    }
    free(mapData.grid);
    UnloadTexture(groundTexture);
    UnloadShader(customShader);
    CloseWindow();
}




