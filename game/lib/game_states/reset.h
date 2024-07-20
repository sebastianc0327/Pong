#pragma once
#include "../objects/ball.h"
#define MAX_TIME 50

void reset()
{
        if(rightRectangle.score != 10 || leftRectangle.score != 10)
        {
                for (int i = 0; i < MAX_TIME; i++)
                {
                        ball.x = screenWidth / 2;
                        ball.y = screenHeight / 2;
                        BeginDrawing();
                        ClearBackground(BLACK);

                        // allows player to still move
                        leftRectangle.movement();
                        // allows robot to still move
                        rightRectangle.movement(ball.x, ball.y, ball.radius, &rightRectangle.y, rightRectangle.height, rightRectangle.speedY);
                        // line in the middle of the window
                        DrawRectangle(screenWidth / 2, 0, 5, screenHeight, WHITE);
                        // draw player
                        DrawRectangle(leftRectangle.x, leftRectangle.y, leftRectangle.width, leftRectangle.height, leftRectangle.color);
                        // draw robot
                        DrawRectangle(rightRectangle.x, rightRectangle.y, rightRectangle.width, rightRectangle.height, rightRectangle.color);

                        DrawText(TextFormat("%i", leftRectangle.score), screenWidth / 2 - screenWidth / 2 / 2, screenHeight / 3 - screenHeight / 2 / 2, 30, WHITE);
                        DrawText(TextFormat("%i", rightRectangle.score), screenWidth / 2 + screenWidth / 2 / 2, screenHeight / 3 - screenHeight / 2 / 2, 30, WHITE);

                        DrawCircle(ball.x, ball.y, ball.radius, ORANGE);
                        EndDrawing();
                }
        }
}