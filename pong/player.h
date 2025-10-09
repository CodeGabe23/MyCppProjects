#pragma once
#include "stuff.h"

struct Player {
    float posX;
    float posY;
    bool canMove;
    int score;
    Rectangle rect;
};

void InitPlayer(Player& player, float x, float y);
void UpdatePlayer(Player& player, int upKey, int downKey, double speed);
