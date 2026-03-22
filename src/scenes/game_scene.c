#include "game_scene.h"
#include "raylib.h"
#include "raymath.h"
#include "camera.h"
#include "entity.h"
#include "world.h"

static GameCamera camera;
static Entity rock;
static World world;
static Matrix transform;
static RayCollision hit;
static BoundingBox box;
static bool isDragging;
static Vector3 dragOffset;

void GameInit(){
    camera = CameraInit();

    isDragging = false;
    dragOffset = (Vector3){0};

    world = WorldLoad(
        "assets/models/world_model.glb",
        ""
    );

    rock = EntityLoad(
        "assets/models/rock_model.glb",
        ""
    );

    rock.scale = (Vector3){1.0f,1.0f,1.0f};
    rock.position = (Vector3){0.0f,4.5f, 0.0f};

    world.scale = (Vector3){20.0f,20.0f, 20.0f};

    transform = MatrixScale(
        world.scale.x,
        world.scale.y,
        world.scale.z
    );

}

void GameUpdate(){
    CameraUpdate(&camera);
    EntityUpdate(&rock);

    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
        Ray ray = GetMouseRay(GetMousePosition(), camera.cam);

        hit = GetRayCollisionBox(ray, box);
         
        if(hit.hit){
            isDragging = true;

            dragOffset = Vector3Subtract(rock.position, hit.point);
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

            rock.position.x = newPos.x;
            rock.position.z = newPos.z;
        }
    }

    box = GetModelBoundingBox(rock.model);
    box.min = Vector3Scale(box.min, rock.scale.x);
    box.max = Vector3Scale(box.max, rock.scale.x);
            
    box.min = Vector3Add(box.min, rock.position);
    box.max = Vector3Add(box.max, rock.position);
        


}

void GameDraw(){
    BeginMode3D(camera.cam);

    WorldDraw(world);
    EntityDraw(rock);


    if(isDragging){
        DrawBoundingBox(box, RED);
    }

    EndMode3D();

    DrawText(TextFormat("FPS: %d", GetFPS()), 800-120, 10,30, DARKGRAY);  
    DrawText("Sandbox feito em C", 10, 10,30, DARKGRAY);
    DrawText("Use Q para aumentar o zoom e E para diminuir", 10, 600 - 70,30, DARKGRAY);
    DrawText("Use as setinhas para mover a camera", 10, 600 - 40,30, DARKGRAY);
}

void GameUnload(){
    EntityUnload(rock);
    WorldUnload(world);
}

Scene CreateGameScene(){
    Scene scene;
    scene.Init = GameInit;
    scene.Update = GameUpdate;
    scene.Draw = GameDraw;
    scene.Unload = GameUnload;
    return scene;
}