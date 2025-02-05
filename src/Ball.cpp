#include "Ball.h"
#include <tice.h>
#include <stdlib.h>
#include <graphx.h>
#include <debug.h>

Ball::Ball() {
    position.x = 120;
    position.y = 80;
    speed = 100;
    baseSpeed = 125;
    radius = 5;

    xDir = 1;
    yDir = 1;
}

/* Draw the 8x8 ball at a specific coordinate. Coordinates of the ball sprite are top-left = (0, 0)*/
void Ball::Draw()
{
    gfx_SetColor(255);
    gfx_FillCircle(position.x, position.y, radius / 2);
}

// Update returns 0 for no point, 1 for player1 scored, 2 for player2 scored, 3 for paddle hit
int Ball::Update(float deltaTime, Vector2 player1Pos, Vector2 player2Pos)
{
    position.x += xDir * (speed * deltaTime);
    position.y += yDir * (speed * deltaTime);

    if (position.y <= 0 || position.y >= GFX_LCD_HEIGHT) {
        yDir *= -1;
    }

    // Ball collision with paddles
    if (position.x <= player1Pos.x + 5 && position.y >= player1Pos.y && position.y <= player1Pos.y + 40) {
        xDir = 1;
        return 3;
    }
    if (position.x >= player2Pos.x && position.y >= player2Pos.y && position.y <= player2Pos.y + 40) {
        xDir = -1;
        return 3;
    }

    // Ball out of bounds, player scored
    if (position.x <= 0)
        return 2;
    else if (position.x >= GFX_LCD_WIDTH)
        return 1;
    
    return 0;
}

void Ball::Reset()
{
    position.x = 120;
    position.y = 80;
    
    int randX = randInt(0, 1);
    int randY = randInt(0, 1);

    xDir = randX == 1 ? 1 : -1;
    yDir = randY == 1 ? 1 : -1;

    speed = baseSpeed;
}