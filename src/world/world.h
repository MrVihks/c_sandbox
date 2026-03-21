#ifndef WORLD_H
#define WORLD_H

#include "raylib.h"

typedef struct {
    Model terrainModel;
    Texture2D terrainTexture;

    Vector3 position;
    Vector3 scale;
} World;

World WorldLoad(const char *modelPath, const char *texturePath);
void WorldDraw(World world);
void WorldUnload(World world);

#endif