#include <iostream>
#include <cstdlib>
using namespace std;

int game(int maxnum);

int main()
{
    int lukujenMaara;
    int tulos;

    cout << "Syota kuinka monen luvun joukosta haluat arvata" << endl;
    cin >> lukujenMaara;
    tulos = game(lukujenMaara);
    cout << "Arvausten maara oli "<< tulos << endl;

    return 0;
}



int game(int maxnum){
    int arvottuLuku;
    int pelaajanArvaus;
    int arvaustenMaara = 0;
    int peliKaynnissa = 1;

    srand(13);
    arvottuLuku = rand() % maxnum + 1;

    while (peliKaynnissa == 1){
        cout << "Syota arvaus" << endl;
        cin >> pelaajanArvaus;

        if (pelaajanArvaus < arvottuLuku){
            cout << "Liian pieni" << endl;
        }
        else if (pelaajanArvaus > arvottuLuku){
            cout << "Liian suuri" << endl;
        }
        else if (pelaajanArvaus == arvottuLuku){
            cout << "Oikein" << endl;
            peliKaynnissa = 0;
        }
        arvaustenMaara++;
    }

    return arvaustenMaara;
}




