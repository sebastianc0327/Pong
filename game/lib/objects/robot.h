#pragma once
#include <iostream>
#include "../../../third_party/raylib.h"
#include <vector>
#define CORRECT_NUMBER 1


class RightRectangle
{
private:
    // range used to find success or not in probability
    std::vector<int> range = {1, 1};
    bool rollProbability = true;
    bool willHitBall = true;
    int time;
    int counter = 0;
    // if true, collision with ball will occur, if false, it will not
    bool probability(std::vector<int> &range, float ballX, int* time)
    {
        const int MAX_RANGE = 40, RESET_RANGE = 1;
        const int MINIMUM_TIME_PASSED = 10;
        //used because after a specific amount of time, you want to increase the game's difficulty
        *time = GetTime();
        int randomValue = GetRandomValue(range[0], range[1]);

        // only try to find the probability if this condition is true
        if (ballX >= screenWidth / 2 && *time >= MINIMUM_TIME_PASSED)
        {
            std::cout << range[1] << std::endl;

            if (randomValue == CORRECT_NUMBER && *time % 9 == 0)
            {
                //decreases the likelyhood of probability
                range[1]++;
                if (range[1] == MAX_RANGE)
                {
                    //resets range so probability won't be too low
                    range[1] = RESET_RANGE;
                }
                return true;
            }
            else if (randomValue == CORRECT_NUMBER && *time % 9 != 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            // return true to keep on functioning as intended
            return true;
        }
    }

public:
    // DO NOT ADJUST RECTANGLE ATTRIBUTES BESIDES WIDTH. You can still adjust screenHeight or screenWidth and it will follow proportionately.
    float width = 15.0F;
    float height = screenHeight / 5.0F; // height is 20% of screenHeight. It will always adjust proportionate to screenHeight.
    // leftRectangle.x position is directly opposite to rightRectangle.x, and it will adjust proportionately to screenWidth.
    float x = screenWidth - width;
    float y = (screenHeight / 2) - (height / 2); // adjusts proportionately to screenHeight
    float speedY = 18;
    int score = 0;
    Color color = WHITE;

    void movement(float ballX, float ballY, int ballRadius, float *rectangleY, float rectangleHeight, float rectangleSpeedY)
    {
        if(rollProbability == true)
        {
            willHitBall = probability(range, ballX, &time);
        }

        if((counter == 0 && willHitBall == true) || *rectangleY > rectangleHeight || *rectangleY < screenHeight - rectangleHeight)
        {
            if(*rectangleY <= rectangleHeight || *rectangleY >= screenHeight - rectangleHeight)
            {
                rollProbability = true;
            }
            if (ballY + ballRadius > *rectangleY + rectangleHeight && ballX <= screenWidth)
            {
                *rectangleY += rectangleSpeedY;
            }
            else if (ballY - ballRadius < *rectangleY && ballX <= screenWidth)
            {
                *rectangleY -= rectangleSpeedY;
            }
        }
        else
        {
            counter++;
        }
        if(counter == 10)
        {
            counter++;
        }
        if (y + height >= screenHeight)
        {
            y = screenHeight - height;
        }
        if (y <= 0)
        {
            y = 0;
        }
    }
};

RightRectangle rightRectangle;
