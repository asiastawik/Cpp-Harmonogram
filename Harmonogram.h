#pragma once
#include "Czas.h"

class Harmonogram
{
public:
	Harmonogram();  //konstruktor
	Harmonogram(const Harmonogram& other);
	~Harmonogram();  //desturktor
	
	Czas SumujCzasy(); //sumowanie wszystkich czasów z harmonogramu
	Czas ZwrocCzas(int x); //zwrócenie danego czasu
	int ZwrocIlosc(); //zwrócenie ilości czasów

	void KopiujIlosc(int n, Harmonogram* hKopia); //kopiowanie harmonogramu do danej ilości czasów
	void KopiujIleCzasu(Czas t, Harmonogram* hKopiaT); //kopiowanie harmonogramu do podanej łącznej puli czasów
	void dodaj(Czas& _c); //dodawanie czasów do harmonogramu

	Czas* tab; //deklarowanie pamięci dynamicznej
	int rozmiar;
};