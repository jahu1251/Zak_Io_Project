#include<iostream>
#include<list>
#include<map>
#include<vector>
#include<fstream>
#include<string>
#include<regex>
#include<sstream>
#include<conio.h>

int _tmain(int argc, _TCHAR* argv[]){
std::ifstream htmlText;
std::string line;
std::string eduEmail = "(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+";

int testNum = 0;

std::list<std::string> l;


htmlText.open("ltudirectory.txt");
if (htmlText.good()){
    while (getline(htmlText, line)){
        std::regex e(eduEmail); // the pattern
        bool match = regex_search(line, e);
        if (match) {
          ++testNum;
       }
    }
}

htmlText.close();

system("pause");
return 0;
}
/*
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
*/