#pragma once

class Czas
{
public:
	Czas();  //konstruktor
	//~Czas();  //desturktor
	Czas(int _godzina, int _minuta, int _sekunda);
	Czas(int _minuta, int _sekunda);
	Czas(int _sekunda);
	int godzina;
	int minuta;
	int sekunda;

	void ustawGodzine();  //funkcja do ustawiania godziny 
	void ustawMinute();   //minuty
	void ustawSekunde();   //sekundy
	void ustawGodzine_harmonogram(); //do ustawiania godziny bez ograniczeń do 24h
	
	void ustawGodzine(int g);  //funkcja do ustawiania godziny gdy mamy już jakąś wartość
	void ustawMinute(int m);   //minuty
	void ustawSekunde(int s);   //sekundy

	int odczytGodziny();  //funkcja do odczytywania godziny
	int odczytMinuty();    //minuty
	int odczytSekundy();   //sekundy

	void wyswietlStan();		//funkcja do wyswietlania czasu 
	void ustawGodzine1();	    //ustawiania czasu
	void ustawGodzine2();	    //ustawiania czasu
	void ustawGodzine3();	    //ustawiania czasu
	void ustawGodzine_h();		//do harmonogramu

	Czas operator+ (Czas& c); //dodawanie czasów
	Czas operator+= (int x); //dodawanie sekund do czasu

	bool operator== (Czas& c); //porownywanie dwoch czasow
	bool operator< (Czas& c); //porownywanie dwoch czasow

};