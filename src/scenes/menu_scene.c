#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include "menu_scene.h"
#include "raylib.h"
#include "scene_manager.h"
#include "game_scene.h"

static bool shouldChangeScene = false;

void MenuInit(){
    GuiSetStyle(DEFAULT, TEXT_SIZE, 35);
}


void MenuUpdate(){
  if(shouldChangeScene){
    SetScene(CreateGameScene());
  }
}

void MenuDraw(){
    ClearBackground(DARKGRAY);

    const char* title = "Prime SandBox";
    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();
    
    int titleSize = 50;
    int buttonWidth = 300;  
    int buttonHeight = 80;  
 
    int titleWidth = MeasureText(title, titleSize);

    int titleX = (screenWidth / 2) - (titleWidth / 2);
    int titleY = (screenHeight / 2) - (buttonHeight * 2 + titleSize);
    int startButtonX = (screenWidth / 2) - (buttonWidth / 2);
    int startButtonY = buttonHeight + titleY;
    int multiplayerButtonX = (screenWidth / 2) - (buttonWidth / 2);
    int multiplayerButtonY = startButtonY + buttonHeight + 20;
    int quitButtonX = (screenWidth / 2) - (buttonWidth / 2);
    int quitButtonY = multiplayerButtonY + buttonHeight + 20;

    DrawText(title, titleX, titleY, titleSize, LIGHTGRAY);

    if(GuiButton((Rectangle){startButtonX, startButtonY, buttonWidth, buttonHeight},"Iniciar Jogo")){
      shouldChangeScene = true;
    }
    GuiButton((Rectangle){multiplayerButtonX, multiplayerButtonY, buttonWidth, buttonHeight},"Multiplayer");
    if(GuiButton((Rectangle){quitButtonX, quitButtonY, buttonWidth, buttonHeight},"Sair do jogo")){
       gameShouldClose = true;
    }
}

void MenuUnload(){

}

Scene CreateMenuScene(){
  Scene menu;
  menu.Init = MenuInit;
  menu.Update = MenuUpdate;
  menu.Draw = MenuDraw;
  menu.Unload = MenuUnload;
  return menu;
}
