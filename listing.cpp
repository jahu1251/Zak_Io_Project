#include <string>
#include <iostream>
#include <filesystem>
#include <list>

std::list<std::string> listing()
{
    std::list<std::string> abc;
    std::string sciezka;
    std::cout << "Podaj sciezke do folderu " << std::endl;
    std::cin >> sciezka;
    for (auto &entry : std::filesystem::directory_iterator(sciezka))
    {
        if(std::filesystem::is_directory(std::filesystem::path(entry))!= 1)
        {
            abc.push_back(std::filesystem::path(entry).filename().string());
        }
    }
    return abc;
}

