#ifndef SCENE_H
#define SCENE_H

typedef struct Scene { 
    void(*Init)();
    void(*Update)();
    void(*Draw)();
    void(*Unload)();
} Scene;

#endif