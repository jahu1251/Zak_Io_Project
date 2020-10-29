#include<iostream>
#include<list>
#include<map>
#include<vector>
#include<fstream>
#include<string>
#include<regex>
#include<sstream>
#include<conio.h>

std::map<std::string, std::vector<std::string>> wyszukiwanie2(std::list<std::string> pliki) {
    auto koniec = pliki.end();
    std::map<std::string, std::vector<std::string>> mapa2;

    for (auto it = pliki.begin(); it != pliki.end(); ++it) {

        std::cout << "Wywolanie funkcji dla " << *it << std::endl;
        
       // std::ifstream plik(*it);

        std::regex wzorzec( "(?<!\\.|\\:)\\b\\w+[A-Za-z0-9_]+(?=\\()" );
        std::ifstream inf;
        inf.open( *it );
    
        int lineo = 0;
        std::string line;
        while( std::getline( inf, line ) )
        {
            ++lineo;
            std::smatch wynik;
            if( std::regex_search( line, wynik, wzorzec ) )
            {
                std::cout << "Wiersz " << lineo << " : " << line;
                for( int i; i < wynik.size(); ++i )
                    std::cout << "\tpasuje.[" << i << "]: " << wynik[ i ] << std::endl;
            
            }
            else
                std::cout << "nie pasuje.\n";
        
        }

    }

    return mapa2;
}