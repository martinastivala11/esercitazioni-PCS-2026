#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdlib>

#include "timecounter.h"
#include "algoritmi_ordinamento.hpp"
#include "is_sorted.hpp"
#include "randfiller.h"


template<typename T>
void
print_vector(const std::vector<T>& v)
{
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << "\n";
}

int main()
{
	randfiller rf;
    
	std::vector<int> vdim;   //creo vdim, con 100 elementi ognuno con numero casuale che sarà poi la dimensione del corrispettivo vettore i-esimo (0<i<100)
    vdim.resize(100);          //100 vettori
    rf.fill(vdim, 0, 1000);    //dimensioni vettori da 0 a 1000
	       
		
	for (int i=0; i<100; i++)
	{
		std::vector<int> vi;
		vi.resize(vdim[i]);   //creo vettore di dimensione casuale (dimensione=numero elemento i-esimo)
		rf.fill(vi, -10000, 10000); //riempio il vettore con elementi negativi e positivi
    
		merge_sort(vi,0,vi.size()-1);
		if (!is_sorted(vi))
		{
			std::cerr << "test di ordinamento fallito" << std::endl;
			return EXIT_FAILURE;
		}
			
	
		std::vector<float> vf;
		vf.resize(vdim[i]);          
		rf.fill(vf, -10000.0f, 10000.0f);
		
		merge_sort(vf,0,vf.size()-1);
		if (!is_sorted(vf))
		{
			std::cerr << "test di ordinamento fallito" << std::endl;
			return EXIT_FAILURE;
		}
	
	
		std::vector<double> vd;
		vd.resize(vdim[i]);
		rf.fill(vd, -10000.0, 10000.0);
		
		merge_sort(vd,0,vd.size()-1);
		if (!is_sorted(vd))
		{
			std::cerr << "test di ordinamento fallito" << std::endl;
			return EXIT_FAILURE;
		}

	}

	std::vector<std::string> vs = {"maria", "luigi", "francesca", "giuseppe", "Maria", "Francesco", "alice", "eleonora", "filippo", "Gaia"};
	merge_sort(vs,0,vs.size()-1);
    if (!is_sorted(vs)) 
	{
		std::cerr << "test di ordinamento fallito" << std::endl;
		return EXIT_FAILURE;
	}
	print_vector(vs);
	
	std::cerr << "test di ordinamento riuscito" << std::endl;
	return EXIT_SUCCESS;
	
}
	


