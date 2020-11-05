#include <string>
#include <iostream>
#include <filesystem>
#include <list>
#include <map>
#include <algorithm>
#include <vector>
#include <fstream>

std::map<std::string, std::vector<std::string>> wyszukiwanie(std::list<std::string> pliki)
{

    auto koniec = pliki.end();
    std::map<std::string, std::vector<std::string>> mapa;

    for (auto it = pliki.begin(); it != pliki.end(); ++it)
    {

        std::ifstream plik(*it);

        while (!plik.eof())
        {

            std::string linijka;
            getline(plik, linijka);
            std::string szukany = "namespace";
            size_t miejsce = linijka.find(szukany);

            if (miejsce != std::string::npos)
            {

                miejsce += szukany.size();
                std::string nazwa_pliku = linijka.substr(miejsce);
                mapa[*it].push_back(nazwa_pliku);
            }
        }
    }

    return mapa;
}