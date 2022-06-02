#pragma once
#pragma once
#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <list>
#include <fstream>
#include <vector>
#include <utility> 
#include <memory>
#include <cstdio>
#include <cstdlib>

using namespace std;


class Uzytkownik
{
public:
	string nazwa;
	string nazwa2;
	string Tel;
	Uzytkownik();
};

class Punktacja
{
public:

	int punkty_wyniku;
	int punkty_zycia;
};

class Ogolne_punkty_z_gry
{
public:
	string punkt_zycia_ogolny;
	string punkt_wyniku_ogolny;
};


template<typename T> class Gracz : public Uzytkownik
{
public:
	Punktacja punktacja_calkowita;

	T Punkty;

	Gracz();
	Gracz(const Gracz&);
	Gracz ustawianie_gracza();
	Gracz<Ogolne_punkty_z_gry> przypisywanie(istream&, Gracz<Ogolne_punkty_z_gry>&);
	Gracz operator= (const Gracz&);
};

class Elementy_rankingu
{
public:
	Gracz<Ogolne_punkty_z_gry> MD;
	Elementy_rankingu* nastepny;
	Elementy_rankingu* pierwszy;
	Elementy_rankingu();
	void wypisywanie_graczy();
};

class Ranking
{
public:
	Elementy_rankingu* pierwszy;
	Ranking();
	Ranking(const Ranking&);
	void nowy_gracz(Gracz<Ogolne_punkty_z_gry>&);
	void usuwanie_gracza(Elementy_rankingu*);
	void wypisywanie_uzytkownikow() const;
	void sortowanie_listya();
	void sortowanie_listyb();
	void wypisywanie_od_najslabszego() const;
	void wypisywanie_od_najlepszego() const;
};

class Gra
{
public:
	string nazwa_gry;
	string miasto;
	int ilosc_gier;
	Ranking Ranking;
	Uzytkownik tworca;
	Gra();
	Gra(const string&);
	void usuwanie_gracza();
	void zapis(const string&) const;
	void szukanie_graczy() const;
	Elementy_rankingu* SzWskDz() const;
	Elementy_rankingu* szukanie_graczy(const string&, const string&) const;

};

class Seria
{
public:
	string nazwa_gry;
	string miasto;
	int ilosc_gier;
	Seria();
};

int wybor();



void pomoc();


template<typename T>
void ZapiszBinarnie(ofstream& stream, const T& wartosc);
