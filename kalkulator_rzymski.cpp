/*
    Autor: Robert Latoszewski
    Data utworzenia: 10.03.2019

    Opis: 
        Kalkulator liczb rzymskich
		Wejscie: znak operacji, dwie liczby rzymskie
		Wyjscie: wynik operacji przedstawiony jako liczba rzymska
*/

#include <iostream>

using namespace std;

char tab_znakow[20];
int zamiana(char tablica[]);
void zamiana_arabskich(int x);


//***********************************************************************
int main()
{
	char operacja;
	while (cin >> operacja >> tab_znakow)
	{

		int a = zamiana(tab_znakow);
		cin >> tab_znakow;
		int b = zamiana(tab_znakow);
		int wynik[2];
		if (operacja == '+')
			wynik[0] = a + b;
		else if (operacja == '-')
			wynik[0] = a - b;
		else if (operacja == '*')
			wynik[0] = a * b;
		else if (operacja == '/')
		{
			wynik[0] = a / b;
			wynik[1] = a % b;
		}
		if (operacja == '/')
		{
			zamiana_arabskich(wynik[0]);
			cout << " ";
			zamiana_arabskich(wynik[1]);
		}
		else
			zamiana_arabskich(wynik[0]);
		cout << endl;
	}
	return 0;
}


//***********************************************************************
//Funkcja zamienia liczby rzymskie na arabskie
int zamiana(char tablica[])
{
	int tab_arabskie[7]{ 1, 5, 10, 50, 100, 500, 1000 };
	char tab_rzymskie[7]{ 'I', 'V', 'X', 'L', 'C', 'D', 'M' };
	struct wartosci_znakow
	{
		int l_arabska;
		char l_rzymska;
	} tab_wartosci[20];
	for (int i = 0; tab_znakow[i] != 0; i++) // uzupelnienie tab_wartosci
	{
		for (int j = 0; j < 7; j++)
			if (tab_znakow[i] == tab_rzymskie[j])
			{
				tab_wartosci[i].l_arabska = tab_arabskie[j];
				tab_wartosci[i].l_rzymska = tab_rzymskie[j];
			}
	}
	int wynik = 0;
	for (int i = 0; tab_znakow[i] != 0; i++)
	{
		if ((tab_wartosci[i].l_arabska < tab_wartosci[i + 1].l_arabska) && (tab_znakow[i + 1] != 0))
		{
			wynik += tab_wartosci[i + 1].l_arabska - tab_wartosci[i].l_arabska;
			++i;
			continue;
		}
		else
		{
			wynik += tab_wartosci[i].l_arabska;
		}
	}
	return wynik;
}

//***********************************************************************
//Funkcja zamienia liczby arabskie na rzymskie
void zamiana_arabskich(int x)
{
	int tab_arabskie[13]{ 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };
	char tab_rzymskie[13][3] = { "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M" };
	int i = 12;
	while (i >= 0)
	{
		if (x >= tab_arabskie[i])
		{
			x -= tab_arabskie[i];
			cout << tab_rzymskie[i];
		}
		else
		{
			--i;
		}
	}
}
