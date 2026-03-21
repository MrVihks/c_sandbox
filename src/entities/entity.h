#ifndef ENTITY_H
#define ENTITY_H

#include "raylib.h"


typedef struct {
    Model model;
    Texture2D texture;
    
    Vector3 position;
    Vector3 scale;
    float rotation;
} Entity;

Entity EntityLoad(const char *modelPath, const char *texturePath);
void EntityUpdate(Entity *e);
void EntityDraw(Entity e);
void EntityUnload(Entity e);

#endif