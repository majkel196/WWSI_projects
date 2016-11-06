#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <stdio.h>
#include <conio.h>

using namespace std;

void stan_konta(int kasa);
void wplata_na_konto(int * kasa);
void wyplata_z_konta(int & kasa);

int main()
{

    cout << " ----------------------------" << endl;
    cout << "|                            |" << endl;
    cout << "|           WITAJ            |" << endl;
    cout << "|                            |" << endl;
    cout << "|             W              |" << endl;
    cout << "|                            |" << endl;
    cout << "|        NASZYM BANKU        |" << endl;
    cout << "|                            |" << endl;
    cout << " ----------------------------" << endl;
    cout << endl;

    cout << "Ile kont chcesz utworzyc? (maksymalna ilosc = 5) : ";
    int ilosc_kont;
    cin >> ilosc_kont;
    while (ilosc_kont > 5 || ilosc_kont <= 0)
    {
        if (ilosc_kont <= 0)
        {
            cout << "Za mala ilosc kont!" << endl;
        }
        else if (ilosc_kont > 5)
        {
            cout << "Za duza ilosc kont!" << endl;
        }
        getchar();
        Sleep(2000);
        system("cls");
        cout << " ----------------------------------" << endl;
        cout << "|                                  |" << endl;
        cout << "|              WITAJ               |" << endl;
        cout << "|                                  |" << endl;
        cout << "|                W                 |" << endl;
        cout << "|                                  |" << endl;
        cout << "|           NASZYM BANKU           |" << endl;
        cout << "|                                  |" << endl;
        cout << " ----------------------------------" << endl;
        cout << endl;
        cout << "Podaj poprawna ilosc kont (maksymalna = 5): ";
        cin >> ilosc_kont;
    }

    int * tablica_konta = new int[ilosc_kont];
    int * tablica_hasla = new int[ilosc_kont];
    int * tablica_kasa = new int[ilosc_kont];

    cout << endl;
    cout << " ----------------------------------" << endl;
    cout << endl;

    for(int i = 0; i < ilosc_kont; i++)
    {
        cout << "Tworzenie konta numer: " << i+1 << endl;
        cout << "Podaj swoj unikalny numer konta: ";
        cin >> tablica_konta[i];
        cout << "Podaj swoj PIN do konta: ";
        cin >> tablica_hasla[i];
        cout << "Podaj stan konta: ";
        cin >> tablica_kasa[i];
        cout << endl;
        cout << " ----------------------------------" << endl;
        cout << endl;
    }

    cout << "Konta zostaly utworzone poprawnie." << endl;
    cout << endl;

    {
        cout << "Przejscie do panelu logowania za ";
        for(int i = 5; i > 0; i--)
        {
            cout << i << "...";
            Sleep(1000);
        }
    }
    system("cls");


    string dzialanie_programu;
    do
    {
        cout << " ----------------------------------" << endl;
        cout << "|                                  |" << endl;
        cout << "|         SYSTEM LOGOWANIA         |" << endl;
        cout << "|                                  |" << endl;
        cout << "| Aby sie zalogowac, wpisz dowolny |" << endl;
        cout << "|      ciag znakow i zatwierdz     |" << endl;
        cout << "|            go enterem.           |" << endl;
        cout << "|                                  |" << endl;
        cout << "|    Aby zakonczyc, wpisz exit.    |" << endl;
        cout << "|                                  |" << endl;
        cout << " ----------------------------------" << endl;

        cin >> dzialanie_programu;
        if(dzialanie_programu == "exit")
        {
            exit(0);
        }
        else
        {
            system("cls");
            cout << " ----------------------------------" << endl;
            cout << "|                                  |" << endl;
            cout << "|         SYSTEM LOGOWANIA         |" << endl;
            cout << "|                                  |" << endl;
            cout << " ----------------------------------" << endl;
            int ilosc_prob = 0;
            int numer_konta_logowanie;
            int numer_pin;
            int ilosc_kasy;
            while(ilosc_prob < 3)
            {
                cout << "Podaj numer konta: ";
                cin >> numer_konta_logowanie;
                cout << "Podaj PIN: ";
                cin >> numer_pin;
                cout << endl;
                cout << "Weryfikacja danych..." << endl;
                Sleep(5000);

                if(numer_konta_logowanie == tablica_konta[0] && numer_pin == tablica_hasla[0] ||
                        numer_konta_logowanie == tablica_konta[1] && numer_pin == tablica_hasla[1] ||
                        numer_konta_logowanie == tablica_konta[2] && numer_pin == tablica_hasla[2] ||
                        numer_konta_logowanie == tablica_konta[3] && numer_pin == tablica_hasla[3] ||
                        numer_konta_logowanie == tablica_konta[4] && numer_pin == tablica_hasla[4] )
                {
                    cout << "Poprawny numer konta. Zalogowano.";
                    Sleep(1000);
                    break;
                }
                else
                {
                    cout << "Niepoprawny numer konta." << endl;
                    if(ilosc_prob == 2)
                    {
                        cout << "3 razy zly PIN. Zamykanie programu." << endl;
                        exit(0);
                    }
                    if (ilosc_prob < 2)
                    {
                        cout << "Pozostalo prob: " << 2 - ilosc_prob << endl;
                        cout << endl;
                        cout << " ----------------------------" << endl;
                        cout << endl;
                    }
                    ilosc_prob++;
                }
            }

            getchar();
            Sleep(1000);
            system("cls");

            if(numer_konta_logowanie == tablica_konta[0])
            {
                numer_konta_logowanie = tablica_konta[0];
                numer_pin = tablica_hasla[0];
                ilosc_kasy = tablica_kasa[0];
            }
            else if(numer_konta_logowanie == tablica_konta[1])
            {
                numer_konta_logowanie = tablica_konta[1];
                numer_pin = tablica_hasla[1];
                ilosc_kasy = tablica_kasa[1];
            }
            else if(numer_konta_logowanie == tablica_konta[2])
            {
                numer_konta_logowanie = tablica_konta[2];
                numer_pin = tablica_hasla[2];
                ilosc_kasy = tablica_kasa[2];
            }
            else if(numer_konta_logowanie == tablica_konta[3])
            {
                numer_konta_logowanie = tablica_konta[3];
                numer_pin = tablica_hasla[3];
                ilosc_kasy = tablica_kasa[3];
            }
            else if(numer_konta_logowanie == tablica_konta[4])
            {
                numer_konta_logowanie = tablica_konta[4];
                numer_pin = tablica_hasla[4];
                ilosc_kasy = tablica_kasa[4];
            }


            char opcja;
            do
            {
                cout << "Zalogowany jako: " << numer_konta_logowanie << endl;
                cout << "PIN: " << numer_pin << endl;
                cout << "Gotowka: " << ilosc_kasy << endl;
                cout << endl;

                cout << " ----------------------------" << endl;
                cout << "| Wybierz opcje:             |" << endl;
                cout << "| 1: Sprawdzenie stanu konta |" << endl;
                cout << "| 2: Wplata gotowki          |" << endl;
                cout << "| 3: Wyplata gotowki         |" << endl;
                cout << "| 4: Przelew na inne konto   |" << endl;
                cout << "| 5: Wylogowanie             |" << endl;
                cout << " ----------------------------" << endl;
                cout << endl;


                opcja = getch();
                switch(opcja)
                {
                case '1':
                {
                    stan_konta(ilosc_kasy);
                }
                break;
                case '2':
                {
                    wplata_na_konto(&ilosc_kasy);
                }
                break;
                case '3':
                {
                    wyplata_z_konta(ilosc_kasy);
                }
                break;
                case '4':
                {
                    cout << "Podaj numer konta na jakie chcesz dokonac przelew: ";
                    int przelew_numer_konta;
                    cin >> przelew_numer_konta;

                    if(przelew_numer_konta == tablica_konta[0])
                    {
                        cout << "Podaj ilosc gotowki jaka chcesz przelac: ";
                        int przelew_kwota;
                        cin >> przelew_kwota;
                        while(przelew_kwota)
                        {
                            if(przelew_kwota > ilosc_kasy)
                            {
                                cout << "Za mala ilosc gotowki na koncie!" << endl;
                                cout << "Podaj ilosc gotowki jaka chcesz przelac: ";
                                cin >> przelew_kwota;
                            }
                            else if(przelew_kwota <= 0)
                            {
                                cout << "Niepoprawna ilosc gotowki!" << endl;
                                cout << "Podaj ilosc gotowki jaka chcesz przelac: ";
                                cin >> przelew_kwota;
                            }
                            else
                            {
                                break;
                            }
                        }
                        cout << "Ilosc gotowki do przelania: " << przelew_kwota << ". Jestes pewny? t/n" << endl;
                        char tn;
                        tn = getch();
                        switch(tn)
                        {
                        case 't':
                        {
                            cout << "Zlecenie w trakcie realizacji..." << endl;
                            Sleep(5000);
                            ilosc_kasy -= przelew_kwota;
                            tablica_kasa[0] += przelew_kwota;
                            cout << "Zlecenie zrealizowano pomyslnie!" << endl;
                            Sleep(2000);
                        }
                        break;
                        case 'n':
                        {
                            cout << "Zlecenie anulowane." << endl;
                        }
                        break;
                        }
                    }
                    else if(przelew_numer_konta == tablica_konta[1])
                    {
                        cout << "Podaj ilosc gotowki jaka chcesz przelac: ";
                        int przelew_kwota;
                        cin >> przelew_kwota;
                       while(przelew_kwota)
                        {
                            if(przelew_kwota > ilosc_kasy)
                            {
                                cout << "Za mala ilosc gotowki na koncie!" << endl;
                                cout << "Podaj ilosc gotowki jaka chcesz przelac: ";
                                cin >> przelew_kwota;
                            }
                            else if(przelew_kwota <= 0)
                            {
                                cout << "Niepoprawna ilosc gotowki!" << endl;
                                cout << "Podaj ilosc gotowki jaka chcesz przelac: ";
                                cin >> przelew_kwota;
                            }
                            else
                            {
                                break;
                            }
                        }
                        cout << "Ilosc gotowki do przelania: " << przelew_kwota << ". Jestes pewny? t/n" << endl;
                        char tn;
                        tn = getch();
                        switch(tn)
                        {
                        case 't':
                        {
                            cout << "Zlecenie w trakcie realizacji..." << endl;
                            Sleep(5000);
                            ilosc_kasy -= przelew_kwota;
                            tablica_kasa[1] += przelew_kwota;
                            cout << "Zlecenie zrealizowano pomyslnie!" << endl;
                            Sleep(2000);
                        }
                        break;
                        case 'n':
                        {
                            cout << "Zlecenie anulowane." << endl;
                        }
                        break;
                        }
                    }
                    else if(przelew_numer_konta == tablica_konta[2])
                    {
                        cout << "Podaj ilosc gotowki jaka chcesz przelac: ";
                        int przelew_kwota;
                        cin >> przelew_kwota;
                        while(przelew_kwota)
                        {
                            if(przelew_kwota > ilosc_kasy)
                            {
                                cout << "Za mala ilosc gotowki na koncie!" << endl;
                                cout << "Podaj ilosc gotowki jaka chcesz przelac: ";
                                cin >> przelew_kwota;
                            }
                            else if(przelew_kwota <= 0)
                            {
                                cout << "Niepoprawna ilosc gotowki!" << endl;
                                cout << "Podaj ilosc gotowki jaka chcesz przelac: ";
                                cin >> przelew_kwota;
                            }
                            else
                            {
                                break;
                            }
                        }
                        cout << "Ilosc gotowki do przelania: " << przelew_kwota << ". Jestes pewny? t/n" << endl;
                        char tn;
                        tn = getch();
                        switch(tn)
                        {
                        case 't':
                        {
                            cout << "Zlecenie w trakcie realizacji..." << endl;
                            Sleep(5000);
                            ilosc_kasy -= przelew_kwota;
                            tablica_kasa[2] += przelew_kwota;
                            cout << "Zlecenie zrealizowano pomyslnie!" << endl;
                            Sleep(2000);
                        }
                        break;
                        case 'n':
                        {
                            cout << "Zlecenie anulowane." << endl;
                        }
                        break;
                        }
                    }
                    else if(przelew_numer_konta == tablica_konta[3])
                    {
                        cout << "Podaj ilosc gotowki jaka chcesz przelac: ";
                        int przelew_kwota;
                        cin >> przelew_kwota;
                        while(przelew_kwota)
                        {
                            if(przelew_kwota > ilosc_kasy)
                            {
                                cout << "Za mala ilosc gotowki na koncie!" << endl;
                                cout << "Podaj ilosc gotowki jaka chcesz przelac: ";
                                cin >> przelew_kwota;
                            }
                            else if(przelew_kwota <= 0)
                            {
                                cout << "Niepoprawna ilosc gotowki!" << endl;
                                cout << "Podaj ilosc gotowki jaka chcesz przelac: ";
                                cin >> przelew_kwota;
                            }
                            else
                            {
                                break;
                            }
                        }
                        cout << "Ilosc gotowki do przelania: " << przelew_kwota << ". Jestes pewny? t/n" << endl;
                        char tn;
                        tn = getch();
                        switch(tn)
                        {
                        case 't':
                        {
                            cout << "Zlecenie w trakcie realizacji..." << endl;
                            Sleep(5000);
                            ilosc_kasy -= przelew_kwota;
                            tablica_kasa[3] += przelew_kwota;
                            cout << "Zlecenie zrealizowano pomyslnie!" << endl;
                            Sleep(2000);
                        }
                        break;
                        case 'n':
                        {
                            cout << "Zlecenie anulowane." << endl;
                        }
                        break;
                        }
                    }
                    else if(przelew_numer_konta == tablica_konta[4])
                    {
                        cout << "Podaj ilosc gotowki jaka chcesz przelac: ";
                        int przelew_kwota;
                        cin >> przelew_kwota;
                        while(przelew_kwota)
                        {
                            if(przelew_kwota > ilosc_kasy)
                            {
                                cout << "Za mala ilosc gotowki na koncie!" << endl;
                                cout << "Podaj ilosc gotowki jaka chcesz przelac: ";
                                cin >> przelew_kwota;
                            }
                            else if(przelew_kwota <= 0)
                            {
                                cout << "Niepoprawna ilosc gotowki!" << endl;
                                cout << "Podaj ilosc gotowki jaka chcesz przelac: ";
                                cin >> przelew_kwota;
                            }
                            else
                            {
                                break;
                            }
                        }
                        cout << "Ilosc gotowki do przelania: " << przelew_kwota << ". Jestes pewny? t/n" << endl;
                        char tn;
                        tn = getch();
                        switch(tn)
                        {
                        case 't':
                        {
                            cout << "Zlecenie w trakcie realizacji..." << endl;
                            Sleep(5000);
                            ilosc_kasy -= przelew_kwota;
                            tablica_kasa[4] += przelew_kwota;
                            cout << "Zlecenie zrealizowano pomyslnie!" << endl;
                            Sleep(2000);
                        }
                        break;
                        case 'n':
                        {
                            cout << "Zlecenie anulowane." << endl;
                        }
                        break;
                        }
                    }
                    else
                    {
                        cout << "Konto nie istnieje!" << endl;
                        Sleep(2000);
                        break;
                    }
                }
                break;
                case '5':
                {
                    cout << "Trwa wylogowywanie..." << endl;
                    Sleep(5000);
                }
                break;
                default:
                {
                    cout << "Nie ma takiej opcji!"<< endl;
                    Sleep(3000);
                }
                break;
                }
                system("cls");
            }
            while(opcja != '5');

            if(numer_konta_logowanie == tablica_konta[0])
            {
                tablica_kasa[0] = ilosc_kasy;
            }
            else if(numer_konta_logowanie == tablica_konta[1])
            {
                tablica_kasa[1] = ilosc_kasy;
            }
            else if(numer_konta_logowanie == tablica_konta[2])
            {
                tablica_kasa[2] = ilosc_kasy;
            }
            else if(numer_konta_logowanie == tablica_konta[3])
            {
                tablica_kasa[3] = ilosc_kasy;
            }
            else if(numer_konta_logowanie == tablica_konta[4])
            {
                tablica_kasa[4] = ilosc_kasy;
            }
        }
    }
    while(dzialanie_programu != "exit");

    delete [] tablica_konta;
    delete [] tablica_hasla;
    delete [] tablica_kasa;

    return 0;
}

