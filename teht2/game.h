#ifndef GAME_H
#define GAME_H

class Game
{
public:
    Game(int);
    ~Game();
    void play();

private:
    void printGameResult();
    int maxNumber;
    int playerGuess = 0;
    int randomNumber;
    int numOfGuesses = 0;
};

#endif // GAME_H
