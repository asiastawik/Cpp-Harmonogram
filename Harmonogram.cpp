#include <iostream>
#include "Harmonogram.h"

void Harmonogram::dodaj(Czas& _c) //dodawanie czasów do harmonogramu
{
	if (tab == nullptr)	//dla pierwszego elementu
	{
		rozmiar++;
		tab = new Czas[rozmiar];
		tab[rozmiar - 1] = _c;
	}

	else
	{	//dla kolejnych elementów, gdy coś mamy już w tablicy
		Czas* pomocnicza;
		pomocnicza = new Czas[rozmiar + 1]; //zwiększamy rozmiar o jeden
		memcpy(pomocnicza, tab, rozmiar * sizeof(Czas));	//kopiujemy całą tablicę do pom
		rozmiar++; //zwiększamy rozmiar
		pomocnicza[rozmiar - 1] = _c; //dla ostatniego rozmiaru "przypisujemy" czas _c
		delete[] tab; //usuwamy dotychczasową tab
		tab = pomocnicza;	//od teraz mamy nową tablicę, z nowym rozmiarem
	}
}

Harmonogram::Harmonogram()
{
	tab = nullptr;
	rozmiar = 0;
}

Harmonogram::Harmonogram(const Harmonogram& other) //konstruktor kopiujący
{
	Czas* pomocnicza; 
	pomocnicza = new Czas[other.rozmiar];
	memcpy(pomocnicza, other.tab, other.rozmiar*sizeof(Czas));
	(*this).tab = pomocnicza;
	(*this).rozmiar = other.rozmiar;
}

Harmonogram::~Harmonogram()
{
	delete[] tab; //destruktor -  musimy usunąć zajętą pamięć
}

Czas Harmonogram::SumujCzasy()
{
	Czas t;
	int i = 0;
	Czas t1;
	t1.Czas::Czas(0, 0, 0);
	while (t1 < (*this).tab[i]) //dopóki istnieje dany czas...
	{
		t = t + tab[i]; //... to go sumujemy wraz z poprzednimi
		i++;
	}
	return t;
}

Czas Harmonogram::ZwrocCzas(int x)
{
	Czas t;
	t = (*this).tab[x]; //zwrot danego czasu x
	return t;
}

int Harmonogram::ZwrocIlosc()
{
	return (*this).rozmiar;
}

void Harmonogram::KopiujIlosc(int n, Harmonogram* hKopia)
{
	for (int i = 0; i < n; i++) //dla każdego i
	{
		hKopia->dodaj((*this).tab[i]); //dodajemy do kopii kolejny element tablicy czasów aż do n (n - podane przez użytkownika)
	}
}

void Harmonogram::KopiujIleCzasu(Czas t, Harmonogram* hKopiaT)
{
	Czas pom;
	pom = pom + (*this).tab[0]; //dodajemy do pomocniczego czasu element zerowy
	//pom.wyswietlStan();
	int i = 0;
	while (pom < t || pom == t) //dopóki pomocniczy jest mniejszy od czasu t (podanego, łącznego) lub stanie się mu idealnie równy
	{
		hKopiaT->dodaj((*this).tab[i]); //dodajemy do kopii kolejny element tablicy czasów
		i++;
		pom = pom + (*this).tab[i]; //dodajemy i w kolejnej pętli sprawdzamy czy nadal jest mniejszy bądź równy
		//pom.wyswietlStan();
	}
}