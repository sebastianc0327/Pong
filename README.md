
Project:
    Create a function called ballMovement() and have it encased within a switch statement in main.cpp. ballMovement shoud return a string with 4 possible variations. These should be the possible variations:
        
        1. "TOUCHING_FLOOR"
        2. "TOUCHING_ROOF"
        3. "TOUCHING_LEFT_RECTANGLE"
        4. "TOUCHING_RIGHT_RECTANGLE"

    Each case should have a functionality for ball's movement by using either the reverseMovement() or updateMovement() functions. Also, there should be a variable called:

        string logBallMovement;
    
    which stores the last returned value for ballMovement(). This should be in place so that the ball keeps moving in that specific direction. 

    If the next move were to cause ball to go out of bounds, set ball's position that is about to go out of bounds to the nearest out of bounds barrier. This should be done before returning any value besides in the "else" section in ballMovement.
TODO:
- Make it so there are two different functions for two different types of movement. The x and y coordinates should not be faster than double the amount of each other. For example, if the x is 20, then the y can be no more than 40 because it would lead to the ball having strange movement. One function for movement should be used to move the ball at the start. Then, the positions of x and y should use the GetRandomValue function to update the movement of the ball upon collision. GetRandomValue should only be utilized upon collisions which means that ball's movement should stick to whatever the random value was.

- Reset ball's position to the position found in the object it collided with so ball doesn't ever go out of bounds. A predictive collision system would have to be implemented to do so. COMPLETED TASK
- Implement the AI for the right rectangle object. There two ways to go about this are as follows:
    
     1. The more complex way would be to have a percentage decreasing as the time passes on in the game that symbolizes the AI's ability to hit the ball. It would accomplish this by having rightRectangle collide with ball at around a 97% probability of the time to start off. Then, the percentage should begin to decrease with a cap limit of around 40% as the game begins to drag on. So, if the probability for ball not to collide with rightRectangle is the one that ends up becoming true, rightRectangle should miss colliding with ball by some amount in it's y-axis.
     2. A simpler way would be to have ball's movement increase with every collision. By doing so, an implementation can be made so rightRectangle only begins tracking ballY's movement once ballX => screenWidth. Of course, since rightRectangle has a set amount of speed it can treverse on the y-axis, it can catch up to ball only for a specific duration due to ball's speed eventaully becoming greater than rightRectangleY's speed. There should be a formula made in order to calculate at what point specifically in the game rightRectangleY's speed would be less than ball's movement, thus, being unable to catch up to ball and have a point scored for the player. 
    
- Use GetRandomValue() with the paramaters being mallabe depending on the chance of the AI not being able to collide with ball. The parameters should become a greater range of values as the game drags on. If the GetRandomVale() function returns the single value specified, the AI should be able to collide with ball. 
- Create 3 different scenarios of movement for ball upon collision with right or left rectangle. These 3 scenarios will be chosen depending on the value returned by GetRandomValue. The returned value should be stored in a variable called chosenMovement. Then, create a case where if chosenMovement equals to a specific case, have ball's direction be implemented as such. 
- Change the name of ballMovement() and actualBallMovement() to their corresponding functionality.
- Fix error that's making ball's movement undefined. It has to do with projectedDirection being assigned a random value each time it's called. It should only be called once per collision and have the direction stay the same until another collision occurs between ball and rectangle. The implementation should be something along the lines of having an array called std::string continuePredictedDirection[2] with the intial values be intialized to "FALSE". There should be an if() statement checking to see if the value had since been updated to "TRUE". If it has, then don't call the chosenDirection() function again until another collision occurs between ball and rectangle. There should also be a for() loop resetting the values within continuePredictedDirection back to "FALSE" once a new collision occurs. -------------COMPLETED
- Make it so there's a way for the AI to lose. Also, fix the collision detection system because ball is going through right rectangle even though it's supposed to be colliding. This image showcases this: ![alt text](image.png)
- There's an issue where ball is still going through left rectangle, and altough it's not visibly happening to rightRectangle, it will occur should the speed of ball be increased significantly. There should be no instances where ball can be shown to go through any rectangle. The solution is to not have ball be drawn if it's going to hit left rectangle at all. This should also prevent any issues arising with increasing the ball's movement because for the player, it would seem like it went out of bounds. You would do this by implementing a predictive collision system.
-rightRectangle's speed got changed so it's different than leftRectangle. Make sure to change it back whenever a predictive AI is made. I say this because it's the only way to have the AI catch up to ball if the speed is kept unchanged as leftRectangle is.
- Create three different game states. One for when ball is reset and a player scores a point (called reset), another where the ball begins it's movement (called run), and the last one where a player has acheived scoring 10 points to end off the game (called finished). In the finished gamestate, there should be a pop up prompting the user to either play again, or exit the game.
- add some preprocessor statements such as if define, etc. in order to avoid reusing the raylib.h library more than once. Also, remove most of the include preprocessor statements found in main.cpp in order to make main.cpp have the least amount of clutter possible. 
- Find a way to move the contents within functionality.h to the ball.h file.