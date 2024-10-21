#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Czas.h"
#include "Harmonogram.h"

int main()
{
	srand(time(NULL));
	Harmonogram* h = new Harmonogram;

	int ilosc = 5;
	int x, x1, x2, x3, x4; //do zabezpieczeń
	int s; //do dodawania sekund
	int i = 0;
	int ile, suma;

	Czas laczny_czas; //dop. łączny czas
	Czas zwroc_czas; //do zwróć czas
	Czas suma_czasow; //do sumy czasow

	//wszystkie char do wyborów w konsoli
	char c[10]; //wybór (główny)
	char n[10];
	char n1[10];
	char n2[10];
	char n3[10];
	char n4[10];

	for (i = 0; i < ilosc; i++) //robimy zeby bylo 5 losowych czasow na poczatku programu
	{
		int s = rand() % 60, m = rand() % 60, g = rand() % 24;
		Czas t2(g, m, s);
		h->dodaj(t2);
	}

	/*
	//Działanie konstruktora kopiującego:

	Harmonogram h2 = Harmonogram(*h);
	Czas pom(1, 1, 1);
	h2.dodaj(pom);

	for (i = 0; i < h->rozmiar; i++)
	{
		std::cout << i + 1 << ". ";
		h->tab[i].wyswietlStan();
	}

	for (i = 0; i < h2.rozmiar; i++)
	{
		std::cout << i + 1 << ". ";
		h2.tab[i].wyswietlStan();
	}
	*/
	setlocale(LC_ALL, "");	//do polskich znaków w konsoli
	std::cout << "                                                 WITAMY W HARMONOGRAMIE!";

	do
	{
		std::cout << "\n\nWybierz co chcesz zrobić:\n1. Wyświetl aktualny harmonogram.\n2. Dodaj nowy czas do aktualnego harmonogramu.\n3. Dodaj sekundy do wybranego czasu.\n4. Kopiuj harmonogram z wybraną ilością czasów.\n5. Kopiuj harmonogram z wybraną sumą czasów.\n6. Sumuj wszystkie czasy harmonogramu.\n7. Zwróć wybrany czas z harmonogramu.\n8. Zwróć ilość czasów w harmonogramie.\n9. Zakończ." << std::endl;
		do
		{
			std::cin >> c;

			int m = strlen(c);
			for (i = 0; i < m; i++)
			{
				if (c[i] >= 49 && c[i] <= 57) //przedzial [1;9]
				{
					x = atoi(c);
				}
				else
				{
					x = -1;
					std::cout << "Niepoprawna wartość. Proszę podać liczbę z przedziału od 1 do 9.\n" << std::endl;
				}
			}
		} while (x < 1 || x > 9);

		switch (x)
		{

		case 1:
		{	
			std::cout << "\nWybrano opcję 1. Wyświetlanie harmonogramu.\n";
			std::cout << "Harmonogram: \n";
			for (i = 0; i < ilosc; i++)
			{
				std::cout << i + 1 << ". ";
				h->tab[i].wyswietlStan();
			}
			break;
		}

		case 2:
		{
			std::cout << "\nWybrano opcję 2. Dodawanie nowego czasu.\n";
			std::cout << "W jaki sposób chcesz ustawić czas?\n1. Format sek, min, godz\n2. Format sek, min\n3. Format sek" << std::endl;
			do
			{
				std::cin >> n1;

				int m1 = strlen(n1);
				for (i = 0; i < m1; i++)
				{
					if (n1[i] >= 49 && n1[i] <= 51) //przedzial [1;3]
					{
						x1 = atoi(n1);
					}
					else
					{
						x1 = -1;
						std::cout << "Niepoprawna wartość. Proszę podać liczbę z przedziału od 1 do 3.\n" << std::endl;
					}
				}

			} while (x1 < 0 || x1 > 3);

			if (x1 == 1)
			{
				Czas t1;
				t1.ustawGodzine1();
				h->dodaj(t1);
			}
			else if (x1 == 2)
			{
				Czas t2;
				t2.ustawGodzine2();
				h->dodaj(t2);
			}
			else if (x1 == 3)
			{
				Czas t3;
				t3.ustawGodzine3();
				h->dodaj(t3);
			}
			ilosc++;
			break;
		}

		case 3:
		{
			std::cout << "\nWybrano opcję 3. Edycja wybranego czasu.\n";
			std::cout << "Który czas chcesz edytowac?" << std::endl;
			for (i = 0; i < ilosc; i++)
			{
				std::cout << i + 1 << ". ";
				h->tab[i].wyswietlStan();
			}

			do
			{
				std::cin >> n2;

				int m2 = strlen(n2);
				for (i = 0; i < m2; i++)
				{
					if (n2[i] >= 48 && n2[i] <= 59) //liczby w kodzie ascii
					{
						x2 = atoi(n2);
					}
					else
					{
						x2 = -1;
						std::cout << "Niepoprawna wartość. Proszę podać liczbę z przedziału dodanych czasów.\n" << std::endl;
					}
				}

			} while (x2 < 1 || x2 > ilosc);

			std::cout << std::endl << "Ile sekund chcesz dodać do czasu " << x2 << "?" << std::endl;
			std::cin >> s; 

			h->tab[x2 - 1] += s;
			break;
		}

		case 4:
		{
			std::cout << "\nWybrano opcję 4. Kopia harmonogramu z wybraną ilością czasów.\n";
			std::cout << "Ile czasów chcesz skopiowac? " << std::endl;
			do
			{
				std::cin >> n3;

				int m3 = strlen(n3);
				for (i = 0; i < m3; i++)
				{
					if (n3[i] >= 48 && n3[i] <= 59) //liczby w kodzie ascii
					{
						x3 = atoi(n3);
					}
					else
					{
						x3 = -1;
						std::cout << "Niepoprawna wartość. Proszę podać liczbę z przedziału dodanych czasów.\n" << std::endl;
					}
				}

			} while (x3 < 1 || x3 > ilosc);

			Harmonogram* hKopia = new Harmonogram;
			h->KopiujIlosc(x3, hKopia);
			std::cout << "\nSkopiowany harmonogram:" << std::endl;
			for (int i = 0; i < x3; i++)
			{
				std::cout << i + 1 << ". ";
				hKopia->tab[i].wyswietlStan();
			}
			delete hKopia;
			break;
		}

		case 5:
		{
			std::cout << "\nWybrano opcję 5. Kopia harmonogramu do podanej wartości czasu.\n";
			std::cout << "Ustaw dopuszczalny łączny czas: " << std::endl;
			laczny_czas.ustawGodzine_h();
			Harmonogram* hKopiaT = new Harmonogram;
			h->KopiujIleCzasu(laczny_czas, hKopiaT);
			std::cout << "\nSkopiowany harmonogram: " << std::endl;
			for (int i = 0; i < hKopiaT->ZwrocIlosc(); i++)
			{
				std::cout << i + 1 << ". ";
				hKopiaT->tab[i].wyswietlStan();
			}
		
			delete hKopiaT;
			break;
		}

		case 6:
		{
			std::cout << "\nWybrano opcję 6. Sumowanie wszystkich czasów.\n";
			suma_czasow = h->SumujCzasy(); //sumowanie czasów z harmonogramu
			std::cout << "\nSuma wynosi: " << std::endl;
			suma_czasow.wyswietlStan();
			break;
		}

		case 7:
		{
			std::cout << "\nWybrano opcję 7. Zwrot wybranego czasu.\n";
			std::cout << "Który czas chcesz pokazać?" << std::endl;
			do
			{
				std::cin >> n4;

				int m4 = strlen(n4);
				for (i = 0; i < m4; i++)
				{
					if (n4[i] >= 49 && n4[i] <= 59) //liczby w kodzie ascii [1;9]
					{
						x4 = atoi(n4);
					}
					else
					{
						x4 = -1;
						std::cout << "Niepoprawna wartosc. Prosze podac liczbe z przedzialu dodanych czasow.\n" << std::endl;
					}
				}

			} while (x4 < 0 || x4 > ilosc);

			x4 = x4 - 1; //bo numerowanie w tablicy jest od zera
			zwroc_czas = h->ZwrocCzas(x4);
			zwroc_czas.wyswietlStan();
			break;
		}

		case 8:
		{
			std::cout << "\nWybrano opcję 8. Zwrot ilości czasów w harmonogramie.\n";
			ile = h->ZwrocIlosc();
			std::cout << "Ilość czasów wynosi: " << ile << std::endl;
			break;
		}

		case 9:
		{
			break;
		}

		default:
		{
			std::cout << "Nie było takiej opcji w menu." << std::endl;
			break;
		}
		}
	} while (x != 9);

	delete h;
	return 0;
}