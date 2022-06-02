#include "Klasy.h"
#include<fstream>

import Teksty;

Seria::Seria()
{
	nazwa_gry = "Niepoprawna nazwa";
	miasto = "Niepoprawne miasto";
	ilosc_gier = 0;
}

template<typename T>
void ZapiszBinarnie(ofstream& stream, const T& wartosc)
{

	stream.write((const char*)&wartosc, sizeof(wartosc));
}



template<class Pomocnicze_zmienne>
Gracz<Pomocnicze_zmienne> przypisywanie(istream& stream, Gracz<Pomocnicze_zmienne>& nowy)
{
	string line;
	getline(stream, line);
	stringstream ss(line);
	ss >> nowy.nazwa;
	ss >> nowy.nazwa2;

	ss >> nowy.punktacja_calkowita.punkty_zycia;
	ss >> nowy.punktacja_calkowita.punkty_wyniku;


	return nowy;
}


Gra::Gra(const string& nazwaPliku) : ilosc_gier(0), nazwa_gry("Niepoprawna nazwa"), miasto("Niepoprawne miasto"), tworca(Uzytkownik())
{
	ifstream binarnystrumien("plik.bin", ios::binary);
	char* temp = new char[sizeof(int)];
	binarnystrumien.read(temp, sizeof(int));
	int* IleP = (int*)(temp);
	ilosc_gier = *IleP;

	ifstream stream(nazwaPliku);
	if (stream.good())
	{
		string line;
		getline(stream, line);
		nazwa_gry = line;
		getline(stream, line);
		miasto = line;
		getline(stream, line);
		stringstream ss3(line);
		ss3 >> tworca.nazwa;
		ss3 >> tworca.nazwa2;
		ss3 >> tworca.Tel;
		getline(stream, line);
		ilosc_gier = atoi(line.c_str());
		for (int i = 0; i < ilosc_gier; i++)
		{
			Gracz<Ogolne_punkty_z_gry> doDodania;
			przypisywanie(stream, doDodania);
			Ranking.nowy_gracz(doDodania);
		}
		stream.close();
	}
}

