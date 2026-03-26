#include "raylib.h"
#include "gui.h"
#include "raygui.h"

static bool panelClosed = true;
static Texture2D rockTexture;

void GuiInit(){
    GuiSetStyle(DEFAULT, TEXT_SIZE, 25);
    GuiSetStyle(DEFAULT, BACKGROUND_COLOR, (int)ColorToInt((Color){200, 200, 200, 255}));

    rockTexture = LoadTexture("assets/gui/rock_texture.png");
}

void GuiDraw(){
    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();
    
    int panelWidth = screenWidth - 100;
    int panelHeight = 200;

    int panelX = (screenWidth / 2) - (panelWidth / 2);
    int panelY = (screenHeight - panelHeight) - 10;

    char* buttonText = panelClosed ? "Abrir" : "Fechar";
    int buttonWidth = 150;
    int buttonHeight = 50;
    int buttonX = 50;
    int buttonY;

  
    DrawText(TextFormat("FPS: %d", GetFPS()), 800-120, 10,30, RED);  
    // DrawText("Sandbox feito em C", 10, 10,30, DARKGRAY);
    // DrawText("Use Q para aumentar o zoom e E para diminuir", 10, 600 - 70,30, DARKGRAY);
    // DrawText("Use as setinhas para mover a camera", 10, 600 - 40,30, DARKGRAY);

    Rectangle panelRectangle = {panelX, panelY, panelWidth, panelHeight};
    
    int textureX = panelX + (panelWidth / 4);
    int textureY = panelY + 20;

    if(!panelClosed){
       buttonY = panelY - buttonHeight - 10;
       GuiPanel(panelRectangle, (const char*)0);

    }else{
        buttonY = panelY + panelHeight - buttonHeight - 10;
    }

    if(GuiButton((Rectangle){buttonX, buttonY, buttonWidth, buttonHeight}, buttonText)){
        panelClosed = !panelClosed;
    }
}

void GuiUnload(){
    UnloadTexture(rockTexture);
}