#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <string>
#include <algorithm>

#include "timecounter.h"
#include "algoritmi_ordinamento.hpp"
#include "randfiller.h"

int main(void)
{
	randfiller rf;
    timecounter tc; 
	
	for (int i=4; i<=8192; i*=2)
	{
		std::cout << "--------- vettore lungo " << i << " ---------\n";
		
		std::vector<int> v;              // creo il vettore
		v.resize(i);  
		rf.fill(v, -10000, 10000);
		
		std::vector<int> v1 = v;        //lavoro su una copia del vettore inziale senno dopo il primo algoritmo mi rimane il vettore riodinato 
		tc.tic();       //inizia a contare i secondi impiegati dall'algoritmo
		bubble_sort(v1);
		double secs1 = tc.toc(); //finisce di contare il tempo e lo memorizza in secs
		std::cout << "L'algoritmo bubble sort ha impiegato " << secs1 << " secondi\n";
    
		std::vector<int> v2 = v;
		tc.tic();       
		insertion_sort(v2);
		double secs2 = tc.toc(); 
		std::cout << "L'algoritmo insertion sort ha impiegato " << secs2 << " secondi\n";
    
		std::vector<int> v3 = v;
		tc.tic();       
		selection_sort(v3);
		double secs3 = tc.toc(); 
		std::cout << "L'algoritmo selection sort ha impiegato " << secs3 << " secondi\n";
    
		std::vector<int> v4 = v;
        tc.tic();
        std::sort(v4.begin(), v4.end()); 
		double secs4 = tc.toc();
        std::cout << "La funzione sort ha impiegato " << secs4 << " secondi\n\n"; // CORREGGI
	}
	
    return 0;
}

//g++ -std=c++20 -o p measure_sorts.cpp timecounter.cpp