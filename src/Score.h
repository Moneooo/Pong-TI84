
#ifndef SCORE_H
#define SCORE_H

class Score
{
    public:
        Score();
        void addScore(int playerIndex);
        void Draw();
    private:
        int player1Score;
        int player2Score;
};

#endif