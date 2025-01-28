#include "pankkitili.h"
#include <iostream>

using namespace std;

Pankkitili::Pankkitili(string n)
{
    omistaja = n;
    cout<<"Pankkitili luotu "<<omistaja<<":lle"<<endl;
}

double Pankkitili::getBalance()
{
    return saldo;
}

bool Pankkitili::deposit(double t)
{
    if (t >= 0){
        saldo += t;
        cout<<omistaja<<":n tilille talletettu "<<t<<endl;
        return true;
    }
    else {
        cout<<"Ei voi tallettaa negatiivista summaa"<<endl;
        return false;
    }

}

bool Pankkitili::withdraw(double n)
{
    if (n >= 0 && saldo >= n){
        saldo -= n;
        cout<<omistaja<<":n tililta nostettu "<<n<<endl;
        return true;
    }
    else {
        if (n >= 0){
            cout<<"Tililla ei ole tarpeeksi saldoa"<<endl;
            return false;
        }
        else{
            cout<<"Ei voi nostaa negatiivista summaa"<<endl;
            return false;
        }

    }
}

Luottotili::Luottotili(string n, double lr): Pankkitili(n)
{
    omistaja = n;
    luottoraja = lr;
    cout<<"Luottotili luotu "<<omistaja<<":lle, luottoraja "<<lr<<endl;
}

bool Luottotili::deposit(double t)
{
    if (saldo >= t && t >= 0){
        saldo -= t;
        cout<<omistaja<<" maksanut luottoa "<<t<<endl;
        return true;
    }
    else {
        if (t >= 0){
            cout<<"Ei voi maksaa liikaa"<<endl;
            return false;
        }
        else{
            cout<<"Ei voi maksaa negatiivista summaa"<<endl;
            return false;
        }

    }
}

bool Luottotili::withdraw(double n)
{
    if (n >= 0 && luottoraja >= saldo + n){
        saldo += n;
        cout<<omistaja<<" ottanut luottoa "<<n<<endl;
        return true;
    }
    else {
        if (n >= 0){
            cout<<"Luottoraja ylitetty"<<endl;
            return false;
        }
        else{
            cout<<"Ei voi nostaa negatiivista summaa"<<endl;
            return false;
        }

    }
}

Asiakas::Asiakas(string n, double lr): kayttotili(n), luottotili(n, lr)
{
    nimi = n;
    cout<<"Asiakkuus luotu "<<n<<endl;
}

string Asiakas::getNimi()
{
    return nimi;
}

void Asiakas::showSaldo()
{
    cout<<getNimi()<<":n kayttotilin saldo on "<< kayttotili.getBalance()<<endl;
    cout<<getNimi()<<":n luottotilin saldo on "<< luottotili.getBalance()<<endl;
}

bool Asiakas::talletus(double t)
{
    if (kayttotili.deposit(t)){
        return true;
    }
    else {
        return false;
    }
}

bool Asiakas::nosto(double n)
{
    if (kayttotili.withdraw(n)){
        return true;
    }
    else {
        return false;
    }
}

bool Asiakas::luotonMaksu(double lm)
{
    if (luottotili.deposit(lm)){
        //luottotili.deposit(lm);
        return true;
    }
    else {
        return false;
    }
}

bool Asiakas::luotonNosto(double ln)
{
    if (luottotili.withdraw(ln)){
        //luottotili.withdraw(ln);
        return true;
    }
    else {
        return false;
    }
}

bool Asiakas::tilisiirto(double s, Asiakas &a)
{
    if (s >= 0 && kayttotili.getBalance() >= s){
        cout<<getNimi()<<" siirtaa "<<s<<" "<<a.getNimi()<<":lle"<<endl;
        nosto(s);
        a.talletus(s);
        return true;
    }
    else {
        if (s >= 0){
            cout<<"Tililla ei ole tarpeeksi saldoa tilisiirtoa varten"<<endl;
            return false;
        }
        else{
            cout<<"Ei voi siirtaa negatiivista summaa"<<endl;
            return false;
        }

    }
}

