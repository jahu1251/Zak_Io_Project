#include<iostream>
#include<map>
#include<list>
#include"search.cpp"
class Graph
{
    std::map<std::string,std::list<std::string>>l;
    std::map<std::string,std::list<std::string>>z;

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
                    std::cout<<i->first<<" <-";
                    for(auto j=i->second.begin() ; j != i->second.end();++j)
                    {
                    std::cout<<*j<<" ";
                    }

                }
               
               std::cout<<std::endl;
            }


        };

        void addEdge(std::string x,std::string y)
        {
            z[x].push_back(y);
            z[y].push_back(x);
        }

        void printAdj()
        {
            for(auto i=z.begin() ; i!=z.end();++i)
            {
                std::cout<<i->first<<": ";
                for(auto j=i->second.begin() ; j != i->second.end();++j)
                {
                    std::cout<<*j<<" ";
                }
               std::cout<<std::endl;
            }
        }
};
