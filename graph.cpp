#include<iostream>
#include<map>
#include<list>
#include"search.cpp"
#include<string> 

//std::string s = std::to_string(42);

class Graph
{
    //struktura przyjmujaca dane z search
    std::map<std::string, std::vector<std::pair<std::string,int>>> l;
    std::string pod = "digraph G {\n";
    std::string end = "}";

    public:

        Graph(std::map<std::string, int> Files)
        {
             
            //selekcja plikow #include
            std::map<std::string, std::vector<std::pair<std::string,int>>>  l;
            l= wyszukiwanie(Files);       
               Save_In_File(l);


        };

        void Save_In_File(std::map<std::string, std::vector<std::pair<std::string,int>>> x)
        {
            std::string name = " graf.dot";
            std::ofstream save(name);
            save<<pod;

            
            for(auto i = x.begin() ; i != x.end() ; ++i)
            {
                if(i->first != "a.out")
                {
                    //tworzenie pliku
                    for(auto j=i->second.begin(); j!=i->second.end() ; ++j)
                    {



                        save<<"\""+j->first<<"->"<<"\""+i->first+"\""<<std::endl;
                    }


                }
            }
             save<<end;
            
            
            std::string command = "dot -Tpng -O";

            system((command + name).c_str());

        }

     


};
