#include "raylib.h"
#include "player.h"

#define SCREEN_WIDTH 960
#define SCREEN_HEIGHT 540

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Kingdom of Echoes");

    SetTargetFPS(60);

    Player player;
    InitPlayer(&player);

    while (!WindowShouldClose())
    {
        // Update
        UpdatePlayer(&player);

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawPlayer(&player);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}