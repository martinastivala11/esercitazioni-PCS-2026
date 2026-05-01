#pragma once

#include <vector>
#include <algorithm>
#include <limits>


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
		
template<typename T>
void merge(std::vector<T>& A, int p, int q, int r)    // p inzio, q centro, r fine a dx
{
	if (A.empty()) {
        return; // Return senza valore perché la funzione è void
    }
	int n1=q-p+1;
	int n2=r-q;
	std::vector<T> L(n1+1), R(n2+1);
	for (int i=0; i<n1; i++)
	{
		L[i]=A[p+i];  
	}
	for (int j=0; j<n2; j++)
	{
		R[j]=A[q+j+1];
	}
	
    if constexpr (std::numeric_limits<T>::has_infinity) {
        L[n1] = std::numeric_limits<T>::infinity();
        R[n2] = std::numeric_limits<T>::infinity();
    } else 
	{
        // Per tipi come std::string, usiamo un valore molto alto o logica differente
    }
	
	int i=0;
	int j=0;
	for (int k=p; k<=r; k++)
	{
		if (i < n1 && (j == n2 || L[i] <= R[j]))
		{
			A[k]=L[i];
			i=i+1;
		}
		else
		{
			A[k]=R[j];
			j=j+1;
		}
	}
}

template <typename T>
void merge_sort(std::vector<T>& A, int p, int r) 
{
    if (p < r) 
	{
        int q = (p + r) / 2;
        merge_sort(A, p, q);
        merge_sort(A, q + 1, r);
        merge(A, p, q, r);
    }
}


template<typename T>
int partition(std::vector<T>& A, int p, int r)
{
	T x=A[r];
	int i=p-1;            
	for (int j=p; j<r;j++)  
	{
		if (A[j]<=x)
		{
			i=i+1;
			std::swap(A[i],A[j]);
		}
	}
	std::swap(A[i+1],A[r]);
	return i+1;     
}		

template<typename T>
void quick_sort(std::vector<T>& A, int p, int r)
{
	if (A.empty()) {
        return; // Return senza valore perché la funzione è void
    }
	
	if (p<r)
	{
		int q=partition(A,p,r);
		quick_sort(A,p,q-1);
		quick_sort(A,q+1,r);
	}
}		

template <typename T>
void quick_sort_modificato(std::vector<T>& A, int p, int r) 
{
	if (A.empty()) 
	{
        	return; 
    	}

    	if (p < r) 
	{
        	if ((r - p) < 60) 
		{ 
	            	insertion_sort(A);  // se il vettore è piccolo utilizzo l'algoritmo 						//quadratico più veloce
        	} 
		else 	
		{
            		int q = partition(A,p,r);
            		quick_sort_modificato(A,p,q-1);
            		quick_sort_modificato(A,q+1,r);
        	}
    	}
}
