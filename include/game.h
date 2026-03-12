#ifndef GAME_H
#define GAME_H

#include "scene.h"

void InitGame();
void UpdateGame();
void DrawGame();
void CloseGame();

void ChangeScene(Scene newScene);

#endif