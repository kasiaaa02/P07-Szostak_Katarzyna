/*
Wypisz wszystkie elementy tablicy dwuwymiarowej MxN w kolejnosci wyznaczanej przez kierunek antyprzekatnej.

Przyklad.
Wejscie:
[ 0 2 3 4 5 ]
[ 1 3 4 5 6 ]
[ 3 4 5 6 7 ]
[ 4 5 6 7 8 ]

Wyjscie:
0
1 2
3 3 3
4 4 4 4
5 5 5 5
6 6 6
7 7
8
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstdio>


using namespace std;

const int kolumny=3, wiersze=5; // Deklaracja wielkosci tablicy dwuwymiarowej

// Losuje wartosci do tablicy z przedzialu 0-9
void Losuj_wartosci( int wiersze, int kolumny, int ** T)
{
    for(int i=0; i<wiersze; i++) //wypelnienie tablicy losowymi liczbami
    {
        for (int j=0; j<kolumny; j++)
        {
            int liczba=rand()%10;
            T[i][j]=liczba;
        }
    }
}

// Wypisuje wartosci tablicy dwuwymiarowej T
void Wypisz_tablice( int wiersze, int kolumny, int ** T)
{
    cout<< " Ilosc kolumn: " <<kolumny<<endl;
    cout<< " Ilosc wierszy: "<<wiersze<<endl;
    cout << "TABLICA DWUWYMIAROWA" << endl<<endl;

    for(int i=0; i<wiersze; i++)
    {
        for (int j=0; j<kolumny; j++) cout<<T[i][j]<<" ";

        cout<<endl;
    }
}
/* Wypisuje wszystkie elementy tablicy T w kolejnosci wyznaczonej przez kierunek antyprzekatnej
 Procedura ta jest podzielona na dwie czesci:
 1) Kiedy ilosc wierszy jest mniejsza badz rowna ilosci kolumn
 2) Kiedy ilosc wierszy jest wieksza od ilosci kolumn.
 Nastepnie kazdy z tych podpunktow dzielimy na trzy czesci. Kazda z czesci trwa
 dopoki zmienna pomocnicza nie dochodzi do konca wartosci wybranej"scianki"
 */
void Antyprzekatne( int wiersze, int kolumny, int ** T)
{
    cout<<endl<<"Antyprzekatne: "<<endl;

        int i=0;
        if(wiersze<=kolumny)
            {
                while ( i<wiersze)

                    {
                        for(int j=0; j<=i; j++) cout<<T[i-j][j] <<" ";
                        cout<<endl;
                        i++;
                    }

                int p=kolumny-wiersze;
                int licznik=0;

                while (licznik<p)
                {
                    for(int j=1; j<=wiersze; j++) cout << T[wiersze-j][j+licznik]<<" ";
                    licznik++;
                    cout<<endl;
                }


                int reszta=wiersze-1;
                int licznik2=0;

                while (licznik2<reszta)
                {
                    for(int j=1; j<=reszta-licznik2; j++)
                    {
                        cout << T[wiersze-j][kolumny-reszta+licznik2+j-1]<< " ";
                    }
                    cout<<endl;
                    licznik2++;
                }
            }

            if(wiersze>kolumny)
            {
                while ( i<kolumny)

                    {
                        for(int j=0; j<=i; j++) cout<<T[i-j][j] <<" ";
                        cout<<endl;
                        i++;
                    }

                while (i<wiersze)
                {
                    for(int j=0; j<kolumny; j++) cout << T[i-j][j]<<" ";
                    i++;
                    cout<<endl;
                }

                int reszta=kolumny-1;
                int licznik2=0;

                while (licznik2<reszta)
                {
                    for(int j=1; j<=reszta-licznik2; j++)
                    {
                        cout << T[wiersze-j][licznik2+j]<< " ";
                    }
                    cout<<endl;
                    licznik2++;
                }
            }
}


int main()

{
    int ** T; // Tworzymy tablice wskaznikow

    T = new int *[wiersze];
    for (int i=0; i<wiersze; i++) T[i]= new int [kolumny];

    Losuj_wartosci(wiersze, kolumny, T);
    Wypisz_tablice(wiersze, kolumny, T);

    cout.setf(ios::fixed);
    cout.precision(5);
    clock_t start, koniec;
    start=clock();
    double roznica;

    Antyprzekatne(wiersze, kolumny, T);

    koniec=clock();
    roznica=(koniec-start)/(double)CLOCKS_PER_SEC;
    cout<<"Czas wykonywania: "<<roznica<<endl;


  // Usuwamy macierz. W pierwszej kolejnosci usuwamy tablice wierszy, nastepnie tablice wskaznikow.

  for( int i = 0; i < wiersze; i++ ) delete[]T [i];

  delete [ ] T;



    return 0;


}

