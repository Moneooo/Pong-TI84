#include <stdlib.h>
#include <graphx.h>
#include <tice.h>
#include <keypadc.h>
#include <debug.h>

#include "Ball.h"
#include "Paddle.h"
#include "Score.h"

/* Helper functions declarations*/
void PrintCentered(const char *str, int offsetX, int offsetY);

Ball *ball = new Ball();
Paddle *player1 = new Paddle(1);
Paddle *player2 = new Paddle(2);
Score *scoreboard = new Score();

int didScore = 0;

// By how much the game gets faster after each paddle hit (2x for every score)
const int GAME_SPEED_ADDITION = 1;

void begin(){
    // Enable a timer and start the real-time clock (rtc). Used for deltaTime calculation
    timer_Enable(1, TIMER_32K, TIMER_NOINT, TIMER_UP);
    rtc_Enable(0);

    // Make a new random seed based off of the real-time clock
    srand(rtc_Time());
}

void end(){
   delete ball;
}

void draw()
{
    ball->Draw();
    player1->Draw();
    player2->Draw();
    scoreboard->Draw();
}

void update(float deltaTime)
{
    player1->Update(deltaTime);
    player2->Update(deltaTime);
    didScore = ball->Update(deltaTime, player1->position, player2->position);

    if (didScore == 1)
    {
        ball->Reset();
        ball->baseSpeed += GAME_SPEED_ADDITION*2;
        player1->speed += GAME_SPEED_ADDITION*2;
        player2->speed += GAME_SPEED_ADDITION*2;
        scoreboard->addScore(1);
    }
    else if (didScore == 2)
    {
        ball->Reset();
        ball->baseSpeed += GAME_SPEED_ADDITION*2;
        player1->speed += GAME_SPEED_ADDITION*2;
        player2->speed += GAME_SPEED_ADDITION*2;
        scoreboard->addScore(2);
    }
    else if (didScore == 3)
    {
        ball->speed += GAME_SPEED_ADDITION;
        player1->speed += GAME_SPEED_ADDITION;
        player2->speed += GAME_SPEED_ADDITION;
    }
}

int main(void)
{
    begin();
    gfx_Begin();

    gfx_SetTextScale(2, 2);
    PrintCentered("Pong!", 0, 0);

    gfx_SetTextScale(1, 1);
    PrintCentered("TI-84 plus CE edition", 0, 20);
    PrintCentered("Press Enter to start", 0, 40);
    PrintCentered("Made by ;)", 0, 70);

    gfx_SetTextScale(2, 2);
    
    // To avoid the player instantly pressing enter after starting the program through cesium
    sleep(2);
    while (!(kb_Data[6] & kb_Enter));
    gfx_SetDrawBuffer();

    do {
        kb_Scan();
        timer_Set(1,0);
        gfx_FillScreen(0);

        // Time Delta is in seconds (divide by 32768 because it is a 32khz clock)
        float timeDelta = timer_Get(1) / 32768.0f;

        update(timeDelta);
        draw();
        gfx_SwapDraw();
    } while (!(kb_Data[6] & kb_Clear));

    gfx_End();

    end();
    return 0;
}

/* Prints a screen centered string */
void PrintCentered(const char *str, int offsetX, int offsetY)
{
    gfx_PrintStringXY(str,
                      (GFX_LCD_WIDTH - gfx_GetStringWidth(str)) / 2 + offsetX,
                      (GFX_LCD_HEIGHT - 8) / 2 + offsetY);
}