void Ranking::sortowanie_listya()
{
	cout << "Ranking: " << endl;
	cout << "Nazwa\tPunkty zycia - Punkty wyniku" << endl;
	Elementy_rankingu* tmp = pierwszy;
	Elementy_rankingu* najmlodszy = pierwszy;
	Ranking posortowana;
	tmp = pierwszy->nastepny;

	while (tmp != nullptr)
	{
		if (tmp->MD.punktacja_calkowita.punkty_zycia > najmlodszy->MD.punktacja_calkowita.punkty_zycia)
		{
			najmlodszy = tmp;
		}
		else if (tmp->MD.punktacja_calkowita.punkty_zycia == najmlodszy->MD.punktacja_calkowita.punkty_zycia)
		{
			if (tmp->MD.punktacja_calkowita.punkty_wyniku > najmlodszy->MD.punktacja_calkowita.punkty_wyniku)
			{
				najmlodszy = tmp;
			}
			else if (tmp->MD.punktacja_calkowita.punkty_wyniku == najmlodszy->MD.punktacja_calkowita.punkty_wyniku)
			{

				najmlodszy = tmp;

			}
		}
		tmp = tmp->nastepny;
	}
	posortowana.pierwszy = najmlodszy;
	if (pierwszy == najmlodszy)
	{
		pierwszy = pierwszy->nastepny;
	}
	else
	{
		Elementy_rankingu* tmp = pierwszy;
		while (tmp->nastepny != najmlodszy)
		{
			tmp = tmp->nastepny;
		}
		tmp->nastepny = najmlodszy->nastepny;
	}
	najmlodszy->nastepny = nullptr;

	while (pierwszy != nullptr)
	{

		najmlodszy = pierwszy;
		tmp = pierwszy;
		while (tmp != nullptr)
		{
			if (tmp->MD.punktacja_calkowita.punkty_zycia > najmlodszy->MD.punktacja_calkowita.punkty_zycia)
			{
				najmlodszy = tmp;
			}
			else if (tmp->MD.punktacja_calkowita.punkty_zycia == najmlodszy->MD.punktacja_calkowita.punkty_zycia)
			{
				if (tmp->MD.punktacja_calkowita.punkty_wyniku > najmlodszy->MD.punktacja_calkowita.punkty_wyniku)
				{
					najmlodszy = tmp;
				}
				else if (tmp->MD.punktacja_calkowita.punkty_wyniku == najmlodszy->MD.punktacja_calkowita.punkty_wyniku)
				{

					najmlodszy = tmp;

				}
			}
			tmp = tmp->nastepny;
		}
		tmp = posortowana.pierwszy;
		while (tmp->nastepny)
		{
			tmp = tmp->nastepny;
		}
		tmp->nastepny = najmlodszy;

		if (pierwszy == najmlodszy)
		{
			pierwszy = pierwszy->nastepny;
		}
		else
		{
			Elementy_rankingu* tmp = pierwszy;
			while (tmp->nastepny != najmlodszy)
			{
				tmp = tmp->nastepny;
			}
			tmp->nastepny = najmlodszy->nastepny;
		}
		najmlodszy->nastepny = nullptr;
	}
	*this = posortowana;
}
void Ranking::sortowanie_listyb()
{
	cout << "Ranking: " << endl;
	cout << "Nazwa | \tPunkty zycia - Punkty wyniku" << endl;
	Elementy_rankingu* tmp = pierwszy;
	Elementy_rankingu* najstarszy = pierwszy;
	Ranking posortowana;
	tmp = pierwszy->nastepny;

	while (tmp != nullptr)
	{
		if (tmp->MD.punktacja_calkowita.punkty_zycia < najstarszy->MD.punktacja_calkowita.punkty_zycia)
		{
			najstarszy = tmp;
		}
		else if (tmp->MD.punktacja_calkowita.punkty_zycia == najstarszy->MD.punktacja_calkowita.punkty_zycia)
		{
			if (tmp->MD.punktacja_calkowita.punkty_wyniku < najstarszy->MD.punktacja_calkowita.punkty_wyniku)
			{
				najstarszy = tmp;
			}
			else if (tmp->MD.punktacja_calkowita.punkty_wyniku == najstarszy->MD.punktacja_calkowita.punkty_wyniku)
			{

				najstarszy = tmp;

			}
		}
		tmp = tmp->nastepny;
	}
	posortowana.pierwszy = najstarszy;
	if (pierwszy == najstarszy)
	{
		pierwszy = pierwszy->nastepny;
	}
	else
	{
		Elementy_rankingu* tmp = pierwszy;
		while (tmp->nastepny != najstarszy)
		{
			tmp = tmp->nastepny;
		}
		tmp->nastepny = najstarszy->nastepny;
	}
	najstarszy->nastepny = nullptr;

	while (pierwszy != nullptr)
	{

		najstarszy = pierwszy;
		tmp = pierwszy;
		while (tmp != nullptr)
		{
			if (tmp->MD.punktacja_calkowita.punkty_zycia < najstarszy->MD.punktacja_calkowita.punkty_zycia)
			{
				najstarszy = tmp;
			}
			else if (tmp->MD.punktacja_calkowita.punkty_zycia == najstarszy->MD.punktacja_calkowita.punkty_zycia)
			{
				if (tmp->MD.punktacja_calkowita.punkty_wyniku < najstarszy->MD.punktacja_calkowita.punkty_wyniku)
				{
					najstarszy = tmp;
				}
				else if (tmp->MD.punktacja_calkowita.punkty_wyniku == najstarszy->MD.punktacja_calkowita.punkty_wyniku)
				{

					najstarszy = tmp;

				}
			}
			tmp = tmp->nastepny;
		}
		tmp = posortowana.pierwszy;
		while (tmp->nastepny)
		{
			tmp = tmp->nastepny;
		}
		tmp->nastepny = najstarszy;

		if (pierwszy == najstarszy)
		{
			pierwszy = pierwszy->nastepny;
		}
		else
		{
			Elementy_rankingu* tmp = pierwszy;
			while (tmp->nastepny != najstarszy)
			{
				tmp = tmp->nastepny;
			}
			tmp->nastepny = najstarszy->nastepny;
		}
		najstarszy->nastepny = nullptr;
	}
	*this = posortowana;
}

void Ranking::usuwanie_gracza(Elementy_rankingu* usuwany)
{
	if (pierwszy == usuwany)
	{
		pierwszy = pierwszy->nastepny;
	}
	else
	{
		Elementy_rankingu* tmp = pierwszy;
		while (tmp->nastepny != usuwany)
		{
			tmp = tmp->nastepny;
		}
		tmp->nastepny = usuwany->nastepny;
	}
	delete usuwany;

}




Uzytkownik::Uzytkownik() : nazwa("Imie"), nazwa2("Nazwisko")
{

}

template<class Pomocnicze_zmienne>
Gracz<Pomocnicze_zmienne>::Gracz()
{
	nazwa = "Imie";
	nazwa2 = "Nazwisko";

	punktacja_calkowita.punkty_zycia = 1800;



}

template <>
Gracz<Ogolne_punkty_z_gry>::Gracz(const Gracz& przekazany)
{
	nazwa = przekazany.nazwa;
	nazwa2 = przekazany.nazwa2;

	punktacja_calkowita.punkty_zycia = przekazany.punktacja_calkowita.punkty_zycia;
	punktacja_calkowita.punkty_wyniku = przekazany.punktacja_calkowita.punkty_wyniku;



}

