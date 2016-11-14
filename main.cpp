/*
*   Program realizujący grę typu wykreślanka
*   Autor Jan Mironkiewcz s165233
*/
#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>

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
int main()
{
    //Wypisujemy menu do konsoli
    cout << "Witamy w grze WYKREŚLANKA!\n";
    cout << "Wybierz co chcesz robić dalej: (wpisz liczbę i naciśnij enter)\n";




    while(1) //Pętla nieskończona umożliwia grę bez końca oraz poruszanie po menu
    {
        int poziom_menu = 0;
        wypisz_menu();
        cin >> poziom_menu;
        //TODO błędy wprowadzania typu zły znak

        switch(poziom_menu)
        {
        case 1: //Wywołanie gry

                break;
        case 2: //Wywolanie instrukcji

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
