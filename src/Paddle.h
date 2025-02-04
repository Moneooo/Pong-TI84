
#ifndef PADDLE_H
#define PADDLE_H
#include "Vector2.cpp"

class Paddle
{
    public:
    Paddle(int player);
    void Draw();
    void Update(float deltaTime);
    Vector2 position;
    int speed;

    private:
    int height;
    int width;

    int playerIndex;
};

#endif