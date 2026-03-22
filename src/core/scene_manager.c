#include "scene_manager.h"

static Scene currentScene;

void SetScene(Scene newScene){
    currentScene = newScene;
    currentScene.Init();
}

void UpdateScene(){
    currentScene.Update();
}

void DrawScene(){
    currentScene.Draw();
}

void UnloadScene(){
    currentScene.Unload();
}

