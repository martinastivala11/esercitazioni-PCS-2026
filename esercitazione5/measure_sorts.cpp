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
	
	const int n_vet = 100;

	std::vector<int> vdim;   //creo vdim, con 100 elementi ognuno con numero casuale che sarà poi la dimensione del corrispettivo vettore i-esimo (0<i<100)
    vdim.resize(100);          //100 vettori
    rf.fill(vdim, 1, 100);  //dimensioni vettori da 1 a 100
	
	std::vector<std::vector<int>> v(n_vet);
	
	for (int i=0; i<n_vet; i++)
	{
		v[i].resize(vdim[i]);   //creo vettore di dimensione casuale (dimensione=numero elemento i-esimo)
		rf.fill(v[i], -10000, 10000); //riempio il vettore con elementi negativi e positivi
    }
	
	
	std::vector<std::vector<int>> v1 = v;
    std::vector<std::vector<int>> v2 = v;
    std::vector<std::vector<int>> v3 = v;
    std::vector<std::vector<int>> v4 = v;
    std::vector<std::vector<int>> v5 = v;
    std::vector<std::vector<int>> v6 = v;
    std::vector<std::vector<int>> v7 = v;	
	
	tc.tic();     //inizia a contare i secondi impiegati dall'algoritmo
	for (int j=0; j<n_vet; j++)
	{
		bubble_sort(v1[j]);
	}
	double secs1 = tc.toc(); //finisce di contare il tempo e lo memorizza in secs
	std::cout <<"tempo medio bubblesort: " << secs1/n_vet << "secondi \n";
    
	tc.tic();     
	for (int j=0; j<n_vet; j++)
	{
		insertion_sort(v2[j]);
	}
	double secs2 = tc.toc(); 
	std::cout <<"tempo medio insertionsort: " << secs2/n_vet << "secondi \n";
    
	tc.tic();     
	for (int j=0; j<n_vet; j++)
	{
		selection_sort(v3[j]);
	}
	double secs3 = tc.toc(); 
	std::cout <<"tempo medio selectionsort: " << secs3/n_vet << "secondi \n";
    
	tc.tic();     
	for (int j=0; j<n_vet; j++)
	{
		merge_sort(v4[j],0,v4[j].size()-1);
	}
	double secs4 = tc.toc(); 
	std::cout <<"tempo medio mergesort: " << secs4/n_vet << "secondi \n";
    
	tc.tic();     
	for (int j=0; j<n_vet; j++)
	{
		quick_sort(v5[j],0,v5[j].size()-1);
	}
	double secs5 = tc.toc(); 
	std::cout <<"tempo medio quicksort: " << secs5/n_vet << "secondi \n";
    
	tc.tic();     
	for (int j=0; j<n_vet; j++)
	{
		std::sort(v6[j].begin(), v6[j].end());
	}
	double secs6 = tc.toc(); 
	std::cout <<"tempo medio std::sort: " << secs6/n_vet << "secondi \n";
	
	tc.tic();     
	for (int j=0; j<n_vet; j++)
	{
		quick_sort_modificato(v7[j],0,v7[j].size()-1);
	}
	double secs7 = tc.toc(); 
	std::cout <<"tempo medio quicksort modificato: " << secs7/n_vet << "secondi \n";
    
    return 0;
}