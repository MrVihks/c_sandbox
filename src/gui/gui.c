#include "raylib.h"
#include "gui.h"


void GuiDraw(){
    DrawText(TextFormat("FPS: %d", GetFPS()), 800-120, 10,30, RED);  
    DrawText("Sandbox feito em C", 10, 10,30, DARKGRAY);
    DrawText("Use Q para aumentar o zoom e E para diminuir", 10, 600 - 70,30, DARKGRAY);
    DrawText("Use as setinhas para mover a camera", 10, 600 - 40,30, DARKGRAY);
}