#include <iostream>
#include <cstdlib>
#include "game.h"

using namespace std;

int main()
{
    int luku;

    cout << "Syota kuinka monen luvun joukosta haluat arvata" << endl;
    cin >> luku;

    Game peli(luku);
    peli.play();

    return 0;
}
