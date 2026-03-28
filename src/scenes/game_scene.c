#include "game_scene.h"
#include "raylib.h"
#include "raymath.h"
#include "camera.h"
#include "entity.h"
#include "world.h"
#include "gui.h"
#include "tutorial.h"


static GameCamera camera;
static World world;
static Entity rock;
static Entity tree;
static Entity tree2;

static Matrix transform;
static RayCollision hit;
static BoundingBox box;
static bool isDragging;
static Vector3 dragOffset;

static Music backgroundMusic;
static float musicVolume = 0.5f;

void GameInit(){
    camera = CameraInit();
    
    backgroundMusic = LoadMusicStream("assets/audio/background_music.mp3");
    PlayMusicStream(backgroundMusic);
    SetMusicVolume(backgroundMusic, musicVolume);

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
    tree = EntityLoad(
        "assets/models/tree_model.glb",
        ""
    );
    tree2 = EntityLoad(
        "assets/models/tree_model.glb",
        ""
    );  
    
  
    rock.scale = (Vector3){1.0f, 1.0f, 1.0f};
    rock.position = (Vector3){0.0f,0.0f, 0.0f};
    
    tree.scale = (Vector3){1.0f, 1.0f, 1.0f};
    tree.position = (Vector3){5.0f,1.2f, 5.0f};

    tree2.scale = (Vector3){1.0f, 1.0f, 1.0f};
    tree2.position = (Vector3){-5.0f,1.2f, -5.0f};


    // por enquanto vai ficar improvisado assim a posição Y do mundo.
    world.scale = (Vector3){50.0f,20.0f, 50.0f};
    world.position = (Vector3){0.0f,-4.4f,0.0f};

    transform = MatrixScale(
        world.scale.x,
        world.scale.y,
        world.scale.z
    );

    GuiInit();
    InitTutorial();
}

void GameUpdate(){
    CameraUpdate(&camera);
    EntityUpdate(&rock);

    UpdateMusicStream(backgroundMusic);
    UpdateTutorial();
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
    ClearBackground(RAYWHITE);
    BeginMode3D(camera.cam);

    WorldDraw(world);
    EntityDraw(rock);

    EntityDraw(tree);
    EntityDraw(tree2);

    if(isDragging){
        DrawBoundingBox(box, RED);
    }

    EndMode3D();

    GuiDraw();
    DrawTutorial();
}

void GameUnload(){
    GuiUnload();
    UnloadTutorial();
    EntityUnload(rock);
    EntityUnload(tree);
    EntityUnload(tree2);
    WorldUnload(world);

    StopMusicStream(backgroundMusic);
    UnloadMusicStream(backgroundMusic);
}

Scene CreateGameScene(){
    Scene scene;
    scene.Init = GameInit;
    scene.Update = GameUpdate;
    scene.Draw = GameDraw;
    scene.Unload = GameUnload;
    return scene;
}