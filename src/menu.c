#include "menu.h"
#include "raylib.h"
#include "game.h"

static Texture2D background;  // For the background image

// Buttons
Button startButton;
Button continueButton;
Button helpButton;
Button quitButton;

// Initialize menu and buttons
void InitMenu()
{
    // Load the background image
    background = LoadTexture("assets/menu.jpg");

    // Set up the buttons (positioned vertically in the center)
    float buttonWidth = 200;
    float buttonHeight = 50;
    float buttonX = (GetScreenWidth() - buttonWidth) / 2;
    
    // Initialize the buttons with rectangles and actions
    startButton = (Button){(Rectangle){buttonX, 400, buttonWidth, buttonHeight}, "Start", StartAction};
    continueButton = (Button){(Rectangle){buttonX, 470, buttonWidth, buttonHeight}, "Continue", ContinueAction};
    helpButton = (Button){(Rectangle){buttonX, 540, buttonWidth, buttonHeight}, "Help", HelpAction};
    quitButton = (Button){(Rectangle){buttonX, 610, buttonWidth, buttonHeight}, "Quit", QuitAction};
}

// Update button states (click detection)
void UpdateMenu()
{
    // Detect if buttons are pressed
    if (CheckCollisionPointRec(GetMousePosition(), startButton.rect) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        startButton.action();
    if (CheckCollisionPointRec(GetMousePosition(), continueButton.rect) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        continueButton.action();
    if (CheckCollisionPointRec(GetMousePosition(), helpButton.rect) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        helpButton.action();
    if (CheckCollisionPointRec(GetMousePosition(), quitButton.rect) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        quitButton.action();
}

// Draw the menu (background and buttons)
void DrawMenu()
{
    // Draw the background image
    DrawTexture(background, 0, 0, WHITE);

    // Draw each button (with hover effect)
    DrawRectangleRec(startButton.rect, CheckCollisionPointRec(GetMousePosition(), startButton.rect) ? LIGHTGRAY : GRAY);
    DrawText(startButton.text, startButton.rect.x + 50, startButton.rect.y + 15, 20, DARKGRAY);

    DrawRectangleRec(continueButton.rect, CheckCollisionPointRec(GetMousePosition(), continueButton.rect) ? LIGHTGRAY : GRAY);
    DrawText(continueButton.text, continueButton.rect.x + 50, continueButton.rect.y + 15, 20, DARKGRAY);

    DrawRectangleRec(helpButton.rect, CheckCollisionPointRec(GetMousePosition(), helpButton.rect) ? LIGHTGRAY : GRAY);
    DrawText(helpButton.text, helpButton.rect.x + 50, helpButton.rect.y + 15, 20, DARKGRAY);

    DrawRectangleRec(quitButton.rect, CheckCollisionPointRec(GetMousePosition(), quitButton.rect) ? LIGHTGRAY : GRAY);
    DrawText(quitButton.text, quitButton.rect.x + 50, quitButton.rect.y + 15, 20, DARKGRAY);
}

// Start button action - switch to explore scene
void StartAction()
{
    ChangeScene(SCENE_EXPLORE);
}

// Continue button action - currently does nothing, can be added later
void ContinueAction()
{
    // Placeholder for future save/load system
}

// Help button action - show instructions
void HelpAction()
{
    // Show instructions in a rectangle
    DrawRectangle(200, 150, 1520, 800, Fade(GRAY, 0.7f)); // Semi-transparent background
    DrawText("This is the help screen. Here you will find instructions on how to play the game.", 250, 200, 30, WHITE);
    DrawText("Press ESC to return to the menu.", 250, 250, 20, WHITE);
}

// Quit button action - close the window
void QuitAction()
{
    CloseWindow();  // This will close the window and end the game
}