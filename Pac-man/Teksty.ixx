export module Teksty;
import <iostream>;

using namespace std;

export void pomoc()
{
	cout << "....................................................................................................." << endl << endl;
	cout << "Pomoc:" << endl << endl;
	cout << "....................................................................................................." << endl << endl;
	
	cout << "Aby go uruchomic program nalezy podac odpowiednie parametry:" << endl;
	cout << "1) Jako wejsciowy = flage -wej oraz plik Ranking.txt" << endl;
	cout << "2) Jako wyjsciowy = flage -wyj oraz plik o dowolnej nazwie np. Wynik.txt" << endl << endl;
	cout << "....................................................................................................." << endl;
};

export void wybory()
{
	cout << "Prosze wybrac opcje :" << endl;
	cout << "1. Rozpoczecie gry" << endl;
	cout << "2. Podglad rankingu" << endl;
	cout << "3. Wyszukiwanie graczy w rankingu, usuwanie" << endl;
	cout << "4. Wyjscie" << endl << endl;
	cout << "....................................................................................................." << endl << endl;


};

export void instrukcja()
{
	cout << "Aby wygrac gre nalezy zebrac minimum 7 kropek i wejsc do portalu" << endl;
	cout << "Gracz posiada poczatkowo 3 punkty zycia, po ich utracie przegrywa gre" << endl;
	cout << "Poruszanie: w a s d oraz spacja" << endl;

};

export void infokoncowe()
{
	cout << "....................................................................................................." << endl << endl;
	cout << "Po kliknieciu opcji 4 - 'Wyjscie' aktualny ranking skopiuje sie do innego folderu" << endl;
	cout << "oraz zostanie pokazana ilosc dziewczyn, ktore sa w nim zapisane" << endl;
	cout << "....................................................................................................." << endl << endl;


};

