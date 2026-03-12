#include "player.h"

void InitPlayer(Player *player)
{
    player->position = (Vector2){400, 300};
    player->speed = 3.0f;
}

void UpdatePlayer(Player *player)
{
    if (IsKeyDown(KEY_W)) player->position.y -= player->speed;
    if (IsKeyDown(KEY_S)) player->position.y += player->speed;
    if (IsKeyDown(KEY_A)) player->position.x -= player->speed;
    if (IsKeyDown(KEY_D)) player->position.x += player->speed;
}

void DrawPlayer(Player *player)
{
    DrawRectangle(player->position.x, player->position.y, 32, 32, SKYBLUE);
}