/*
*   Program realizujący grę typu wykreślanka
*   Autor Jan Mironkiewcz s165233
*   Główny słownik Sjp do gier
*/
#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>
#include <fstream>

using namespace std;

void wypisz_menu(void)
{
    cout <<"1. Grajmy! " << endl;
    cout <<"2. Jak grać " << endl;
    cout <<"3. Słowniki " << endl;
    cout <<"4. Autor " << endl;
    cout <<"5. Wyjście z programu" << endl;
}
void wypisz_autor(void)
{
    system("cls");
    cout <<"Jan Mironkiewicz" << endl;
    cout <<"nr indeksu s165233" << endl;
    cout <<"email janmironkiewicz@gmail.com"<<endl;
    cout <<"naciśnij klawisz aby wrócić do menu"<<endl;
    system("pause");
}
void menu_slowniki(void)
{
    //TODO wczytanie i zarządzanie słownikami, prawdopodobnie potrzebny będzie wskaźnik do tablicy słownika

}

int main()
{
    //przygotowanie słownika docelowo zapakować do funkcji
    ifstream slownik;
    slownik.open("slowa.txt");
    if(!slownik.good())
    {
        cout <<"Nie wczytano słownika";
        system("pause");
        return 0;
    }
    uint64_t liczba_linii = 0;//64bitowa ponieważ lini może być bardzo dużo(obszerny słownik)
    string linia;
    while(!slownik.eof())
        {
            getline(slownik,linia);
            liczba_linii++;
        }
    slownik.close();
    slownik.open("slowa.txt");
    cout <<"lini: "<<liczba_linii<<endl;
    //policzmy ilość linii
    string *tablica = new string[liczba_linii];//mamy dużo pamięci w komputerze więc będziemy z tego korzystać
    liczba_linii=0; //tą część trzeba zamienić na przejście na początek pliku zamiast zamykania i otwierania
    while(!slownik.eof())
        {
            getline(slownik,tablica[liczba_linii]);
            liczba_linii++;
        }

    string *mniejsza = new string[1000];
    srand(time(NULL ) ); //podajemy czas jako ziarno
    uint64_t liczba= 1;
    for(int i = 0; i<999; i++)
    {
        liczba = rand()*(rand()%81);
        mniejsza[i] = tablica[liczba];
        cout << mniejsza[i]<<endl;
        //dodać ograniczenia co do długości liter tj więcej niż 3 mniej niż wyjdzie z wielkości planszy
    }
    delete [] tablica;

    while(1) //Pętla nieskończona umożliwia grę bez końca oraz poruszanie po menu
    {
        //Wypisujemy menu do konsoli
        cout << "Witamy w grze WYKREŚLANKA!\n";
        cout << "Wybierz co chcesz robić dalej: (wpisz liczbę i naciśnij enter)\n";

        int poziom_menu = 0;
        wypisz_menu();
        cin >> poziom_menu;
        //TODO błędy wprowadzania typu zły znak


        switch(poziom_menu)
        {
        case 1: //Wywołanie gry

                break;
        case 2: //Wywolanie instrukcji
                system("cls");
                cout <<"Gra nie zwraca uwagi na wielkość liter"<<endl;
                cout <<"Można wprowadzić więcej niż jedno słowo za jednym razem. Wystarczy rozdzielić je spacją"<<endl;
                cout <<"Słów należy szukać w pionie, poziomie oraz na ukos"<<endl;
                cout <<"Jeżeli chcesz przerwać swoją grę wpisz '_Koniec_'"<<endl;
                cout <<"Nacisnij klawisz aby powrócić do menu...";
                system("pause");
                break;
        case 3: //Docelowe menu zarządzania słownikami do generowania

                break;
        case 4: //O autorze
                wypisz_autor();
                break;
        case 5://Wyjście z programu

                return 0;
                break;
        default:
                cout << "Brak menu nr: "<< poziom_menu <<"\nSpróbuj ponownie\n";
                system("pause");
                break;
        }

        system("cls");


    }
    return 0; //Prawidłowe zakończenie programu
}
