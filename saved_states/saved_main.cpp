#include <iostream>
#include "../../third_party/raylib.h"
#include <string>
#include "functionality.h"
#include <vector>
#define CORRECT_NUMBER 1


int screenWidth = 1200;
int screenHeight = 750;

int main(void)
{
    SetTargetFPS(60);

    //Ball attributes 
    class Ball
    {
        public:

            float x = screenWidth / 2;
            float y = screenHeight / 2;
            int radius = 15; 
            float speedX = 15;
            float speedY = 12;
    };


    //object declaration
    Ball ball;

    //rectangle attributes 
    class RightRectangle   
    {
        private:
        //range used to find success or not in probability
        std::vector<int> range = {1,1};

            //if true, collision with ball will occur, if false, it will not
            bool probability(std::vector<int>& range, float ballX)
            {
                const int MAX_RANGE = 10, RESET_RANGE = 1;
                const int MINIMUM_TIME_PASSED = 10;
                int time = GetTime();
                int probability = GetRandomValue(range[0], range[1]);

                //only try to find the probability if this condition is true 
                if(ballX >= screenWidth / 2 && time >= MINIMUM_TIME_PASSED)
                {                                   
                     std::cout << range[1] << std::endl;


                    if(probability == CORRECT_NUMBER)
                    {
                        range[1]++;
                        if(range[1] == MAX_RANGE)
                        {
                            range[1] = RESET_RANGE;
                        }
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    //return true to keep on functioning as intended
                    return true;
                }
            }
        public:

            //DO NOT ADJUST RECTANGLE ATTRIBUTES BESIDES WIDTH. You can still adjust screenHeight or screenWidth and it will follow proportionately.
            float width = 15.0F;
            float height = screenHeight / 5.0F; //height is 20% of screenHeight. It will always adjust proportionate to screenHeight.
            //leftRectangle.x position is directly opposite to rightRectangle.x, and it will adjust proportionately to screenWidth.
            float x = screenWidth - width; 
            float y = (screenHeight / 2) - (height / 2); //adjusts proportionately to screenHeight
            float speedY = 18;
            int score = 0;               

            void movement(float ballX, float ballY, int ballRadius, float *rectangleY, float rectangleHeight, float rectangleSpeedY)
            {
               // bool chance = probability(range, ballX);
               /* if(chance)
                { */
                    if(ballY + ballRadius > *rectangleY + rectangleHeight && ballX <= screenWidth)
                    {
                        *rectangleY += rectangleSpeedY;
                    }
                    else if(ballY - ballRadius < *rectangleY && ballX <= screenWidth)
                    {
                        *rectangleY -= rectangleSpeedY;
                    }
                //}

                if(y + height >= screenHeight)
                {
                    y = screenHeight - height;
                }
                if(y <= 0)
                {
                    y = 0;
                }
            }                    
    };
    
    RightRectangle rightRectangle;

    class LeftRectangle
    {
        public:
            //DO NOT ADJUST RECTANGLE ATTRIBUTES BESIDES WIDTH. You can still adjust screenHeight or screenWidth and it will follow proportionately.
            float width = 15.0F;
            float height = screenHeight / 5.0F;    //height is 20% of screenHeight. It will always adjust proportionate to screenHeight.
            //rightRectangle.x position is directly opposite to leftRectangle.x, and it will adjust proportionately to screenWidth.
            float x = 0; 
            float y = (screenHeight / 2) - (height / 2);   //adjusts proportionately to screenHeight.
            float speedY = 10;
            int score = 0;

            void movement()
            {
                if(IsKeyDown(KEY_DOWN))
                {
                    y += speedY;
                }
                else if(IsKeyDown(KEY_UP))
                {
                    y -= speedY;
                }

                if(y + height >= screenHeight)
                {
                    y = screenHeight - height;
                }
                if(y <= 0)
                {
                    y = 0;
                }                
            }

    };
    
    LeftRectangle leftRectangle;


    InitWindow(screenWidth, screenHeight, "PingPong");
    //used as a way to 
    int counter = 0;
    HideCursor();
    while(!WindowShouldClose())
    {  
        BeginDrawing();
            DrawFPS(0,0);
            ClearBackground(BLACK);
        /*
            for(int i = 0; i <= screenWidth; i += 25)
            {
                DrawRectangle(i,0, 1, screenHeight, RAYWHITE);
                
                for(int z = 0; z <= screenHeight; z += 25)
                {
                    if(i == 0)
                    {
                        DrawRectangle(1,z, screenWidth, 1, RAYWHITE);
                    }
                }
            } 
        */
            bool isGameWon = wonGame(&leftRectangle.score, &rightRectangle.score, screenWidth, screenHeight);

            leftRectangle.movement();
            rightRectangle.movement(ball.x, ball.y, ball.radius, &rightRectangle.y, rightRectangle.height, rightRectangle.speedY);
            if(counter == 0 || counter == 50)
            {
                actualBallMovement(&ball.x, &ball.y, ball.radius, ball.speedX, ball.speedY, rightRectangle.x, rightRectangle.y, leftRectangle.x, leftRectangle.y, leftRectangle.width, leftRectangle.height, screenWidth, screenHeight, counter);
                counter = 0;
            }

            
            DrawRectangle(leftRectangle.x, leftRectangle.y, leftRectangle.width, leftRectangle.height, RAYWHITE);
            DrawRectangle(rightRectangle.x, rightRectangle.y, rightRectangle.width, rightRectangle.height, RAYWHITE);
            DrawRectangle(screenWidth / 2, 0, 5, screenHeight, WHITE);
            DrawCircle(ball.x, ball.y, ball.radius, ORANGE);
            DrawText(TextFormat("%i" ,leftRectangle.score), screenWidth / 2 - screenWidth / 2 / 2, screenHeight / 3 - screenHeight / 2 / 2, 30, WHITE);
            DrawText(TextFormat("%i" ,rightRectangle.score), screenWidth / 2 + screenWidth / 2 / 2, screenHeight / 3 - screenHeight / 2 / 2, 30, WHITE);



        EndDrawing();



        if(ball.x > screenWidth || ball.x < 0 || counter > 0)
        {
            counter++;
            if(ball.x > screenWidth && counter == 1)
            {
                leftRectangle.score++;
            }
            else if(ball.x < 0 && counter == 1)
            {
                rightRectangle.score++;
            }
            ball.x = screenWidth / 2;
            ball.y = screenHeight / 2;
        }
    }
    CloseWindow();       

    return 0;
}
