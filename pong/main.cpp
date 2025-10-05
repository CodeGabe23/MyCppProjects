#include "raylib.h"
#include <iostream>
#include <string>

//tryna make a Pong game solo with no help. just google.
//steps:
// 1. display background image (just for fun)
// 2. have 2 players. one on W/S and another on up/down arrow keys
// 3. make a ball that randomly moves at the start and handles collision
// 4. display score on each side
// 5. draw a line in the middle
// 6. end game when ball passes either player's paddle.
// 7. display winner


int main(void)
{
	const int SCREENWIDTH{ 1500 };
	const int SCREENHEIGHT{ 1000 };
	
	double playerSpeed{ 0.1 };

	float leftPlayerPosX{ SCREENWIDTH / 10 };
	float leftPlayerPosY{ SCREENHEIGHT / 2.5, };
	bool leftPlayerCanMove{ true };
	int leftPlayerScore{};
	Rectangle leftPlayerRectangle{ leftPlayerPosX , leftPlayerPosY, 25, 108 };

	float rightPlayerPosX{ SCREENWIDTH / 1.1 };
	float rightPlayerPosY{ SCREENHEIGHT / 2.5 };
	bool rightPlayerCanMove{ true };
	int rightPlayerScore{};
	Rectangle rightPlayerRectangle{ rightPlayerPosX , rightPlayerPosY, 25, 108 };

	double ballSpeedX{ 0.1 };
	double ballSpeedY{ 0.1 };
	float ballPosX{SCREENHEIGHT / 1.5};
	float ballPosY{SCREENWIDTH / 3};
	Rectangle ballRectangle{ballPosX, ballPosY, 200, 200};

	InitWindow(SCREENWIDTH, SCREENHEIGHT, "Gabe's Pong");
	//SetTargetFPS(60); this breaks the game;

	// Load textures
	Texture2D bgImg = LoadTexture("images/bomboclat.png");
	Texture2D leftPlayer = LoadTexture("images/playerPaddle.png");
	Texture2D rightPlayer = LoadTexture("images/playerPaddle.png");
	Texture2D ball = LoadTexture("images/ball.png");





	while (!WindowShouldClose())
	{
		BeginDrawing();

		ballPosX += ballSpeedX;
		ballPosY += ballSpeedY;

		// Updating rectangle positions for collision purposes
		leftPlayerRectangle={ leftPlayerPosX , leftPlayerPosY, 25, 108 };
		rightPlayerRectangle={ rightPlayerPosX , rightPlayerPosY, 25, 108 };
		ballRectangle={ ballPosX, ballPosY, 200, 200 };

		// Collisions detection: Check if ball is touching player
		if (CheckCollisionRecs(leftPlayerRectangle, ballRectangle) || CheckCollisionRecs(rightPlayerRectangle, ballRectangle))
		{
			ballSpeedX = -ballSpeedX;
		}


		//check if ball is on border;
		if (ballPosY > SCREENHEIGHT - 200 ) //checks if touching floor
		{
			ballSpeedY = -ballSpeedY;
		}
		if (ballPosY < 0) //checks if touching ceiling
		{
			//std::cout << "OUT OF MAP\n"; debugging
			ballSpeedY = -ballSpeedY;
		}
		if (ballPosX > SCREENWIDTH - 200) //checks if its touching right borders
		{
			leftPlayerScore++;
			ballPosX={ SCREENHEIGHT / 1.5 };
			ballPosY={ SCREENWIDTH / 3 };
			ballSpeedX = -ballSpeedX;
		}
		if (ballPosX < 0) //checks if its touching left borders
		{
			rightPlayerScore++;
			ballPosX = { SCREENHEIGHT / 1.5 };
			ballPosY = { SCREENWIDTH / 3 };
			ballSpeedX = -ballSpeedX;
		}

		// check if players are allowed to move (if they are within screen borders)
		//left player
		if (leftPlayerPosY < 0) 
		{
			leftPlayerPosY += 0.01;
			leftPlayerCanMove = false;
		} 
		else if (leftPlayerPosY > SCREENHEIGHT - 105)
		{
			leftPlayerPosY -= 0.01;
			leftPlayerCanMove = false;
		}
		else leftPlayerCanMove = true;

		//right player
		if (rightPlayerPosY < 0 )
		{
			rightPlayerPosY += 0.01;
			rightPlayerCanMove = false;
		}
		else if (rightPlayerPosY > SCREENHEIGHT - 105)
		{
			rightPlayerPosY -= 0.01;
			rightPlayerCanMove = false;
		}
		else rightPlayerCanMove = true;

		//get player's input
		
		//TESTING:
		// moving ball
		if (IsKeyDown(KEY_T)) ballPosY -= ballSpeedY;
		if (IsKeyDown(KEY_G)) ballPosY += ballSpeedY;
		if (IsKeyDown(KEY_F)) ballPosX -= ballSpeedX;
		if (IsKeyDown(KEY_H)) ballPosX += ballSpeedX;

		//left player
		if (leftPlayerCanMove)
		{
			if (IsKeyDown(KEY_W))leftPlayerPosY -= playerSpeed;
			if (IsKeyDown(KEY_S))leftPlayerPosY += playerSpeed;
		}
		
		//right player
		if (rightPlayerCanMove)
		{
			if (IsKeyDown(KEY_UP))rightPlayerPosY -= playerSpeed;
			if (IsKeyDown(KEY_DOWN))rightPlayerPosY += playerSpeed;
		}

		//draw FPS in top left
		std::string fps = std::to_string(GetFPS());
		const char* cfps = fps.c_str();
		DrawText(cfps, 0, 0, 22, BLUE); // show fps

		//display background and ball
		DrawTexture(bgImg, SCREENWIDTH / 2.7, 0, WHITE); // WHITE is for no tint btw
		DrawTexture(ball, ballPosX, ballPosY, WHITE);

		// draw players
		DrawTexture(leftPlayer, leftPlayerPosX, leftPlayerPosY, PURPLE);
		DrawTexture(rightPlayer, rightPlayerPosX, rightPlayerPosY, PURPLE);

		// draw player score
		DrawText(TextFormat("%d", leftPlayerScore), 400, 100, 50, GREEN);
		DrawText(TextFormat("%d", rightPlayerScore), 1200, 100, 50, GREEN);


		ClearBackground(BLACK);
		EndDrawing();
	}

	CloseWindow();

	return 0;
}
