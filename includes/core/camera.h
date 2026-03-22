#ifndef CAMERA_H
#define CAMERA_H

#include "raylib.h"

typedef struct {
    Camera3D cam;
    float speed;
    float zoomSpeed;
} GameCamera;

GameCamera CameraInit(void);
void CameraUpdate(GameCamera *camera);

#endif