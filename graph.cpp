#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "search.cpp"
#include <stdexcept>
#include <string>

class Graph
{

    public:

        Graph(std::map<std::string, int> Files)
        {
             
            //selekcja plikow #include
            std::map<std::string, std::vector<std::pair<std::string,int>>>  l;
            l= wyszukiwanie(Files);       
            Save_In_File(l);


        };

        void Save_In_File(std::map<std::string, std::vector<std::pair<std::string,int>>> l)
        {

            std::string name = "graf.dot";
            std::ofstream file(name);
            file << "digraph files_graph\n{\n";
            for (auto i = l.begin(); i != l.end(); ++i) 
            {
                if(i->first != "a.out")
                {
                    for(auto j=i->second.begin(); j!=i->second.end() ; ++j)
                    {

                        file << '"' << j->first<< "->" << '"'<<i->first   << '"' << "[label = 1]"<< "\n";


                    }
                 }
            }

                file << "}";
                file.close();
                std::string word = "dot -Tpng -O graf.dot";
                int n = word.length();
                char array[n+1];
                strcpy(array , word.c_str());


            exec(array);
        }




        std::string exec(const char* cmd) 
        {
            char buffer[128];
            std::string result = "";
            FILE* pipe = popen(cmd, "r");
            if (!pipe) throw std::runtime_error("popen() failed!");
            try {
                while (fgets(buffer, sizeof buffer, pipe) != NULL) 
                {
                    result += buffer;
                }
                } catch (...) {
                    pclose(pipe);
                    throw;
                }
            pclose(pipe);
            return result;
        }


};