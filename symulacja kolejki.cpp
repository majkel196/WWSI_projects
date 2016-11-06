#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int x1;    //intensywnosc grupa 1
    cout << "Podaj co ile sekund ma przychodzic klient grupy pierwszej: ";
    cin >> x1;

    int x2;    //intensywnosc grupa 2
    cout << "Podaj co ile sekund ma przychodzic klient grupy drugiej: ";
    cin >> x2;

    int s1;         //czas obslugi grupa 1
    cout << "Podaj czas obslugi klientow grupy pierwszej (w sekundach): ";
    cin >> s1;

    int s2;         //czas obslugi grupa 2
    cout << "Podaj czas obslugi klientow grupy drugiej (w sekundach): ";
    cin >> s2;

    int czas_trwania;
    cout << "Podaj czas trwania symulacji wyrazony w sekundach: ";
    cin >> czas_trwania;

    int * tablica_klienci1 = new int [czas_trwania];    //tablica klientow grupa1
    int * tablica_klienci2 = new int [czas_trwania];    //tablica klientow grupa2

    int klient1 = 0;    //ilosc klientow grupa1
    int klient2 = 0;    //ilosc klientow grupa2
    int obecny1 = 0;
    int obecny2 = 0;
    int czy_wolna_kolejka = 1;
    int czas_obslugi;
    int obsluzony_grupa_1 = 0;  //ilosc obsluzonych klientow grupa 1
    int obsluzony_grupa_2 = 0;  //ilosc obsluzonych klientow grupa 2
    int obecnie_w_kolejce;

    queue <int> kolejka_grupa_pierwsza;
    queue <int> kolejka_grupa_druga;

    //petla opisana tak, ze na poczatku w 0 sekundzie przychodzi do kolejki zarowno klient grupy 1
    //jak i klient grupy 2, dodatkowo miedzy podejsciem klientow do kasy wystepuje przerwa 1 sekundowa,
    //ktora bardziej zbliza program do rzeczywistych zdarzen
    for(int ilosc_cykli = 0; ilosc_cykli < czas_trwania; ilosc_cykli++)
    {
        if(ilosc_cykli % x1 == 0)
        {
            tablica_klienci1[klient1] = ilosc_cykli;  //wskazuje w ktorej sekundzie doszedl klient do kolejki
            klient1++;                                //zwieksza ilosc klientow, ktorzy przyszli
            kolejka_grupa_pierwsza.push(ilosc_cykli); //dodaje element do kolejki FIFO
        }
        if(ilosc_cykli % x2 == 0)
        {
            tablica_klienci2[klient2] = ilosc_cykli;  //wskazuje w ktorej sekundzie doszedl klient do kolejki
            klient2++;                                //zwieksza ilosc klientow, ktorzy przyszli
            kolejka_grupa_druga.push(ilosc_cykli);    //dodaje element do kolejki FIFO
        }

        if(kolejka_grupa_pierwsza.empty() && kolejka_grupa_druga.empty())
        {
            break;
        }
        else
        {
            if(czy_wolna_kolejka == 1)  //jesli kolejka jest wolna; 1 = true, 0 = false
            {

                if(kolejka_grupa_pierwsza.empty() && kolejka_grupa_druga.size() != 0)
                {
                    obecny2++;              //przesuniecie pozycji w tablicy
                    czas_obslugi = s2;      //przyrownanie klientowi jego czasu jaki spedzi przy kasie
                    czy_wolna_kolejka = 0;  //ustawienie statusu kolejki na zajeta
                    obecnie_w_kolejce = 2;  //wskazanie, ze obecnie w kolejce znajduje sie klient grupy 2
                }
                else if(kolejka_grupa_pierwsza.size() != 0 && kolejka_grupa_druga.empty())
                {
                    obecny1++;              //przesuniecie pozycji w tablicy
                    czas_obslugi = s1;      //przyrownanie klientowi jego czasu jaki spedzi przy kasie
                    czy_wolna_kolejka = 0;  //ustawienie statusu kolejki na zajeta
                    obecnie_w_kolejce = 1;  //wskazanie, ze obecnie w kolejce znajduje sie klient grupy 1
                }
                else if(kolejka_grupa_pierwsza.empty() && kolejka_grupa_druga.empty())
                {
                    break;
                }
                else
                {
                    if(tablica_klienci1[obecny1] < tablica_klienci2[obecny2])   //jesli klient z pierwszej grupy ma mniejsza wartosc czasu niz klient grupy drugiej
                    {
                        obecny1++;              //przesuniecie pozycji w tablicy
                        czas_obslugi = s1;      //przyrownanie klientowi jego czasu jaki spedzi przy kasie
                        czy_wolna_kolejka = 0;  //ustawienie statusu kolejki na zajeta
                        obecnie_w_kolejce = 1;  //wskazanie, ze obecnie w kolejce znajduje sie klient grupy 1
                    }
                    else if(tablica_klienci1[obecny1] > tablica_klienci2[obecny2])  //jesli klient z pierwszej grupy ma wieksza wartosc czasu niz klient grupy drugiej
                    {
                        obecny2++;              //przesuniecie pozycji w tablicy
                        czas_obslugi = s2;      //przyrownanie klientowi jego czasu jaki spedzi przy kasie
                        czy_wolna_kolejka = 0;  //ustawienie statusu kolejki na zajeta
                        obecnie_w_kolejce = 2;  //wskazanie, ze obecnie w kolejce znajduje sie klient grupy 2
                    }
                    else if(tablica_klienci1[obecny1] == tablica_klienci2[obecny2]) //przyjmujemy, ze jesli w tym samym czasie doszedl klient grupy 1 i grupy 2 to najpierw obslugujemy klienta grupy 1
                    {
                        obecny1++;              //przesuniecie pozycji w tablicy
                        czas_obslugi = s1;      //przyrownanie klientowi jego czasu jaki spedzi przy kasie
                        czy_wolna_kolejka = 0;  //ustawienie statusu kolejki na zajeta
                        obecnie_w_kolejce = 1;  //wskazanie, ze obecnie w kolejce znajduje sie klient grupy 1
                    }
                }
            }
            else if(czy_wolna_kolejka == 0)         //jesli kolejka jest wolna; 1 = true, 0 = false
            {
                czas_obslugi--;                     //odejmujemy czas jaki pozostal klientowi do obsluzenia
                if(czas_obslugi == 0)               //jesli klient zostal obsluzony (czyli jego czas do konca obsluzenia wynosi 0)
                {
                    czy_wolna_kolejka = 1;          //ustawienie statusu kolejki na wolna
                    if(obecnie_w_kolejce == 1)      //jesli obslugiwany byl klient grupy 1
                    {
                        obsluzony_grupa_1++;        //zwiekszenie ilosci obsluzonych klientow grupy 1
                        kolejka_grupa_pierwsza.pop();
                    }
                    else if(obecnie_w_kolejce == 2) //jesli obslugiwany byl klient grupy 2
                    {
                        obsluzony_grupa_2++;         //zwiekszenie ilosci obsluzonych klientow grupy 1
                        kolejka_grupa_druga.pop();
                    }
                }
            }
        }
    }

    cout << "W sumie klientow przybylo: " << klient1 + klient2 << endl;
    cout << "Klientow grupy pierwszej przybylo: " << klient1 << endl;
    cout << "Klientow grupy drugiej przybylo: " << klient2 << endl;
    cout << "Obsluzonych z grupy 1: " << obsluzony_grupa_1 << endl;
    cout << "Obsluzonych z grupy 2: " << obsluzony_grupa_2 << endl;

delete [] tablica_klienci1;
delete [] tablica_klienci2;

    return 0;
}
