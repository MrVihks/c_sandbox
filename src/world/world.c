#include "world.h"

World WorldLoad(const char *modelPath, const char *texturePath){
    World w = {0};

    w.terrainModel = LoadModel(modelPath);
    w.terrainTexture = LoadTexture(texturePath);

    w.terrainModel.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = w.terrainTexture;

    w.position = (Vector3){0,0,0};
    w.scale = (Vector3){1.0f,1.0f,1.0f};

    return w;
}

void WorldDraw(World world){
    DrawModelEx(
        world.terrainModel,
        world.position,
        (Vector3){1,0,0},
        0.0f,
        world.scale,
        WHITE
    );
}

void WorldUnload(World world){
    UnloadTexture(world.terrainTexture);
    UnloadModel(world.terrainModel);
}