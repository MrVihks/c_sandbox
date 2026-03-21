#include "entity.h"

Entity EntityLoad(const char *modelPath, const char *texturePath){
    Entity e = {0};

    e.model = LoadModel(modelPath);
    e.texture = LoadTexture(texturePath);

    e.model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = e.texture;
    
    e.position = (Vector3){0,0,0};
    e.scale = (Vector3){1,1,1};
    e.rotation = 0.0f;

    return e;
}

void EntityUpdate(Entity *e){
    e -> rotation += 60.0f * GetFrameTime();
}

void EntityDraw(Entity e){
    DrawModelEx(
        e.model,
        e.position,
        (Vector3){0,1,0},
        e.rotation,
        e.scale,
        WHITE
    );
}

void EntityUnload(Entity e){
    UnloadTexture(e.texture);
    UnloadModel(e.model);
}

