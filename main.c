#include "raylib.h"
#include "scene_manager.h"
#include "game_scene.h"
#include "menu_scene.h"

bool gameShouldClose = false;

int main(){

    int windowX = 800;
    int windowY = 600;

    InitWindow(windowX,windowY, "Prime SandBox");
    SetTargetFPS(60);
    
    // SetScene(CreateGameScene());
    SetScene(CreateMenuScene());

    while(!WindowShouldClose() && !gameShouldClose){

        UpdateScene();
        BeginDrawing();
      
              
        DrawScene();
        EndDrawing();
    }

    UnloadScene();
    CloseWindow();
    
    return 0;
}