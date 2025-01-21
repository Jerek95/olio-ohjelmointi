#include "chef.h"
#include <algorithm>
#include <iostream>

using namespace std;

Chef::Chef(string n) : chefName(n)
{
    cout<<"Kokki nimelta "<<chefName<<" luotu"<<endl;
}

Chef::~Chef()
{
    cout<<"Kokki tuhottu"<<endl;
}

string Chef::getName()
{
    return chefName;
}

int Chef::makeSalad(int a)
{
    int salaatti = a / 5;
    cout<<"Valmistetaan "<<a<< " aineksesta "<<salaatti<< " annosta salaattia"<<endl;
    return salaatti;
}

int Chef::makeSoup(int a)
{
    int keitto = a / 3;
    cout<<"Valmistetaan "<<a<< " aineksesta "<<keitto<< " annosta keittoa"<<endl;
    return keitto;
}

ItalianChef::ItalianChef(string n) : Chef(n)
{
    cout<<"Italialaine kokki nimelta "<<n<<" luotu"<<endl;
}

ItalianChef::~ItalianChef()
{
    cout<<"Italialaine kokki tuhottu"<<endl;
}

bool ItalianChef::askSecret(string salasana, int jauho, int vesi)
{
    if (salasana == password){
        cout<<"Salasana oikein"<<endl;
        makePizza(jauho, vesi);
        return true;
    }
    else{
        cout<<"Salasana vaarin"<<endl;
        return false;
    }
}

int ItalianChef::makePizza(int j, int v)
{
    int pizza = min(j, v) / 5;
    cout<<"Valmistetaan "<<j<< " aineksesta jauhoja ja "<<v<< " aineksesta vetta "<<pizza<<" pizzaa"<<endl;
    return pizza;
}

