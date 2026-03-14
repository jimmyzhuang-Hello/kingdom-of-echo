#ifndef MENU_H
#define MENU_H

#include "raylib.h"

// Function declarations for menu
void InitMenu();
void UpdateMenu();
void DrawMenu();

// Define button structure to handle button state and actions
typedef struct {
    Rectangle rect;
    const char *text;
    void (*action)(void);  // Function pointer for button actions
} Button;

// Declare the buttons
extern Button startButton;
extern Button continueButton;
extern Button helpButton;
extern Button quitButton;

// Helper functions for button actions
void StartAction();
void ContinueAction();
void HelpAction();
void QuitAction();

#endif