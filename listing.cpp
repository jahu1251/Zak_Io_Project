#include <string>
#include <iostream>
#include <filesystem>
#include <list>
#include <map>

    std::map<std::string, int> listing()
    {
        std::map<std::string, int> map_name_size;
        std::string sciezka;
        std::cout << "Podaj sciezke do folderu " << std::endl;
        std::cin >> sciezka;
        for (auto& entry : std::filesystem::directory_iterator(sciezka))
        {
            if (std::filesystem::is_directory(std::filesystem::path(entry)) != 1)
            {
                if (std::filesystem::file_size(entry) < 1024)
                {
                    map_name_size[std::filesystem::path(entry).filename().string()] = 1;
                }
                else
                {
                    map_name_size[std::filesystem::path(entry).filename().string()] = std::filesystem::file_size(entry) / 1024;
                }
            }
        }
        return map_name_size;

    }