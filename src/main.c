#include "raylib.h"
#include "game.h"

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Kingdom of Echoes");

    SetTargetFPS(60);

    InitGame();

    while (!WindowShouldClose())
    {
        // Update
        UpdateGame();

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawGame();

        EndDrawing();
    }
    CloseGame();
    CloseWindow();
    return 0;
}