#pragma once
#include "../objects/player.h"
#include "../objects/robot.h"

void resetScore()
{
    leftRectangle.score = 0;
    rightRectangle.score = 0;
}

//signals that the game is over
bool ended()
{    

    //leftRectangle wins game
    if(leftRectangle.score == 10)
    {
        while(!IsKeyPressed(KEY_ENTER))
        {
            BeginDrawing();
            ClearBackground(BLACK);
            DrawText("YOU WIN!", screenWidth / 2, screenHeight / 2, 250, WHITE);
            //reset game
            resetScore();
            EndDrawing();
        }
        return true;
    }
    //AI wins game
    else if(rightRectangle.score == 10)
    {
        while(!IsKeyPressed(KEY_ENTER))
        {
            BeginDrawing();
            ClearBackground(BLACK);
            DrawText("YOU LOSE", screenWidth / 2, screenHeight / 2, 25, WHITE);
            DrawText("Press ENTER to play again", screenWidth / 2 - 100, screenHeight / 2 + 100 , 25, WHITE);

            //reset game
            resetScore();
            EndDrawing();
        }
        return true;
    }            
    return false;     
}




