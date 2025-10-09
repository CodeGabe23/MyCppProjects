#include "player.h"

void InitPlayer(Player& player, float x, float y) {
    player.posX = x;
    player.posY = y;
    player.canMove = true;
    player.score = 0;
    player.rect = { x, y, 25, 108 };
}

void UpdatePlayer(Player& player, int upKey, int downKey, double speed) {
    if (player.posY < 0) {
        player.posY += 0.01;
        player.canMove = false;
    }
    else if (player.posY > SCREENHEIGHT - 105) {
        player.posY -= 0.01;
        player.canMove = false;
    }
    else player.canMove = true;

    if (player.canMove) {
        if (IsKeyDown(upKey)) player.posY -= speed;
        if (IsKeyDown(downKey)) player.posY += speed;
    }

    player.rect = { player.posX, player.posY, 25, 108 };
}
