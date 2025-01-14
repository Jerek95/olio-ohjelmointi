#include "game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
using namespace std;

Game::Game(int m) {
    cout<<"Peli aloitettu maksimiarvolla "<<m<<endl;
    maxNumber = m;
}

Game::~Game()
{
    cout<<"Peli lopetettu"<<endl;
}

void Game::play()
{
    srand(time(NULL));
    randomNumber = rand() % maxNumber + 1;

    while (playerGuess != randomNumber){
        cout<<"Syota arvaus"<<endl;
        cin>>playerGuess;
        if (playerGuess < randomNumber){
            cout<<"Liian pieni"<<endl;

        }
        else if (playerGuess > randomNumber){
            cout<<"Liian suuri"<<endl;
        }
        else {
            cout<<"Oikein"<<endl;

        }
        numOfGuesses++;

    }

    printGameResult();
}

void Game::printGameResult()
{
    cout<<"Tuloksesi on "<<numOfGuesses<<endl;
}
