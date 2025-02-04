#ifndef BALL_H
#define BALL_H
#include "Vector2.cpp"

class Ball
{
    public:
    Ball();
    void Draw();
    void Reset();
    int Update(float deltaTime, Vector2 player1Pos, Vector2 player2Pos);
    int speed;
    int baseSpeed;

    private:
    Vector2 position;
    int radius;

    int xDir;
    int yDir;
};

#endif