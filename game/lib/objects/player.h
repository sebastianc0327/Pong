#pragma once
class LeftRectangle
{
public:
    // DO NOT ADJUST RECTANGLE ATTRIBUTES BESIDES WIDTH. You can still adjust screenHeight or screenWidth and it will follow proportionately.
    float width = 15.0F;
    float height = screenHeight / 5.0F; // height is 20% of screenHeight. It will always adjust proportionate to screenHeight.
    // rightRectangle.x position is directly opposite to leftRectangle.x, and it will adjust proportionately to screenWidth.
    float x = 0;
    float y = (screenHeight / 2) - (height / 2); // adjusts proportionately to screenHeight.
    float speedY = 10;
    int score = 0;
    Color color = WHITE;

        void movement()
    {
        if (IsKeyDown(KEY_DOWN))
        {
            y += speedY;
        }
        else if (IsKeyDown(KEY_UP))
        {
            y -= speedY;
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

LeftRectangle leftRectangle;
