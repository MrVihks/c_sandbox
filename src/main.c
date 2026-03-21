#include <stdio.h>

#include "raylib.h"
#include "raymath.h"

#include "camera.h"
#include "entity.h"
#include "world.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

int main(){

    int windowX = 1280;
    int windowY = 768;

    InitWindow(windowX,windowY, "Jogo RTS");
    SetTargetFPS(60);
    
    InitAudioDevice();
    Music music = LoadMusicStream("assets/audio/backmusic.mp3");

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
    chest.position = (Vector3){0.0f,4.5f, 0.0f};
    world.scale = (Vector3){20.0f,20.0f, 20.0f};

    Matrix transform = MatrixScale(
        world.scale.x,
        world.scale.y,
        world.scale.z
    );

    RayCollision hit;
    BoundingBox box;
    
    bool isDragging = false;
    Vector3 dragOffset = {0};

    PlayMusicStream(music);
    SetMusicVolume(music, 1.0f);
    while(!WindowShouldClose()){

        CameraUpdate(&camera);
        EntityUpdate(&chest);
        UpdateMusicStream(music);

        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
            Ray ray = GetMouseRay(GetMousePosition(), camera.cam);

            hit = GetRayCollisionBox(ray, box);
         
            if(hit.hit){
                isDragging = true;

                dragOffset = Vector3Subtract(chest.position, hit.point);
            }
        }

        if(IsMouseButtonReleased(MOUSE_LEFT_BUTTON)){
            isDragging = false;
        }
   
        if(isDragging){
            Ray ray = GetMouseRay(GetMousePosition(), camera.cam);

            RayCollision groundHit = GetRayCollisionMesh(ray, world.terrainModel.meshes[0],transform);

            if(groundHit.hit){
                Vector3 newPos = Vector3Add(groundHit.point, dragOffset);

                chest.position.x = newPos.x;
                chest.position.z = newPos.z;
            }
        }

        box = GetModelBoundingBox(chest.model);
        box.min = Vector3Scale(box.min, chest.scale.x);
        box.max = Vector3Scale(box.max, chest.scale.x);
            
        box.min = Vector3Add(box.min, chest.position);
        box.max = Vector3Add(box.max, chest.position);
        
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        BeginMode3D(camera.cam);
        
        WorldDraw(world);
        EntityDraw(chest);

        if(isDragging){
            DrawBoundingBox(box,RED);
        }

        EndMode3D();
        DrawText(TextFormat("FPS: %d", GetFPS()), windowX-120, 10,30, DARKGRAY);
        DrawText("Sandbox feito em C", 10, 10,30, DARKGRAY);
        DrawText("Use Q para aumentar o zoom e E para diminuir", 10, windowY - 70,30, DARKGRAY);
        DrawText("Use as setinhas para mover a camera", 10, windowY - 40,30, DARKGRAY);
        EndDrawing();
    }

    UnloadMusicStream(music);
   
    EntityUnload(chest);
    WorldUnload(world);

    CloseAudioDevice();
    CloseWindow();

    return 0;
}