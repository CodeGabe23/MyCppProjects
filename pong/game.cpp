#include "game.h"
#include "stuff.h"
#include "player.h"
#include "ball.h"

// Textures
Texture2D bgImg;
Texture2D leftTexture;
Texture2D rightTexture;
Texture2D ballTexture;

static Player leftPlayer;
static Player rightPlayer;
static Ball ball;
static double playerSpeed = 0.1;

void InitGame() {
    InitWindow(SCREENWIDTH, SCREENHEIGHT, "Gabriel's Pong");

    // Initialize players and ball
    InitPlayer(leftPlayer, SCREENWIDTH / 10.0f, SCREENHEIGHT / 2.5f);
    InitPlayer(rightPlayer, SCREENWIDTH / 1.1f, SCREENHEIGHT / 2.5f);
    InitBall(ball, SCREENHEIGHT / 1.5f, SCREENWIDTH / 3.0f);

    // Load textures
    bgImg = LoadTexture("images/bomboclat.png");
    leftTexture = LoadTexture("images/playerPaddle.png");
    rightTexture = LoadTexture("images/playerPaddle.png");
    ballTexture = LoadTexture("images/ball.png");
}

void UpdateGame() {
    UpdatePlayer(leftPlayer, KEY_W, KEY_S, playerSpeed);
    UpdatePlayer(rightPlayer, KEY_UP, KEY_DOWN, playerSpeed);
    UpdateBall(ball, leftPlayer, rightPlayer);
}

void DrawGame() {
    BeginDrawing();
    ClearBackground(BLACK);

    DrawTexture(bgImg, SCREENWIDTH / 2.7, 0, WHITE);
    DrawTextureEx(ballTexture, { ball.posX, ball.posY }, 0.0f, 0.5f, WHITE);
    DrawTexture(leftTexture, leftPlayer.posX, leftPlayer.posY, PURPLE);
    DrawTexture(rightTexture, rightPlayer.posX, rightPlayer.posY, PURPLE);

    DrawText(TextFormat("%d", leftPlayer.score), 400, 100, 50, GREEN);
    DrawText(TextFormat("%d", rightPlayer.score), 1200, 100, 50, GREEN);

    EndDrawing();
}

void UnloadGame() {
    UnloadTexture(bgImg);
    UnloadTexture(leftTexture);
    UnloadTexture(rightTexture);
    UnloadTexture(ballTexture);

    CloseWindow();
}

bool ShouldCloseGame() {
    return WindowShouldClose();
}
