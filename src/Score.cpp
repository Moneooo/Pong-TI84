#include <graphx.h>

#include "Score.h"

#include <debug.h>

Score::Score()
{
    player1Score = 0;
    player2Score = 0;
}

void Score::addScore(int playerIndex)
{
    if (playerIndex == 1)
        player1Score++;
    else
        player2Score++;
}

void Score::Draw()
{
    gfx_SetTextFGColor(255);
    gfx_SetTextBGColor(0);
    gfx_SetTextTransparentColor(5);

    gfx_SetTextXY(126, 5);
    gfx_PrintInt(player1Score, 2);

    gfx_Rectangle(159, 2, 2, 20);

    gfx_SetTextXY(164, 5);
    gfx_PrintInt(player2Score, 2);
}