template<>
Gracz<string>::Gracz()
{
	nazwa = "Imie";
	nazwa2 = "Nazwisko";

	punktacja_calkowita.punkty_zycia = 1800;

	Punkty = " ";

}


template<>
Gracz<Ogolne_punkty_z_gry> Gracz<Ogolne_punkty_z_gry>::ustawianie_gracza()
{

	cout << "Prosze podac nazwe gracza" << endl;
	cin >> nazwa;
	cout << "Prosze podac nazwisko gracza (opcjonalnie)" << endl;
	cin >> nazwa2;




	return *this;
}

Ranking::Ranking() : pierwszy(nullptr)
{

}

template<>
Gracz<Ogolne_punkty_z_gry> Gracz<Ogolne_punkty_z_gry>::operator= (const Gracz<Ogolne_punkty_z_gry>& kopiowany)
{
	nazwa = kopiowany.nazwa;
	nazwa2 = kopiowany.nazwa2;
	punktacja_calkowita.punkty_zycia = kopiowany.punktacja_calkowita.punkty_zycia;
	punktacja_calkowita.punkty_wyniku = kopiowany.punktacja_calkowita.punkty_wyniku;



	return *this;
}

Ranking::Ranking(const Ranking& przekazana) : pierwszy(nullptr)
{
	Elementy_rankingu* tmp1 = przekazana.pierwszy;
	Elementy_rankingu* tmp = nullptr;
	auto* nowy1 = new Elementy_rankingu;
	if (pierwszy == nullptr)
	{
		nowy1->MD = tmp1->MD;
		pierwszy = nowy1;
		nowy1->nastepny = nullptr;
		tmp = pierwszy;
	}
	tmp1 = tmp1->nastepny;
	while (tmp1 != nullptr)
	{
		auto* nowy = new Elementy_rankingu;
		nowy->MD = tmp1->MD;
		nowy->nastepny = nullptr;
		nowy->pierwszy = pierwszy;
		tmp->nastepny = nowy;
		tmp = tmp->nastepny;
		tmp1 = tmp1->nastepny;
	}
}

void Ranking::nowy_gracz(Gracz<Ogolne_punkty_z_gry>& przekazany)
{
	auto* nowy = new Elementy_rankingu;
	nowy->MD = przekazany;
	if (pierwszy == nullptr)
	{
		pierwszy = nowy;
		nowy->nastepny = nullptr;
	}
	else
	{
		Elementy_rankingu* tmp = pierwszy;
		while (tmp->nastepny)
		{
			tmp = tmp->nastepny;
		}
		tmp->nastepny = nowy;
		nowy->nastepny = nullptr;
	}
}

void Ranking::wypisywanie_uzytkownikow() const
{
	cout << "....................................................................................................." << endl << endl;
	Elementy_rankingu* tmp1 = pierwszy;
	while (tmp1 != nullptr)
	{
		cout << tmp1->MD.nazwa << " ";
		cout << tmp1->MD.nazwa2 << endl;
		tmp1 = tmp1->nastepny;
	}
	cout << "....................................................................................................." << endl << endl;
}

void Ranking::wypisywanie_od_najslabszego() const
{
	cout << "....................................................................................................." << endl << endl;
	Elementy_rankingu* tmp1 = pierwszy;
	while (tmp1 != nullptr)
	{
		cout << tmp1->MD.nazwa << " ";
		cout << tmp1->MD.nazwa2 << "       ";
		cout << tmp1->MD.punktacja_calkowita.punkty_zycia << "-" << tmp1->MD.punktacja_calkowita.punkty_wyniku << endl;
		tmp1 = tmp1->nastepny;
	}
	cout << "....................................................................................................." << endl << endl;
}
void Ranking::wypisywanie_od_najlepszego() const
{
	cout << "....................................................................................................." << endl << endl;
	Elementy_rankingu* tmp1 = pierwszy;
	while (tmp1 != nullptr)
	{
		cout << tmp1->MD.nazwa << " ";
		cout << tmp1->MD.nazwa2 << "       ";
		cout << tmp1->MD.punktacja_calkowita.punkty_zycia << "-" << tmp1->MD.punktacja_calkowita.punkty_wyniku << endl;
		tmp1 = tmp1->nastepny;
	}
	cout << "....................................................................................................." << endl << endl;
}

Elementy_rankingu::Elementy_rankingu()
{
	pierwszy = nullptr;
	nastepny = nullptr;
	MD = Gracz<Ogolne_punkty_z_gry>();
}

Gra::Gra() : ilosc_gier(2), nazwa_gry("Niepoprawna nazwa"), miasto("Niepoprawne miasto"), tworca(Uzytkownik())
{

}




