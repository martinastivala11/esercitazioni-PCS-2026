#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <iterator>
#include "graphs.hpp"


int main() 
{
    unidirected_graph<int> g1, g2;
    
    g1.add_edge(1, 2);
    g1.add_edge(2, 3);
	g1.add_edge(3, 8);
	g1.add_edge(8, 4);
	g1.add_edge(3, 1);
	
    
    g2.add_edge(1, 3);
	g2.add_edge(1, 2);
	g2.add_edge(2, 3);
	g2.add_edge(2, 4);

	std::set<int> nodi = g1.all_nodes();
	for (const auto& nodo : nodi) 
	{
		std::set<int> vicini = g1.neighbours(nodo);
        std::cout << "i vicini del nodo " << nodo << " sono: ";
		for (int v : vicini) 
		{
			std::cout << v << " ";
		}
        std::cout << "\n";
    }
	
	std::set<unidirected_edge<int>> archi = g1.all_edges();
	std::cout<< "gli archi sono: ";
	for (const auto& arco : archi) 
	{
        std::cout << arco << " "; 
    }
	std::cout << std::endl;
	
	std::cout<< "i nodi sono: ";
    std::set<int> nodes = g1.all_nodes();
    for (const auto& nodo : nodes) 
	{
        std::cout << nodo << " "; 
    }
    std::cout << std::endl;
	
	std::cout<< "l'arco "<< unidirected_edge<int>(1,2)<< " si trova in posizione: "<< g1.edge_number(unidirected_edge(1,2))<< "\n";

    std::cout<< "l'arco in posizione 2 è: "<< g1.edge_at(2)<< "\n";
	std::cout<< "l'arco in posizione 6 è: "<< g1.edge_at(6)<< "\n";
	
    unidirected_graph<int> differenza = g1 - g2;
	auto archi_d=differenza.all_edges();
    std::cout << "gli archi rimanenti dalla differenza sono: "; 
	for (const auto& arco : archi_d)
	{
		std::cout << arco <<" ";
	}
	std::cout << std::endl;
	
    return 0;
}