#pragma once
#include "stuff.h"
#include "player.h"

struct Ball {
    float posX;
    float posY;
    double speedX;
    double speedY;
    Rectangle rect;
};

void InitBall(Ball& ball, float x, float y);
void UpdateBall(Ball& ball, Player& left, Player& right);
