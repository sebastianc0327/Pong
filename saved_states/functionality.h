int logBallMovement = 0;
//sets the direction of ball to move within these three different locations
enum moveTo {SLIGHTLY_STRAIGHT_ACROSS, TOP_WINDOW, BOTTOM_WINDOW};
moveTo projectedDirection;
//what direction ball is currently heading towards
enum currentDirection {UNKNOWN, LEFT, RIGHT};
currentDirection currentlyGoing  = UNKNOWN; 
//checks to see whether to continue going a specific direction or not
std::string continueDirection[2] = {"FALSE", "FALSE"};

//dicates the direction ball will move depending on the random value chosen
int chosenDirection()
{
    const int MAX_RANGE = 0, MINIMUM_RANGE = 2;
    int randomValue = GetRandomValue(MAX_RANGE, MINIMUM_RANGE);

    //decides on the direction ball will go upon collision with a rectangle
    switch(randomValue)
    {
        case 0:
            projectedDirection = SLIGHTLY_STRAIGHT_ACROSS;
        break;
        case 1:
            projectedDirection = TOP_WINDOW;
        break;
        case 2:
            projectedDirection = BOTTOM_WINDOW;
        break;
    } 
    return randomValue;
        
}

void actualBallMovement(float* ballX, float* ballY, float ballRadius, float ballSpeedX, float ballSpeedY, float rightRectangleX, float rightRectangleY, float leftRectangleX, float leftRectangleY, float rectangleWidth, float rectangleHeight, int screenWidth, int screenHeight, int counter)
{   

    switch(logBallMovement)
    {               
        //collision with ballY on screenHeight
        case 1:
            if(currentlyGoing == LEFT)
            {
                *ballY-= ballSpeedY;
                *ballX -= ballSpeedX;                
            }
            else if(currentlyGoing == RIGHT)
            {
                *ballY-= ballSpeedY;
                *ballX += ballSpeedX;                       
            }

        break;
        //collision with ballY on the 0 point of the y-axis
        case 2:
            if(currentlyGoing == LEFT)
            {
                *ballY += ballSpeedY;
                *ballX -= ballSpeedX;                
            }
            else if(currentlyGoing == RIGHT)
            {
                *ballY += ballSpeedY;
                *ballX += ballSpeedX;                       
            }
        break;
        //collision with left rectangle
        case 3:
            if(continueDirection[0] != "TRUE")
            {
                chosenDirection();
            }
            continueDirection[0] = "TRUE";
            //resetting back to "FALSE" for the 4th case
            continueDirection[1] = "FALSE";

            if(projectedDirection == SLIGHTLY_STRAIGHT_ACROSS)
            {
                //double the speed
                *ballX += ballSpeedX * 2.3;
                *ballY -= ballSpeedY / 2.3;
            }
            else if(projectedDirection == TOP_WINDOW)
            {
                *ballX += ballSpeedX;
                *ballY -= ballSpeedY;
            }
            else if(projectedDirection == BOTTOM_WINDOW)
            {
                *ballX += ballSpeedX;
                *ballY += ballSpeedY;
            }
            currentlyGoing =  RIGHT;  
        break;
        //collision with right rectangle
        case 4:
            if(continueDirection[1] != "TRUE")
            {
                chosenDirection();
            }
            continueDirection[1] = "TRUE";
            //resetting back to "FALSE" value for the 3rd case
            continueDirection[0] = "FALSE";

            if(projectedDirection == SLIGHTLY_STRAIGHT_ACROSS)
            {
                *ballX -= ballSpeedX * 2.3;
                *ballY += ballSpeedY / 2.3;
            }
            else if(projectedDirection == TOP_WINDOW)
            {
                *ballX -= ballSpeedX;
                *ballY -= ballSpeedY;
            }
            else if(projectedDirection == BOTTOM_WINDOW)
            {
                *ballX -= ballSpeedX;
                *ballY += ballSpeedY;
            }
            currentlyGoing = LEFT;
        break;           
        default:
            //if logBallMovement is still assigned the value 0, execute the default case code 
            *ballX -= ballSpeedX;
    }
    
    if(*ballY + ballRadius >= screenHeight)
    {
        //collision with screenHeight
        logBallMovement = 1;
        //reset ballY's position
        *ballY = screenHeight - ballRadius;

    }

    else if(*ballY <= 0)
    {
        //collision with top border
        logBallMovement = 2;
        //reset ballY's position
        *ballY = 0;

    }
     
   else if(*ballX <= leftRectangleX + rectangleWidth && *ballY + ballRadius >= leftRectangleY && *ballY - ballRadius / 2 <= leftRectangleY + rectangleHeight)
    {   //collision with left rectangle
        logBallMovement = 3;
        //reset ballX's position
        *ballX = leftRectangleX + rectangleWidth + ballRadius;
    }
    else if(*ballX + ballRadius >= rightRectangleX && *ballY + ballRadius >= rightRectangleY && *ballY - ballRadius / 2 <= rightRectangleY + rectangleHeight)
    {
        //collision with right rectangle
        logBallMovement = 4;
        //reset ballX's position
        *ballX = rightRectangleX - ballRadius;
    }
    else if(counter == 50)
    {
        logBallMovement = 0;
    }
    
}
    bool wonGame(int* leftRectangleScored, int* rightRectangleScored, int screenWidth, int screenHeight)
    {   
        //leftRectangle wins game
        if(*leftRectangleScored == 10)
        {
            DrawText("YOU WIN!", screenWidth / 2 - screenWidth / 2 / 2, screenHeight / 2 / 2, 50, WHITE);
            DrawText("NOPE", screenWidth / 2 + screenWidth / 2 / 2, screenHeight / 2 / 2, 50, WHITE);
            //reset game
            *leftRectangleScored = 0;
            *rightRectangleScored = 0;
            return true;
        }
        //AI wins game
        else if(*rightRectangleScored == 10)
        {
            DrawText("YOU WIN!", screenWidth / 2 + screenWidth / 2 / 2, screenHeight / 2 / 2, 50, WHITE);
            DrawText("NOPE", screenWidth / 2 - screenWidth / 2 / 2, screenHeight / 2 / 2, 50, WHITE);
            //reset game
            *leftRectangleScored = 0;
            *rightRectangleScored = 0;
            return true;
        }

        return false;

        
        
    }