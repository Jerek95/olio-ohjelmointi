#ifndef NOTIFIKAATTORI_H
#define NOTIFIKAATTORI_H

#include <iostream>
using namespace std;

class Seuraaja
{
public:
    Seuraaja(string);
    string getNimi();
    void paivitys(string);
    Seuraaja* next = nullptr;
private:
    string nimi;
};


class Notifikaattori
{
public:
    Notifikaattori();
    void lisaa(Seuraaja*);
    void poista(Seuraaja*);
    void tulosta();
    void postita(string);
private:
    Seuraaja* seuraajat = nullptr;
};





#endif // NOTIFIKAATTORI_H
