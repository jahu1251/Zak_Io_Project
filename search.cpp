#include<iostream>
#include<list>
#include<algorithm>
#include<map>
#include<vector>
#include<fstream>
#include<string>
using namespace std;

map<string, vector<string>> wyszukiwanie(list<string> pliki) {

    auto koniec = pliki.end();
    map<string, vector<string>> mapa;

    for (auto it = pliki.begin(); it != pliki.end(); ++it) {

        ifstream plik("*it");

            while (!plik.eof()) {

                string linijka;
                getline(plik, linijka);
                string szukany = "#include";
                size_t miejsce = linijka.find(szukany);

                if (miejsce != string::npos){

                    miejsce += szukany.size();
                    string nazwa_pliku = linijka.substr(miejsce);
                    mapa[*it].push_back(nazwa_pliku);

                }
            }
        }

    return mapa;
    }