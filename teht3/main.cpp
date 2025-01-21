#include <iostream>
#include "chef.h"

using namespace std;

int main()
{

    ItalianChef ikokki("Kokki");
    ikokki.makeSoup(47);
    ikokki.makeSalad(21);
    ikokki.askSecret("pizza", 31, 27);

    return 0;
}
