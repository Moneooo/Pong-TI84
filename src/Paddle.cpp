#include "Paddle.h"
#include <tice.h>
#include <stdlib.h>
#include <graphx.h>
#include <debug.h>
#include <keypadc.h>

Paddle::Paddle(int player) {
    speed = 125;
    height = 40;
    width = 5;

    playerIndex = player;
    position.y = 100;

    if (player == 1)
        position.x = 30;
    else
        position.x = GFX_LCD_WIDTH - 30 - width;
}

/* Draw the 8x8 ball at a specific coordinate. Coordinates of the ball sprite are top-left = (0, 0)*/
void Paddle::Draw()
{
    // gfx_sprite_t *behind_sprite = gfx_MallocSprite(BALL_DIAMETER, BALL_DIAMETER);
    // gfx_GetSprite(behind_sprite, x, y);

    gfx_SetColor(255);

    gfx_FillRectangle(position.x, position.y, width, height);
}

void Paddle::Update(float deltaTime)
{
    if (playerIndex == 2)
    {
        if (kb_Data[7] & kb_Up)
            position.y -= speed * deltaTime;
        else if (kb_Data[7] & kb_Down)
            position.y += speed * deltaTime;
    }
    else if (playerIndex == 1)
    {
        if (kb_Data[1] & kb_2nd)
            position.y -= speed * deltaTime;
        else if (kb_Data[2] & kb_Alpha)
            position.y += speed * deltaTime;
    }

    // Paddle bounds
    if (position.y < 0) {
        position.y = 0;
    }
    else if (position.y + height > GFX_LCD_HEIGHT) {
        position.y = GFX_LCD_HEIGHT - height;
    }
}