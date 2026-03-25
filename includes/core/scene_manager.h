#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "scene.h"
#include <stdbool.h>

extern bool gameShouldClose;

void SetScene(Scene newScene);
void UpdateScene();
void DrawScene();
void UnloadScene();

#endif