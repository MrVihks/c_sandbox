#include "tutorial.h"
#include "raylib.h"
#include "raygui.h"

void InitTutorial(){
    GuiSetStyle(DEFAULT, TEXT_SIZE, 25);
    GuiSetStyle(DEFAULT, BACKGROUND_COLOR, (int)ColorToInt((Color){200, 200, 200, 255}));
}

void DrawTutorial(){
    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();

    int panelWidth  = screenWidth - 100;
    int panelHeight = 150;

    int panelX = (screenWidth / 2) - (panelWidth / 2);
    int panelY = 10;
    
    Rectangle tutorialPanel = {panelX, panelY, panelWidth, panelHeight};
    GuiPanel(tutorialPanel, (const char*)0);
    // DrawText("Sandbox feito em C", 10, 10,30, DARKGRAY);
    // DrawText("Use Q para aumentar o zoom e E para diminuir", 10, 600 - 70,30, DARKGRAY);
    // DrawText("Use as setinhas para mover a camera", 10, 600 - 40,30, DARKGRAY);
}

void UpdateTutorial(){
  // nada aqui por enquanto
}

void UnloadTutorial(){
  // aqui só vou usar caso precise descarregar alguma textura
}