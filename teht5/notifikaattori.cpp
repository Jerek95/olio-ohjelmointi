#include "notifikaattori.h"
#include <iostream>

using namespace std;

Notifikaattori::Notifikaattori()
{
    cout<<"Luodaan notifikaattori"<<endl;
}

void Notifikaattori::lisaa(Seuraaja* lisattavaSeuraaja)
{
    if (seuraajat == nullptr){
        seuraajat = lisattavaSeuraaja;
    }

    else{
        lisattavaSeuraaja->next = seuraajat;
        seuraajat = lisattavaSeuraaja;
    }
    cout<<"Notifikaattori lisaa seuraajan "<<lisattavaSeuraaja->getNimi()<<endl;
}

void Notifikaattori::poista(Seuraaja* poistettavaSeuraaja)
{
    Seuraaja* o = seuraajat;
    while (o->next != poistettavaSeuraaja){
        o = o->next;
    }
    o->next = poistettavaSeuraaja->next;
    cout<<"Notifikaattori poistaa seuraajan "<<poistettavaSeuraaja->getNimi()<<endl;
}

void Notifikaattori::tulosta()
{
    Seuraaja* o = seuraajat;
    cout<<"Notifikaattorin seuraajat:"<<endl;
    while (o != nullptr){
        cout<<"Seuraaja "<<o->getNimi()<<endl;
        o = o->next;
    }
}

void Notifikaattori::postita(string p)
{
    Seuraaja* o = seuraajat;
    cout<<"Notifikaattori postaa viestin "<<p<<endl;
    while (o != nullptr){
        o->paivitys(p);
        o = o->next;
    }
}

Seuraaja::Seuraaja(string s)
{
    nimi = s;
    cout<<"Luodaan seuraaja "<<nimi<<endl;
}

string Seuraaja::getNimi()
{
    return nimi;
}

void Seuraaja::paivitys(string p)
{
    cout<<"Seuraaja "<<getNimi()<<" sai viestin "<<p<<endl;
}
