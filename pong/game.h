#pragma once
#include "raylib.h"

void InitGame();
void UpdateGame();
void DrawGame();
void UnloadGame();
bool ShouldCloseGame();

// Textures
extern Texture2D bgImg;
extern Texture2D leftTexture;
extern Texture2D rightTexture;
extern Texture2D ballTexture;