void Gra::zapis(const string& nazwaPliku) const
{
	ofstream binarnyplik("PACMAN.bin", ios::binary);
	Seria* seria = new Seria;
	seria->ilosc_gier = ilosc_gier;
	seria->nazwa_gry = nazwa_gry;
	seria->miasto = miasto;
	binarnyplik.write((char*)(seria), sizeof(Seria));
	delete seria;

	fstream plik;
	plik.open(nazwaPliku, ios::out);
	if (plik.good())
	{
		plik << nazwa_gry << endl << miasto << endl;
		plik << tworca.nazwa << " " << tworca.nazwa2 << endl;
		plik << ilosc_gier << endl;
		Elementy_rankingu* tmp = Ranking.pierwszy;
		while (tmp != nullptr)
		{

			plik << tmp->MD.nazwa << " " << tmp->MD.nazwa2 << " ";
			plik << tmp->MD.punktacja_calkowita.punkty_zycia << " " << tmp->MD.punktacja_calkowita.punkty_wyniku << " " << endl;


			Elementy_rankingu* doUsuniecia = tmp;
			tmp = tmp->nastepny;
			delete doUsuniecia;
		}
	}
	plik.close();
}

void Gra::szukanie_graczy() const
{
	Elementy_rankingu* ZnalezioneDziecko = nullptr;
	while (ZnalezioneDziecko == nullptr)
	{
		string nazwa, nazwa2;
		cout << "Aby znalezc uzytkownika prosze podac w kolejnosci jego dane, lub wpisac 'powrot' aby wrocic do menu glownego" << endl;

		cout << "Prosze podac imie: ";
		cin >> nazwa;
		if (nazwa == "powrot")
		{
			return;
		}
		cout << "Prosze podac nazwisko: ";
		cin >> nazwa2;
		ZnalezioneDziecko = this->szukanie_graczy(nazwa, nazwa2);


	}
	ZnalezioneDziecko->wypisywanie_graczy();
}

Elementy_rankingu* Gra::szukanie_graczy(const string& przekazaneImie, const string& przekazaneNazwisko) const
{
	Elementy_rankingu* tmp = Ranking.pierwszy;
	while ((tmp->MD.nazwa != przekazaneImie) || (tmp->MD.nazwa2 != przekazaneNazwisko))
	{
		if (tmp->nastepny == nullptr)
		{
			cout << "Szukanego gracza nie ma na liscie" << endl;
			return nullptr;
		}
		tmp = tmp->nastepny;
	}
	return tmp;
}

void Elementy_rankingu::wypisywanie_graczy()
{
	cout << "....................................................................................................." << endl;
	cout << "Znaleziono uzytkownika:" << endl;
	cout << "....................................................................................................." << endl;
	cout << "Imie i nazwisko: " << MD.nazwa << " " << MD.nazwa2 << endl;
	cout << "Punktacja: " << MD.punktacja_calkowita.punkty_zycia << "-" << MD.punktacja_calkowita.punkty_wyniku << endl;

	cout << "....................................................................................................." << endl;
}

Elementy_rankingu* Gra::SzWskDz() const
{
	Elementy_rankingu* ZnalezioneDziecko = nullptr;
	while (ZnalezioneDziecko == nullptr)
	{
		string nazwa, nazwa2;
		cout << "Aby wypisac uzytkownika prosze podac w kolejnosci jego dane, lub wpisac 'powrot' aby wrocic do menu glownego" << endl;
		this->Ranking.wypisywanie_uzytkownikow();
		cout << "Prosze podac imie: ";
		cin >> nazwa;
		if (nazwa == "powrot")
		{
			return nullptr;
		}
		cout << "Prosze podac nazwisko: ";
		cin >> nazwa2;
		ZnalezioneDziecko = this->szukanie_graczy(nazwa, nazwa2);
	}
	ZnalezioneDziecko->wypisywanie_graczy();
	return ZnalezioneDziecko;
}

void Gra::usuwanie_gracza()
{
	Elementy_rankingu* Znalezione1 = nullptr;

	Znalezione1 = SzWskDz();
	if (Znalezione1 != nullptr)
	{
		string WypiszAnuluj;
		cout << "Potwierdzenie wypisu gracza, prosze wpisac 'wypisz' aby kontynuowac, lub 'anuluj' by wrocic do menu glownego" << endl;
		cin >> WypiszAnuluj;
		if (WypiszAnuluj == "wypisz")
		{
			this->Ranking.usuwanie_gracza(Znalezione1);
			this->ilosc_gier--;
			cout << "" << endl;
			cout << "Wypisano gracza" << endl;
			return;
		}
	}
	cout << "Anulowano" << endl;
}




//