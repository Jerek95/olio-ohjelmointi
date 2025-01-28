#include <iostream>
#include "pankkitili.h"

using namespace std;

int main()
{
    Asiakas asiakas1("Maija", 1000);
    Asiakas asiakas2("Matti", 2000);

    asiakas1.talletus(500);
    asiakas2.talletus(600);
    asiakas1.nosto(300);
    asiakas2.nosto(100);
    asiakas1.luotonNosto(400);
    asiakas2.luotonNosto(200);
    asiakas1.luotonMaksu(50);
    asiakas2.luotonMaksu(100);
    asiakas1.tilisiirto(20, asiakas2);
    asiakas1.showSaldo();
    asiakas2.showSaldo();


    return 0;
}
