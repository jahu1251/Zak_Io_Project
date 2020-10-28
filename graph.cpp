#include<iostream>
#include<map>
#include<list>
#include"search.cpp"

class Graph
{
    //struktura przyjmujaca dane z search
    std::map<std::string,std::list<std::string>>l;
    std::string pod = "digraph G {\n";
    std::string end = "}";

    public:

        Graph(std::list<std::string> Files)
        {
             
            //selekcja plikow #include
            std::map<std::string, std::vector<std::string>> l;
            l= wyszukiwanie(Files);

            for(auto i=l.begin() ; i!=l.end();++i)
            {
                if(i->first !="a.out")
                {
                    for(auto j=i->second.begin() ; j != i->second.end();++j)
                    {
                        std::cout<<"\""+i->first+"\""<<" <-";

                        std::cout<<*j<<" ";
                    }

                }
               
               std::cout<<std::endl;
            }


                Save_In_File(l);


        };

        void Save_In_File(std::map<std::string, std::vector<std::string>>  x)
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
                        save<<*j<<"->"<<"\""+i->first+"\""<<std::endl;
                    }


                }
            }
             save<<end;
            
            
            std::string command = "dot -Tpng -O";


            system((command + name).c_str());

        }

     


};
