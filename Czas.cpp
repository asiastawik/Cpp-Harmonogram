#include <iostream>
#include "Czas.h"

Czas::Czas() // konstuktor domyślny - bez argumentów
//lista inicjalizacyjna
	: godzina(NULL)
	, minuta(NULL)
	, sekunda(NULL)
{
	//std::cout << "wywolano konsutuktor\n" << std::endl;
	/*godzina = NULL;
	minuta = NULL;
	sekunda = NULL;*/
}

Czas::Czas(int _godzina, int _minuta, int _sekunda) 
{
	/*_godzina = NULL;
	_minuta = NULL;
	_sekunda = NULL;*/
	godzina = _godzina;
	minuta = _minuta;
	sekunda = _sekunda;
}

Czas::Czas(int _minuta, int _sekunda)
{
	/*_minuta = NULL;
	_sekunda = NULL;*/
	minuta = _minuta;
	sekunda = _sekunda;
}

Czas::Czas(int _sekunda)
{
	//_sekunda = NULL;
	sekunda = _sekunda;
}

/*Czas::~Czas() //destruktor, niszczenie, likwidacja obiektu
{
}*/

int Czas::odczytGodziny()
{
	return godzina;
}

int Czas::odczytMinuty()
{
	return minuta;
}

int Czas::odczytSekundy()
{
	return sekunda;
}

void Czas::ustawGodzine_harmonogram()
{
	int g;
	do
	{
		std::cout << "Podaj godzinę:  ";
		std::cin >> g;

		if (g == -0)
		{
			g = 0; //na wypadek jakby miało się zepsuć
		}

	} while (g < 0);

	godzina = g;
}

void Czas::ustawGodzine()
{
	int g;
	do
	{
		std::cout << "Podaj godzinę:  ";
		std::cin >> g;

		if (g == -0)
		{
			g = 0; //na wypadek jakby miało się zepsuć
		}

		if (g < 0 || g >= 24)
		{
			std::cout << "Podaj wartość z zakresu [0,23]!" << std::endl;
		}

	} while (g < 0 || g >= 24);

	godzina = g;
}

void Czas::ustawMinute()
{
	int m;
	do
	{
		std::cout << "Podaj minutę:  ";
		std::cin >> m;
		if (m == -0)
		{
			m = 0; //na wypadek jakby miało się zepsuć
		}

		if (m < 0)
		{
			std::cout << "Minuty muszą przyjmować wartości dodatnie!" << std::endl;
		}
	} while (m < 0);

	int kg;
	if (m > 59)
	{
		kg = m / 60;
		godzina = godzina + kg;
		m = m % 60; //reszta z dzielenia
	}
	minuta = m;
}

void Czas::ustawSekunde()
{
	int s;
	do
	{
		std::cout << "Podaj sekundę:  ";
		std::cin >> s;
		if (s == -0)
		{
			s = 0; //na wypadek jakby miało się zepsuć
		}

		if (s < 0)
		{
			std::cout << "Sekundy muszą przyjmować wartości dodatnie!" << std::endl;
		}
	}while (s < 0);

	int km;
	if (s > 59)
	{
		km = s / 60;
		minuta = minuta + km;
		s = s % 60; //reszta z dzielenia
	}
	sekunda = s;
}

void Czas::ustawGodzine(int g)
{
	godzina = g;
}

void Czas::ustawMinute(int m)
{
	int kg;
	if (m > 59)
	{
		kg = m / 60;
		godzina = godzina + kg;
		m = m % 60; //reszta z dzielenia
	}
	minuta = m;
}

void Czas::ustawSekunde(int s)
{
	int km;
	if (s > 59)
	{
		km = s / 60;
		minuta = minuta + km;
		s = s % 60; //reszta z dzielenia
	}
	sekunda = s;
}

void Czas::wyswietlStan()
{
	int km = 0; //krotność sekundy
	int kg = 0; //krotność godziny

	int s = odczytSekundy();
	if (s > 59)
	{
		km = s / 60;
		s = s % 60; //reszta z dzielenia
	}

	int m = odczytMinuty() + km;
	if (m > 59)
	{
		kg = m / 60;
		m = m % 60;
	}

	int g = odczytGodziny() + kg;

	if (g < 10)
		std::cout << "Czas: " << 0 << g << ":";
	else
		std::cout << "Czas: " << g << ":";
	if (m < 10)
		std::cout << 0 << m << ":";
	else
		std::cout << m << ":";
	if (s < 10)
		std::cout << 0 << s << std::endl;
	else
		std::cout << s << std::endl;
}

void Czas::ustawGodzine_h()
{
	ustawSekunde();
	ustawMinute();
	ustawGodzine_harmonogram();
}

void Czas::ustawGodzine1()
{
	ustawSekunde();
	ustawMinute();
	ustawGodzine();
}

void Czas::ustawGodzine2()
{
	godzina = NULL;
	ustawSekunde();
	ustawMinute();
}

void Czas::ustawGodzine3()
{
	minuta = NULL;
	godzina = NULL;
	ustawSekunde();
}

Czas Czas::operator+=(int x)  // operator dodawania sekund
{
	ustawSekunde(sekunda + x);
	ustawMinute(minuta); //na wszelki wypadek jezeli bylo by powyzej 60
	ustawGodzine(godzina); //to samo
	return (*this); //dereferencja wskaźnika this zwraca obiekt  (INSTRUKCJA)
					//referencję na ten obiekt zwracamy następnie z funkcji
}

Czas Czas:: operator+(Czas& c)  // operator dodawania dwoch czasow
{
	ustawSekunde(sekunda + c.sekunda);
	ustawMinute(minuta + c.minuta);
	ustawGodzine(godzina + c.godzina);
	return (*this);	//dereferencja wskaźnika this zwraca obiekt  (INSTRUKCJA)
					//referencję na ten obiekt zwracamy następnie z funkcji
}

bool Czas ::operator== (Czas& c)  //operator porownywania czasow; jeśli równe
{
	Czas czas = (*this);
	if (czas.odczytGodziny() == c.odczytGodziny() && czas.odczytMinuty() == c.odczytMinuty() && czas.odczytSekundy() == c.odczytSekundy())
		return true;
	else
		return false;
}

bool Czas ::operator< (Czas& c)  //operator porownywania czasow; jeśli któryś czas jest mniejszy
{
	Czas czas = (*this);
	if (czas == c)
	{
		return false; //żaden nie jest mniejszy, są równe
	}
	else
	{
		if (czas.odczytGodziny() < c.odczytGodziny()) //jeśli jest większy
			return true;
		else if (czas.odczytGodziny() == c.odczytGodziny()) //jeśli godzina jest równa to czas nadal może być inny
		{
			if (czas.odczytMinuty() < c.odczytMinuty()) //minuty
				return true;
			else if (czas.odczytMinuty() == c.odczytMinuty()) //jeśli minuty są równe nadal sekundy mogą być inne
			{
				if (czas.odczytSekundy() < c.odczytSekundy())
					return true;
			}

		}
		return false;
	}
}