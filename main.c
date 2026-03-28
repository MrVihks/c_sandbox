#include "raylib.h"
#include "scene_manager.h"
#include "gui_manager.h"
#include "game_scene.h"
#include "menu_scene.h"
#include <time.h>
#include <stdlib.h>

bool gameShouldClose = false;

int main(){

    int windowX = 800;
    int windowY = 600;

    srand(time(NULL));

    InitWindow(windowX,windowY, "Prime SandBox");
    InitAudioDevice();

    SetTargetFPS(60);
    
    SetScene(CreateMenuScene());
 
    while(!WindowShouldClose() && !gameShouldClose){

        UpdateScene();
        BeginDrawing();
        
              
        DrawScene();
        EndDrawing();
    }

    UnloadScene();
    
    CloseAudioDevice();
    CloseWindow();
    
    return 0;
}