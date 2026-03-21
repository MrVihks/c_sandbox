#include "raylib.h"
#include <stdio.h>

#include "camera.h"
#include "entity.h"
#include "world.h"

int main(){
    InitWindow(800,600, "Jogo RTS");
    SetTargetFPS(60);
    
    GameCamera camera = CameraInit();

    World world = WorldLoad(
        "assets/models/world_model.glb",
        "assets/textures/chest_texture.png"
    );

    Entity chest = EntityLoad(
        "assets/models/chest_model.glb",
        "assets/textures/chest_texture.png"
    );

    chest.scale = (Vector3){0.2f,0.2f,0.2f};
    chest.position = (Vector3){0.0f,5.0f, 0.0f};
    world.scale = (Vector3){20.0f,20.0f, 20.0f};

    while(!WindowShouldClose()){

        CameraUpdate(&camera);
        EntityUpdate(&chest);

        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        BeginMode3D(camera.cam);
        WorldDraw(world);
        EntityDraw(chest);
       
        // DrawGrid(10, 1.0f);


        EndMode3D();

        DrawText("RTS de teste", 10,10,20, DARKGRAY);
        EndDrawing();
    }
    EntityUnload(chest);
    WorldUnload(world);
    CloseWindow();
}