#include <iostream>
extern const int screenWidth = 1200;
extern const int screenHeight = 750;
#include "../lib/game_states/running.h"
#ifdef MAX_TIME
    #undef MAX_TIME
#endif
#include "../lib/game_states/reset.h"
#include "../lib/game_states/ended.h"

/*
    Note: In order to avoid having to constantly keep on calling BeginDrawing() and EndDrawing(), I decided for the code to be all
    within those two functions.
*/

int main(void)
{
    SetTargetFPS(60);

    InitWindow(screenWidth, screenHeight, "PingPong");
    bool isRunning = true, isResetting = false;

    HideCursor();
    while(!WindowShouldClose())
    {
        if(isRunning)
        {
            isRunning = running();
        }
        else
        {
            reset();
            isRunning = true;
        
        }
        if(ended());
        
    }
    CloseWindow();       

    return 0;
}
