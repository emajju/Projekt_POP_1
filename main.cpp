/*
*   Program realizuj¹cy grê typu wykreœlanka
*   Autor Jan Mironkiewcz s165233
*   G³ówny s³ownik Sjp do gier
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
    cout <<"2. Jak graæ " << endl;
    cout <<"3. S³owniki " << endl;
    cout <<"4. Autor " << endl;
    cout <<"5. Wyjœcie z programu" << endl;
}
void wypisz_autor(void)
{
    system("cls");
    cout <<"Jan Mironkiewicz" << endl;
    cout <<"nr indeksu s165233" << endl;
    cout <<"email janmironkiewicz@gmail.com"<<endl;
    cout <<"naciœnij klawisz aby wróciæ do menu"<<endl;
    system("pause");
}
void menu_slowniki(void)
{
    //TODO wczytanie i zarz¹dzanie s³ownikami, prawdopodobnie potrzebny bêdzie wskaŸnik do tablicy s³ownika

}
bool przygotuj_dane(char adres[], string mniejsza[], int min_dl, int max_dl) //Zwróci fałsz jeżeli problem z plikiem, wymaga 1000el tablicy
{
     //przygotowanie s³ownika docelowo zapakowaæ do funkcji
    ifstream slownik;
    slownik.open(adres);

    if(!slownik.good())
    {
        cout <<"Nie wczytano s³ownika";
        system("pause");
        return false;
    }
    uint64_t liczba_linii = 0;//64bitowa poniewa¿ lini mo¿e byæ bardzo du¿o(obszerny s³ownik)
    string linia;
    while(!slownik.eof())
        {
            getline(slownik,linia);
            liczba_linii++;
        }
    slownik.close();
    slownik.open(adres);
    //cout <<"lini: "<<liczba_linii<<endl;
    //policzmy iloœæ linii
    string *tablica = new string[liczba_linii];//mamy du¿o pamiêci w komputerze wiêc bêdziemy z tego korzystaæ
    liczba_linii=0;

    while(!slownik.eof())
        {
            getline(slownik,tablica[liczba_linii]);
            liczba_linii++;
        }

    //string *mniejsza = new string[1000];
    srand(time(NULL ) ); //podajemy czas jako ziarno
    uint64_t liczba= 1;
    for(int i = 0; i<999; i++)
    {
        liczba = rand()*(rand()%(liczba_linii/RAND_MAX)); //Poprawiamy losowoœæ, RAND_MAX mo¿e okazaæ siê mniejszy ni¿ iloœæ linii w pliku
        int dlugosc = tablica[liczba].length();
        //cout << "  " << dlugosc;
        while((dlugosc<min_dl)||(dlugosc>max_dl)) //uzale¿niæ od zmiennych aby reagowa³o to na zmianê rozmiaru planszy
        {
            liczba = rand()*(rand()%(liczba_linii/RAND_MAX)); //Poprawiamy losowoœæ, RAND_MAX mo¿e okazaæ siê mniejszy ni¿ iloœæ linii w pliku
            dlugosc = tablica[liczba].length();

        }
        mniejsza[i] = tablica[liczba];
        //cout << mniejsza[i]<<endl;
        //dodaæ ograniczenia co do d³ugoœci liter tj wiêcej ni¿ 3 mniej ni¿ wyjdzie z wielkoœci planszy
    }
    delete [] tablica;
    //delete [] mniejsza; //sprz¹tamy w pamiêci
    slownik.close();

}
int main()
{

    while(1) //Pêtla nieskoñczona umo¿liwia grê bez koñca oraz poruszanie po menu
    {
        //Wypisujemy menu do konsoli
        cout << "Witamy w grze WYKREŒLANKA!\n";
        cout << "Wybierz co chcesz robiæ dalej: (wpisz liczbê i naciœnij enter)\n";

        int poziom_menu = 5; //do sprawdzania wydajnoœci
        wypisz_menu();
        cin >> poziom_menu; //w komentarzu gdy sprawdzana jest wydajnoœæ rozwi¹zañ
        //TODO b³êdy wprowadzania typu z³y znak


        switch(poziom_menu)
        {
        case 1:
            {

                //Wywo³anie gry
                //Pytamy o poziom trudnoœci oraz wymiary planszy
                //-£adujemy s³ownik
                //-Losujemy pierwsz¹ mniejsz¹ tablicê(MAX 1000 wyst¹pieñ
                //-Losujemy s³owa, ich pozycjê na planszy
                //-Losujemy litery dooko³a s³ów zale¿nie od poziomu trudnoœci
                //--£adujemy grê na ekran i dopiero gramy
                cout << "Wybierz rozmiar "<<endl;
                cout << "1. 5*8"<<endl;
                cout << "2. 10*10"<<endl;
                cout << "3. W³asny rozmiar"<<endl;
                int rozm_x, rozm_y;
                cin >> poziom_menu;
                switch(poziom_menu)
                {
                    case 1:
                            rozm_x =5;
                            rozm_y =8;
                            break;
                    case 2:
                            rozm_x =10;
                            rozm_y =10;
                            break;
                    case 3:
                            cout<<"Podaj szerokoœæ pola gry ";
                            cin >> rozm_x;
                            cout << "Podaj wysokoœæ pola gry ";
                            cin >> rozm_y;
                            break;
                    default:
                        cout << "Brak menu nr: "<< poziom_menu <<"\nSpróbuj ponownie\n";//Niby obs³uga b³êdów ;)
                        system("pause");
                        poziom_menu = 6;
                        break;

                }
                if(poziom_menu == 6)break;//wpisanie wartoœci innej ni¿ menu wyniesie nas do menu wy¿ej
                int trudnosc = 0;
                //Ustawiamy poziom trudnoœci
                cout<<"Musisz jeszcze okreœliæ poziom trudnoœci: "<<endl;
                cout<<"1. S³owa otoczone s¹ pojedyñcz¹ liter¹"<<endl;
                cout<<"2. S³owa otoczone s¹ losowymi literami"<<endl;
                cout<<"3. S³owa otoczone s¹ losowymi literami w³¹cznie z polskimi znakami"<<endl;
                cin >> trudnosc;
                /////////////////////////////////////////////////////////////////////Przygotowywanie tablicy
                system("cls"); //Wyczyść ekran
                cout << "Przygotowywanie gry...(może chwilę potrwać w zależności do słownika)\n";
                string *random = new string[1000]; //tablica zawiera 1000 słów po pierwszym losowaniu reszta zostanie wylosowana później
                przygotuj_dane("slowa.txt", random, 3, 10);
                //Tworzymy tablicę dwuwymiarową obsługującą planszę gry
                char **plansza = new char *[rozm_x]; //alokacja pamieci
                for ( int i = 0; i < rozm_x; ++i )
                {
                    plansza[i] = new double [rozm_y]; //alokacja pamieci

                }
                system("pause");


                //CDN

                //Sprzątanie pamięci
                delete[] random;
                for ( int i=0; i < rozm_x; ++i )
                        delete [] plansza[i];
                delete [] plansza;
                }
                break;
        case 2: //Wywolanie instrukcji
                system("cls");
                cout <<"Gra nie zwraca uwagi na wielkoœæ liter"<<endl;
                cout <<"Mo¿na wprowadziæ wiêcej ni¿ jedno s³owo za jednym razem. Wystarczy rozdzieliæ je spacj¹"<<endl;
                cout <<"S³ów nale¿y szukaæ w pionie, poziomie oraz na ukos"<<endl;
                cout <<"Je¿eli chcesz przerwaæ swoj¹ grê wpisz '_Koniec_'"<<endl;
                cout <<"Nacisnij klawisz aby powróciæ do menu...";
                system("pause");
                break;
        case 3: //Docelowe menu zarz¹dzania s³ownikami do generowania
                //Tu bêdzie mo¿liwoœæ w³¹czenia innego s³ownika np zmienna z maina przez ref jako adres do pliku

                break;
        case 4: //O autorze
                wypisz_autor();
                break;
        case 5://Wyjœcie z programu
                return 0;
                break;
        default:
                cout << "Brak menu nr: "<< poziom_menu <<"\nSpróbuj ponownie\n";//Niby obs³uga b³êdów ;)
                system("pause");
                break;
        }

        system("cls");//Wyczyœæ ekran przy ponownym za³adowaniu menu


    }
    return 0; //Prawid³owe zakoñczenie programu
}
