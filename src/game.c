#include "game.h"
#include "raylib.h"
#include "player.h"
#include "menu.h"

static Scene currentScene;
static Player player;

void InitGame()
{
    currentScene = SCENE_MENU;
    InitMenu();
    InitPlayer(&player);
}

void ChangeScene(Scene newScene)
{
    currentScene = newScene;
}

void UpdateGame()
{
    switch(currentScene)
    {
        case SCENE_MENU:
        {
            UpdateMenu();
        } break;

        case SCENE_EXPLORE:
        {
            UpdatePlayer(&player);

            if(IsKeyPressed(KEY_P))
                ChangeScene(SCENE_PUZZLE);
        } break;

        case SCENE_PUZZLE:
        {
            if(IsKeyPressed(KEY_B))
                ChangeScene(SCENE_BULLET_HELL);
        } break;

        case SCENE_BULLET_HELL:
        {
            if(IsKeyPressed(KEY_M))
                ChangeScene(SCENE_MENU);
        } break;

        default:
        break;
    }
}

void DrawGame()
{
    switch(currentScene)
    {
        case SCENE_MENU:
        {
            DrawMenu();
        } break;

        case SCENE_EXPLORE:
        {
            DrawText("EXPLORE SCENE", 10, 10, 20, WHITE);
            DrawPlayer(&player);
        } break;

        case SCENE_PUZZLE:
        {
            DrawText("PUZZLE SCENE", 10, 10, 20, ORANGE);
        } break;

        case SCENE_BULLET_HELL:
        {
            DrawText("BULLET HELL SCENE", 10, 10, 20, RED);
        } break;

        default:
        break;
    }
}

void CloseGame()
{
}