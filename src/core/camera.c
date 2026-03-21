#include "camera.h"

GameCamera CameraInit(void){
    GameCamera gc = {0};

    gc.cam.position = (Vector3){0.0f,20.0f,20.0f};
    gc.cam.target = (Vector3){0.0f,0.0f,0.0f};
    gc.cam.up = (Vector3){0.0f,1.0f,0.0f};
    gc.cam.fovy = 45.0f;
    gc.cam.projection = CAMERA_PERSPECTIVE;

    gc.speed = 10.0f;
    gc.zoomSpeed = 20.0f;

    return gc;
}

void CameraUpdate(GameCamera *camera){
    float dt = GetFrameTime();

    float move = camera -> speed * dt;
    float zoom = camera -> zoomSpeed * dt;

    if(IsKeyDown(KEY_RIGHT)){
        camera -> cam.position.x += move;
        camera -> cam.target.x += move;
    }
    if(IsKeyDown(KEY_LEFT)){
        camera -> cam.position.x -= move;
        camera -> cam.target.x -= move;
    }
    if(IsKeyDown(KEY_DOWN)){
        camera -> cam.position.z += move;
        camera -> cam.target.z += move;
    }
    if(IsKeyDown(KEY_UP)){
        camera -> cam.position.z -= move;
        camera -> cam.target.z -= move;
    }


    if(IsKeyDown(KEY_Q)) camera -> cam.position.y += zoom;
    if(IsKeyDown(KEY_E)) camera -> cam.position.y -= zoom;
}