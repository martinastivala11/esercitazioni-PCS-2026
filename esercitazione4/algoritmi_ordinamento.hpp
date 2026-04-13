#pragma once

#include <vector>
#include <algorithm>


template<typename T>
void bubble_sort(std::vector<T>& A)
{
	if (A.empty()) {
        return; // Return senza valore perché la funzione è void
    }
	
	for (int i=0; i<A.size()-1; i++)
	{
		for (int j=A.size()-1; j>=i+1; j--)
		{
			if (A[j]<A[j-1])
			{
				std::swap(A[j],A[j-1]);
			}
		}
	}
}
	
	
template<typename T>
void insertion_sort(std::vector<T>& A)
{
	if (A.empty()) {
        return; // Return senza valore perché la funzione è void
    }
	
	for (int j=1 ; j<A.size(); j++)  
	{
		T key=A[j];
		int i=j-1;
		while (i>=0 && A[i]>key)
		{
			A[i+1]=A[i];
			i=i-1;
		}
		A[i+1]=key;
	}
}

template<typename T>
void selection_sort(std::vector<T>& A)
{
	if (A.empty()) {
        return; // Return senza valore perché la funzione è void
    }
	
	for (int i=0; i<A.size()-1; i++)
	{
		int min_index=i;
		for (int j=i+1; j<A.size(); j++)
		{
			if (A[j]<A[min_index])
			{
				min_index=j;
			}
		}
		std::swap(A[i],A[min_index]);
	}
}
				