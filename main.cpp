#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

void citire(int numere[],int &limita)
{
    fin>>limita;    //Citim limita din fisierul date.in
    for(int i=1; i<=limita; i++){
        fin>>numere[i];     //Citim numerele din fisierul date.in
    }
}

void afisare(int numere[],int limita)
{
    for(int i=1; i<=limita; i++){
        fout<<numere[i]<<" ";     //Afisam numerele din fisierul date.in
    }
}


//Aici e problema
void eliminareNumereGresite(int numere[],int limita)
{
    for(int i=1; i<=limita; i++){
        if(numere[i] < 100 || numere[i] > 1000000){      //Verificam nuemrele incorecte
            for(int j = i; j<=limita; j++){
                numere[j] = numere[j+1];      //Eliminam numerele incorecte din vector
                limita--;
            }
            i--;
        }
    }
}

int main()
{
    int numere[100], limita;    //Declaram variabilele
    citire(numere, limita);     //Apel la functia de citire
    eliminareNumereGresite(numere, limita);     //Apel la functia de eliminare
    afisare(numere, limita);    //Apel la functia de afisare
}
