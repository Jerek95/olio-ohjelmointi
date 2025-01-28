#ifndef PANKKITILI_H
#define PANKKITILI_H

#include <iostream>
using namespace std;

class Pankkitili
{
public:
    Pankkitili(string);
    double getBalance();
    virtual bool deposit(double);
    virtual bool withdraw(double);
protected:
    string omistaja;
    double saldo = 0;
};

class Luottotili : public Pankkitili{
public:
    Luottotili(string, double);
    bool deposit(double) override;
    bool withdraw(double) override;
protected:
    double luottoraja = 0;
};

class Asiakas{
public:
    Asiakas(string, double);
    string getNimi();
    void showSaldo();
    bool talletus(double);
    bool nosto(double);
    bool luotonMaksu(double);
    bool luotonNosto(double);
    bool tilisiirto(double, Asiakas &);
private:
    string nimi;
    Pankkitili kayttotili;
    Luottotili luottotili;
};

#endif // PANKKITILI_H