void stan_konta(int kasa)
{
    cout << "Zlecenie w trakcie realizacji..." << endl;
    Sleep(5000);
    cout << "Stan konta wynosi: " << kasa << endl;
    Sleep(2000);
}

void wplata_na_konto(int * kasa)
{
    cout << "Ile gotowki chcesz wplacic?" << endl;
    int wplata_gotowki;
    cin >> wplata_gotowki;
    while(wplata_gotowki < 0)
    {
        cout << "Niepoprawna ilosc gotowki!" << endl;
        Sleep(2000);
        cout << "Ile gotowki chcesz wplacic?" << endl;
        cin >> wplata_gotowki;
    }
    *kasa += wplata_gotowki;
    cout << "Zlecenie w trakcie realizacji..." << endl;
    Sleep(5000);
    cout << "Zlecenie zrealizowano pomyslnie." << endl;
    Sleep(2000);
}

void wyplata_z_konta(int & kasa)
{
    cout << "Ile gotowki chcesz pobrac z konta?" << endl;
    int wyplata_gotowki;
    cin >> wyplata_gotowki;
    while(wyplata_gotowki)
    {
        if(wyplata_gotowki > kasa)
        {
            cout << "Za mala ilosc gotowki na koncie!" << endl;
            Sleep(2000);
            cout << "Ile gotowki chcesz pobrac z konta?" << endl;
            cin >> wyplata_gotowki;
        }
        else if(wyplata_gotowki < 0)
        {
            cout << "Niepoprawna ilosc pieniedzy!" << endl;
            Sleep(2000);
            cout << "Ile gotowki chcesz pobrac z konta?" << endl;
            cin >> wyplata_gotowki;
        }
        else if(wyplata_gotowki <= kasa && wyplata_gotowki >= 0)
        {
            break;
        }
    }
    kasa -= wyplata_gotowki;
    cout << "Zlecenie w trakcie realizacji..." << endl;
    Sleep(5000);
    cout << "Zlecenie zrealizowano pomyslnie." << endl;
    Sleep(2000);
}
