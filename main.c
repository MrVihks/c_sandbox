#include "raylib.h"
#include "scene_manager.h"
#include "game_scene.h"

int main(){

    int windowX = 800;
    int windowY = 600;

    InitWindow(windowX,windowY, "Jogo RTS");
    SetTargetFPS(60);
    
    SetScene(CreateGameScene());

    while(!WindowShouldClose()){

        UpdateScene();
        BeginDrawing();
        ClearBackground(RAYWHITE);
              
        DrawScene();
        EndDrawing();
    }

    UnloadScene();
    CloseWindow();
    
    return 0;
}