#include<iostream>
#include<list>
#include<algorithm>
#include<map>
#include<vector>
#include<fstream>
#include<string>

std::map<std::string, std::vector<std::pair<std::string,int>>> wyszukiwanie(std::map<std::string, int> pliki) {

    //auto koniec = pliki.end();
    std::map<std::string, std::vector<std::pair<std::string,int>>>  mapa;
    for (auto it = pliki.begin(); it != pliki.end(); ++it) 
  {

    std::ifstream plik(it->first);
    while(!plik.eof())
    {
        std::string linijka;
        getline(plik, linijka);
        std::string szukany = "#include\"";
        size_t miejsce = linijka.find(szukany);

        if (miejsce != std::string::npos)
            {
              miejsce += szukany.size();
              std::string nazwa_pliku = linijka.substr(miejsce);
              mapa[it->first].push_back(std::make_pair(nazwa_pliku,it->second));                         
            }

    }
     
  }
/*
    for (auto it = pliki.begin(); it != pliki.end(); ++it) {

        std::ifstream plik(*it);

            while (!plik.eof()) {

                std::string linijka;
                getline(plik, linijka);
                std::string szukany = "#include\"";
                size_t miejsce = linijka.find(szukany);

                if (miejsce != std::string::npos){

                    miejsce += szukany.size();
                    std::string nazwa_pliku = linijka.substr(miejsce);
                    mapa[*it].push_back(nazwa_pliku);

                }
            }
        }
*/
    return mapa;
    
    }
