export module Zadaniowe;
import Teksty;

import <iostream>;
import <thread>;
import <filesystem>;
import <regex>;
import <future>;
import <conio.h>;
import <ctime>; 
import <thread>;

using namespace std;
namespace fs = filesystem;





export void kopia_plikow_fs(fs::path _from, fs::path _to) {

    const auto copyOptions = fs::copy_options::update_existing | fs::copy_options::recursive;
    fs::copy(_from, _to, copyOptions);

};



export int pomiar_czasu() {

    time_t pocz, koniec;

    pocz = clock();

    kopia_plikow_fs("C:/Users/Lenovo/Desktop/Project1/Ranking.txt", "C:/Users/Lenovo/Desktop/KOPIATU");

    koniec = clock();

    cout << "Kopiowanie pliku trwalo: " << static_cast <double>(koniec - pocz) / CLOCKS_PER_SEC << " sekund";
    return 0;
};

export int dziewczyny(string tekst)
{

    regex mojReg("\\w*[Aa]\\b");

    int znalezione = 0;
    for (sregex_iterator i = sregex_iterator(tekst.begin(), tekst.end(), mojReg); i != sregex_iterator(); ++i)
    {
        znalezione++;
    }

    return znalezione;

};

export int wybor()
{
    int MenuWybor = 0;

    while ((MenuWybor != 1) && (MenuWybor != 2) && (MenuWybor != 3) && (MenuWybor != 4))
    {
        wybory();
        infokoncowe();
        cin >> MenuWybor;
    }
    if (MenuWybor == 1) return 1;
    else if (MenuWybor == 2) return 2;
    else if (MenuWybor == 3) return 3;
    else if (MenuWybor == 4) return 4;

    else return 0;
};