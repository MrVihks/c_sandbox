#include "tutorial.h"
#include "raylib.h"
#include "raygui.h"

static bool panelClosed = false;

void InitTutorial(){
    GuiSetStyle(DEFAULT, TEXT_SIZE, 25);
    GuiSetStyle(DEFAULT, BACKGROUND_COLOR, (int)ColorToInt((Color){200, 200, 200, 255}));
}

void DrawTutorial(){
    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();

    int panelWidth  = screenWidth - 100;
    int panelHeight = 200;

    int panelX = (screenWidth / 2) - (panelWidth / 2);
    int panelY = 40;
 
    int tutorialFontSize = 25;

    if(!panelClosed){
        Rectangle tutorialPanel = {panelX, panelY, panelWidth, panelHeight};
        GuiPanel(tutorialPanel, (const char*)0);

        DrawText("Tutorial Prime Sandbox", panelX + 10, panelY + 10, 40, DARKGRAY);      
        DrawText("Use Q para aumentar o zoom e E para diminuir", panelX + 20, panelY + 70, tutorialFontSize, DARKGRAY);
        DrawText("Use as setinhas para mover a camera", panelX + 20, panelY + 110, tutorialFontSize, DARKGRAY);

        if(GuiButton((Rectangle){panelX + panelWidth - 160, panelY + panelHeight - 60, 150, 50}, "Fechar")){
            panelClosed = true;
        }
    }
}

void UpdateTutorial(){
  // nada aqui por enquanto
}

void UnloadTutorial(){
  // aqui só vou usar caso precise descarregar alguma textura
}