#pragma once
#include "../../../third_party/raylib.h"
#include "../objects/player.h"
#include "../objects/robot.h"
#include "../objects/ball.h"

bool running()
{ 
    BeginDrawing();
        DrawFPS(0, 0);

        ClearBackground(BLACK);

        leftRectangle.movement();
        rightRectangle.movement(ball.x, ball.y, ball.radius, &rightRectangle.y, rightRectangle.height, rightRectangle.speedY);

        // leads movement and collision detection for ball
        ballMovement(&ball.x, &ball.y, ball.radius, ball.speedX, ball.speedY, rightRectangle.x, rightRectangle.y, leftRectangle.x, leftRectangle.y, leftRectangle.width, leftRectangle.height, screenWidth, screenHeight);

        // player
        DrawRectangle(leftRectangle.x, leftRectangle.y, leftRectangle.width, leftRectangle.height, leftRectangle.color);
        // robot
        DrawRectangle(rightRectangle.x, rightRectangle.y, rightRectangle.width, rightRectangle.height, rightRectangle.color);
        // line in the middle of the window
        DrawRectangle(screenWidth / 2, 0, 5, screenHeight, WHITE);
        DrawCircle(ball.x, ball.y, ball.radius, ball.color);
        DrawText(TextFormat("%i", leftRectangle.score), screenWidth / 2 - screenWidth / 2 / 2, screenHeight / 3 - screenHeight / 2 / 2, 30, WHITE);
        DrawText(TextFormat("%i", rightRectangle.score), screenWidth / 2 + screenWidth / 2 / 2, screenHeight / 3 - screenHeight / 2 / 2, 30, WHITE);
    EndDrawing();
    if (ball.x > screenWidth || ball.x < 0)
    {
        if (ball.x > screenWidth)
        {
            leftRectangle.score++;
        }
        else if (ball.x < 0)
        {
            rightRectangle.score++;
        }
    }
    if (logBallMovement == 5)
    {
        // reset the movement of ball
        logBallMovement = 0;
        // exit run() due to ball being out of bounds
        return false;
    }
    return true;
}
