#include "ball.h"

void InitBall(Ball& ball, float x, float y) {
    ball.posX = x;
    ball.posY = y;
    ball.speedX = 0.2;
    ball.speedY = 0.2;
    ball.rect = { x, y, 100, 100 };
}

void UpdateBall(Ball& ball, Player& left, Player& right) {
    ball.posX += ball.speedX;
    ball.posY += ball.speedY;

    ball.rect = { ball.posX, ball.posY, 100, 100 };

    // Bounce vertically
    if (ball.posY > SCREENHEIGHT - 200 || ball.posY < 0)
        ball.speedY = -ball.speedY;

    // Bounce off paddles
    if (CheckCollisionRecs(ball.rect, left.rect) || CheckCollisionRecs(ball.rect, right.rect))
        ball.speedX = -ball.speedX;

    // Score handling
    if (ball.posX > SCREENWIDTH - 200) {
        left.score++;
        InitBall(ball, SCREENHEIGHT / 1.5f, SCREENWIDTH / 3.0f);
        ball.speedX = -ball.speedX;
    }
    if (ball.posX < 0) {
        right.score++;
        InitBall(ball, SCREENHEIGHT / 1.5f, SCREENWIDTH / 3.0f);
        ball.speedX = -ball.speedX;
    }
}
